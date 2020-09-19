#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, max_profit = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(prices[i], min_price);
        }

        return max_profit;
        
    }
};



int main(){

    return 0;
}