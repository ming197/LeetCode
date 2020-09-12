#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 10){
            if(x >= 0) return true;
            else return false;
        }
        vector<int> nums;
        while(x){
            nums.emplace_back(x % 10);
            x /= 10;
        }

        int left = 0, right = nums.size() - 1;
        while(left < right){
            if(nums[left] != nums[right]) return false;
            left++;
            right--;
        }
        return true;

    }
};


int main(){

    return 0;
}