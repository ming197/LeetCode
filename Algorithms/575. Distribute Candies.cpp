#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size();
        vector<int> dict(2e5 + 10, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int index = candies[i] < 0? candies[i] * -1 + 1e5 :  candies[i];
            if(dict[index] == 0){
                dict[index] = 1;
                cnt++;
            }
        }
        return min(n / 2, cnt);

    }
};

int main(){

}