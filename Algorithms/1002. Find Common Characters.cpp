#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> hash_mapp(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++){
            for(auto& letter : A[i]){
                hash_mapp[i][letter - 'a']++;
            }
        }
        
        vector<string> ans;
        for(int j = 0; j < 26; j++){
            int nums = 110;
            for(int i = 0; i < n; i++){
                nums = min(nums, hash_mapp[i][j]);
            }
            while (nums--)
            {   
                string s;
                s.push_back('a' + j);
                ans.emplace_back(s);
            }
            
        }

        return ans;

    }
};

int main(){

    return 0;
}