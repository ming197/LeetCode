#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> changeNum;
        for(auto& bill : bills){
            if(bill == 5) changeNum[5]++;
            if(bill == 10){
                if(changeNum[5] == 0) return false;
                else changeNum[5]--;
                changeNum[10]++;
            }
            if(bill == 20){
                if(changeNum[5] > 0){
                    if(changeNum[10] > 0){
                        changeNum[5]--;
                        changeNum[10]--;
                    }else{
                        if(changeNum[5] >= 3) changeNum[5] -= 3;
                        else return false;
                    }
                }else{
                    return false;
                }
                changeNum[20]++;
            }           
        }
        return true;
    }
};


int main(){
    Solution solution;

    vector<int> array = {5,5,5,10,20};
    bool ans = solution.lemonadeChange(array);
    cout << ans;
    return 0;
}