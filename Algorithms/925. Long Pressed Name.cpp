#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p = 0, q = 0;
        while(q < typed.size()){
            if(name[p] == typed[q]){
                p++;
                q++;
            }else if(q > 0 && typed[q-1] == typed[q]){
                q++;
            }else{
                return false;
            }
        }
        return (p == name.size());

    }
};