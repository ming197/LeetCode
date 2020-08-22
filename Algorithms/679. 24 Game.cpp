#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

    bool judgePoint24(vector<int>& nums) {
        vector<double> l;
        for(const int& num : nums){  // 将输入的整型转换为浮点型
            l.emplace_back(static_cast<double>(num));
        }
        return solve(l);
    }

    bool solve(vector<double>& l){
        if(l.size() == 0){
            return false;
        }
        if(l.size() == 1){ // 递归边界, 等于 0 的判断方法
            return fabs(l[0] - TARGET) < EPSILON;
        }

        int size = l.size();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){ 
                if(i != j){     // 从列表中任意选出两个数进行运算，枚举所有的情况
                    vector<double> list2 = vector<double>();
                    for(int k = 0; k < size; k++){ // 将未参与运算的数放入 list2 中
                        if(k != i && k != j){
                            list2.emplace_back(l[k]);
                        }
                    }
                    for(int k = 0; k < 4; k++){
                        if(k < 2 && i < j) continue;    // +, * 满足交换律, 只需计算一遍即可
                        if(k == ADD){
                            list2.emplace_back(l[i] + l[j]);
                        }else if(k == MULTIPLY){
                            list2.emplace_back(l[i] * l[j]);
                        }else if(k == SUBTRACT){
                            list2.emplace_back(l[i] - l[j]);
                        }else if(k == DIVIDE){
                            if(fabs(l[j]) < EPSILON){   // 遇到除以 0 的情况，需要直接跳过
                                continue;
                            }
                            list2.emplace_back(l[i] / l[j]);
                        }
                        if(solve(list2)){   // 递归
                            return true;
                        }
                        list2.pop_back();   // 进行下一次循环之前，需要将上一步四则运算的结果从 list2 中删除
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    vector<int> data = {1, 3, 2, 6};
    Solution solution;
    bool ans = solution.judgePoint24(data);

    cout << ans;
}