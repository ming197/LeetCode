#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    unordered_map<char, vector<int>> move = {
        {'R', {1, 0}},
        {'L', {-1, 0}},
        {'U', {0, 1}},
        {'D', {0, -1}}
    };
    bool judgeCircle(string moves) {
        int x = 0,  y = 0;
        for(auto c : moves){
            x += move[c][0];
            y += move[c][1];
        }

        return (x == 0) && (y == 0);
    }
};

int main(){

    return 0;
}