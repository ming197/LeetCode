#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int last[26];
        int n = S.size();
        for(int i = 0; i < n; i++){
            last[S[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        for(int i = 0; i < n; i++){
            end = max(end, last[S[i] - 'a']);
            if(i == end){
                ans.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}