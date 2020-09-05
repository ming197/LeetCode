#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return total(nums, 0, nums.size() - 1, 1) >= 0;
    }
    int total(vector<int>& nums, int start, int end, int turn){
        if(start == end) return nums[start]*turn;
        int startScore = nums[start]*turn + total(nums, start+1, end, -turn);
        int endScore = nums[end]*turn + total(nums, start, end-1, -turn);
        return max(startScore*turn, endScore*turn)*turn;
    }
};

int main(){

    return 0;
}