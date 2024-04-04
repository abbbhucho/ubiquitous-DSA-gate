#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long reversed = 0;
        long long temp = x;

        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }
};

int main()
{
    int t = 0;
    cin >> t;
    while( t-- ){
        int n1;
        cin >> n1;
        Solution s;
        cout<< "palindrome or not: " << std::boolalpha << s.isPalindrome(n1) << "\n";
    
    }
    return 0;
}