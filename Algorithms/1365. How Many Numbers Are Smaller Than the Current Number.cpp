#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> hash_map(110, 0);
        vector<int> dict(110, 0);
        for(int& num : nums){
            hash_map[num]++;
        }
        for(int i = 1; i < 110; i++){
            dict[i] = dict[i - 1] + hash_map[i - 1];
        }
        vector<int> ans;
        for(int& num : nums){
            ans.emplace_back(dict[num]);
        }
        return ans;
    }
};

int main(){

    return 0;
}