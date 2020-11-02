#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

// 所有的上升线段都计算进去
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for(int i = 1; i < n; i++){
            if(prices[i - 1] < prices[i]) ans += (prices[i] - prices[i - 1]);
        }
        return ans;
    }
};


int main(){

    return 0;
}