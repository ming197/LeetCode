#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> maxSubsequence(k, 0);
        int minLength = max(0, k - n), maxLength = min(k, m);
        for(int i = minLength; i <= maxLength; i++){
            vector<int> sub1(MaxSubsequence(nums1, i));
            vector<int> sub2(MaxSubsequence(nums2, k - i));
            vector<int> curMaxSubsequence(merge(sub1, sub2));
            if(compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) {
                maxSubsequence.swap(curMaxSubsequence);
            }
        }
        return maxSubsequence;
    }

    vector<int> MaxSubsequence(vector<int>& nums, int seqLength){
        vector<int> stk;
        int length = nums.size();
        // 表示（最多）可以不入栈的个数
        int remain = length - seqLength;
        for(int i = 0; i < length; i++){
            int num = nums[i];
            // 单调栈，跳过一个元素，remain减一
            while(stk.size() > 0 && remain > 0 && num > stk.back()){
                stk.pop_back();
                remain--;
            }
            if(stk.size() < seqLength) stk.push_back(num);
            else remain--;
        }
        return stk;
    }

    vector<int> merge(vector<int>& sub1, vector<int>& sub2){
        int m = sub1.size(), n = sub2.size();
        if(!m || !n) return (m == 0 ? sub2 : sub1);
        vector<int> mergedSeq;
        int i = 0, j = 0;
        while (i < m && j < n){
            if(compare(sub1, i, sub2, j) > 0) mergedSeq.push_back(sub1[i++]);
            else mergedSeq.push_back(sub2[j++]);
        }
        if(i == m) mergedSeq.insert(mergedSeq.end(), sub2.begin() + j, sub2.end());
        if(j == n) mergedSeq.insert(mergedSeq.end(), sub1.begin() + i, sub1.end());
        return mergedSeq; 
    }
    // 比较两个等长数组的大小
    int compare(vector<int> seq1, int index1, vector<int> seq2, int index2){
        int m = seq1.size(), n = seq2.size();
        while(index1 < m && index2 < n){
            int difference = seq1[index1] - seq2[index2];
            if(difference != 0) return difference;
            index1++;
            index2++;
        }
        return (m - index1) - (n - index2);
    }
};


int main(){
    Solution solution;
    vector<int> a = {6, 7};
    vector<int> b = {6, 0, 4};
    vector<int> c(solution.merge(a, b));
    for(auto& num : c){
        cout << num << endl;
    }
    return 0;
}