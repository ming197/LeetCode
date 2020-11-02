# 回溯算法

回溯法是一种暴力（枚举）搜索算法，主要是在搜索尝试过程中寻找问题的解，当发现已**不满足求解条件**时，就**“回溯”**返回，尝试别的路径。回溯算法的基本思想是：从一条路往前走，能进则进，不能进则退回来，换一条路再试。

+ 枚举所有的可行解， 枚举寻找可行解的过程一般用递归实现

+ 到达某一步发现不能获得可行解，则回退至上一步

## 排列枚举问题

### [N皇后](https://leetcode-cn.com/problems/n-queens/)

由于每一排只能放置一个皇后，则每排皇后的列号组成一个 1 到 n 的排列。该问题则转化为一个排列枚举问题， 时间复杂度为 $ O(n!)$。

+ 枚举所有可行解：对于 queen[i] （皇后 i 的列号）的取值， 从 1 到 n 枚举；同时需要满足解的条件：与其他的皇后不在同一列；与其他皇后不在同一对角线上（利用set,记录出现过的列和对角线）

+ 回溯：若不满足条件，此路径不通，返回至上一步；若满足条件，继续向下搜索（深搜）。

  ``` c++
void backtrack(vector<int>& queens, int n, int row){
      // 	递归边界，若找到可行解，将该搜索路径加入解集
  	if(row == n){
       	vector<string> board = generateBoard(queens, n);
	        ans.push_back(board);
  	}else{
  		for(int i = 0; i < n; i++){	// 枚举每个皇后列的取值
            	// 判断每个解是否满足条件
	            // 若不满足，直接跳过该条搜索路径
  			if(columns.find(i) != columns.end()) continue;
	            int diagonal1 = row - i;
  			if(diagonals1.find(diagonal1) != diagonals1.end()) continue;
				int diagonal2 = row + i;
  			if(diagonals2.find(diagonal2) != diagonals2.end()) continue;
	            // 若满足条件，将该分支加入搜索路径
  			queens[row] = i; 
				columns.insert(i);
  			diagonals1.insert(diagonal1);
  			diagonals2.insert(diagonal2);
            	// 沿着该分支继续深搜
  			backtrack(ans, queens, n, row + 1, columns, diagonals1, diagonals2);
            	// 若沿着该分支找到可行解，或者此路径不通，则将此搜索路径上的该点删除，返回上一个决策点
				queens[row] = -1;
  			columns.erase(i);
				diagonals1.erase(diagonal1);
  			diagonals2.erase(diagonal2);
			} // for
  	}// else
}// backtrtack
  
  ```

### [电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)

每个数字对应多个字母，枚举字母的**排列组合**情况即可。

### [括号生成](https://leetcode-cn.com/problems/generate-parentheses/)

枚举所有解的情况，即左括号和又括号的全排列。同时加入限制条件，当前搜索路径的左括号数量大于等于右括号的数量。

``` c++
    void backtrack(string& temp, int l, int r, int& n){
        // 递归边界，找到可行解，将搜索路径加入解集
        if(temp.size() == 2 * n){
            ans.emplace_back(temp);
            return;
        }
        // 枚举当前节点的所有情况
        // 左括号的数量小于 n 时，可不断加入 "("
        if(l < n){
            temp.push_back('(');
            backtrack(temp, l + 1, r, n);
            temp.pop_back();
        }
        // 右括号的数量小于左括号的数量时，才可加入 ")"
        if(r < l){
            temp.push_back(')');
            backtrack(temp, l, r + 1, n);
            temp.pop_back();
        }
    }
```

## 可行解问题

对于这类寻找所有可行解的题，我们都可以尝试用「搜索回溯」的方法来解决。

### [组合总和](https://leetcode-cn.com/problems/combination-sum/)

定义递归函数 backtrack(sum, pos)，其中 sum为当前路径的节点总和，pos 表示该节点在待选序列中的位置。

``` c++
	void backtrack(vector<int>& candidates, int& target, vector<vector<int>>& ans, vector<int>& temp, int sum, int pos){
        // 递归边界
        // 找到可行解
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        // 超出总和， 该搜索路径失败
        if(sum > target) return;
        // 枚举所有的搜索路径
        for(int i = pos; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            backtrack(candidates, target, ans, temp, sum + candidates[i], i);
            // 回溯：找到可行解，或者路径不通
            temp.pop_back();
        }
    }
```

### [组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/)

相比于[组合总和](https://leetcode-cn.com/problems/combination-sum/)，该题数组中的元素有重复，且每个元素只能使用一次，需要解决重复解的问题。对应搜索树中的剪枝操作。对于重复解的问题，首先将元素排序便于后续处理；利用 freq 记录**不同元素出现的频次**；通过枚举各个元素出现的次数，解决重复解的问题。

``` c++
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<pair<int, int>> freq;
        sort(candidates.begin(), candidates.end());
        for(auto num : candidates){
            if(freq.empty() || freq.back().first != num){
                freq.emplace_back(num, 1);
            }else{
                freq.back().second++;
            }
        }
        dfs(candidates, target, 0, ans, temp, freq);
        return ans;
    }
    void dfs(vector<int>& candidates, int rest, int pos, vector<vector<int>>& ans, vector<int>& temp, vector<pair<int, int>>& freq){
        if(rest == 0){
            ans.emplace_back(temp);
            return;
        }
        if(pos == freq.size() || rest < freq[pos].first){
            return;
        }
        // 直接跳过
        dfs(candidates, rest, pos + 1, ans, temp, freq);
        // 选择当前数
        int most = min(rest / freq[pos].first, freq[pos].second);
        for(int i = 1; i <= most; i++){
            temp.push_back(freq[pos].first);
            dfs(candidates, rest - i * freq[pos].first, pos + 1, ans, temp, freq);
        }
        for(int i = 1; i <= most; ++i){
            temp.pop_back();
        }
    }
};
```

​		