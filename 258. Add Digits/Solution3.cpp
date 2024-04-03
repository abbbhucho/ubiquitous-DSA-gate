#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int addDigits(int num) {
        int sum = 0;
        // Loop to do sum while
        // sum is not less than
        // or equal to 9
        while(num > 0 || sum > 9)
        {
            if(num == 0)
            {
                num = sum;
                sum = 0;
            }
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

int main()
{
    int n = 1234;
    Solution s;
    cout << s.addDigits(n);
    return 0;
}