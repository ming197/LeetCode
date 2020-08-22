// 参考链接： https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/


// cur表示当前位数（个十百千万）上数值的大小
// digit为位因子大小为 10^i
// low、high分别表示cur前后 数的大小
// 如：2314， 当cur = 2时， digit = 100, high = 2, low = 14 


class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        long long digit = 1, res = 0;
        int high = n / 10, cur = n % 10, low = 0;
        while(high != 0 || cur != 0){
            if(cur == 0) res += high * digit;   // cur为0时，只需要考虑high部分的取值范围 len:[0， high-1]*digit
            else if(cur == 1) res += high * digit + low + 1;    // cur为1时，同时考虑high和low, high取值范围有len:[0, high-1]*digit和 len:[high]*[0, low]俩种
            else res += (high + 1) * digit; // cur为2时，high 的取值范围为len:[0, high]*digit
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};