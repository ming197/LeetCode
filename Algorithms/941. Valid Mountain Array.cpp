#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 2) return false;
        bool flag = false;
        int p = 0, q = 1;
        if(A[p] >= A[q]) return false;
        p++;
        q++;
        while(q < A.size()){
            if(!flag){
                if(A[p] >= A[q]) flag = true;
                else{
                    p++;
                    q++;
                }
            }else{
                if(A[p] <= A[q]) return false;
                else{
                    p++;
                    q++;
                }
            }
        }
        return true&flag;

    }
};

int main(){

    return 0;
}