#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num != 0) { 
            int digit = num % 10;
            sum += digit;
            num = num / 10;
            if(num == 0 && sum > 9){
                num = sum;
                sum = 0;
            }
        }
        return sum;
    }
};

int main()
{
    int num1 = 38;
    int num2 = 0;
    int num3 = 13255;
    Solution s;
    cout << "Add Digits : " << s.addDigits(num3) << "\n";

    return 0;
}