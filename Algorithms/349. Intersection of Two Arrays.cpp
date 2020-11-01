#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        for(auto& num : nums1){
            s1.insert(num);
        }
        for(auto& num : nums2){
            s2.insert(num);
        }
        vector<int> ans;
        for(auto it = s1.begin(); it != s1.end(); it++){
            if(s2.find(*it) != s2.end()){
                ans.emplace_back(*it);
            }
        }
        return ans;
    }
};