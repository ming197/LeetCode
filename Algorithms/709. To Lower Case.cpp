#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        int change_num='a'-'A';
        for(auto& letter : str){
            if(letter <= 'Z' && letter >= 'A') letter = letter + change_num;
        }
        return str;
    }
};