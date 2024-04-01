#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int i=0;
        int sum = 0;
        vector<int> digits;
        while(n > 0){
            digits.push_back(n%10);
            n = n/10;
            i++;
        }
        bool msb_sign = (i%2 == 0) ? false : true; // checking for odd
        while(i > 0){
            if((i%2 != 0) == msb_sign){
                sum += digits[--i];
            } else {
                sum -= digits[--i];
            }
        }
        return sum;
    }
};

int main()
{
    int n1 = 521;
    int n2 = 111;
    int n3 = 886996;

    Solution s;

    cout<< "Alternating Sum: "<< s.alternateDigitSum(n1);
    return 0;
}