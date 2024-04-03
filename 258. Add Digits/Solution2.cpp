#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/**
 * @brief Math Solution
 * 
 * Time Complexity : O(1)
 * Space Complexity : O(1)
 * 
 * https://leetcode.com/problems/add-digits/solutions/3781389/c-python-c-beats-100-with-math-proof/
 *
 * The logic behind this approach is :

To check if a number is divisible by 9, add the digits of the number and check if the sum is divisible by 9 or not. If yes, is the case,  the number is divisible by 9, otherwise, it’s not.

let’s take 27  i.e (2+7 = 9) hence divisible by 9.
If a number n is divisible by 9, then the sum of its digit until the sum becomes a single digit is always 9. For example, 
Let, n = 2880 
Sum of digits = 2 + 8 + 8 = 18: 18 = 1 + 8 = 9

Therefore,
A number can be of the form 9x or 9x + k. For the first case, the answer is always 9. For the second case, and is always k which is the remainder left.

The problem is widely known as the digit root problem.

https://en.wikipedia.org/wiki/Digital_root
 */
    int addDigits(int num) {
        if (num == 0)
            return 0;
        int ans = num % 9;
        return (ans == 0) ? 9 : ans;
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