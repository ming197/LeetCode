#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdlib>

using namespace std;

class RandomizedCollection {
public:
    // 将所有的元素存在一个vector中
    vector<int> nums; 
    // key: nums的元素的值(不包含重复元素)，values：该元素在nums中的下标的集合
    unordered_map<int, unordered_set<int>> idx;
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.emplace_back(val);
        idx[val].insert(nums.size() - 1);
        // 该元素仅有一个（插入前不包含），下标集合size为1，返回true
        return idx[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(idx.find(val) == idx.end()){
            return false;
        }
        // 随意找出该元素在nums中的一个下标，并在集合中删除
        int i = *(idx[val].begin());
        idx[val].erase(i);

        // 删除固定位置的元素，保证删除操作的时间复杂度为 1
        nums[i] = nums.back();  // 将原最后一个位置的元素，移到待删除元素的位置
        // 最后一个元素位置发生改变
        idx[nums[i]].erase(nums.size() - 1);
        if (i < nums.size() - 1) {  
            idx[nums[i]].insert(i); 
        }

        // 如果待删除元素是唯一一个，删除该元素在哈希表中的位置
        if (idx[val].size() == 0) {
            idx.erase(val);
        }
        // 在nums中删除该元素
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        // 随机产生整数并取余
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */