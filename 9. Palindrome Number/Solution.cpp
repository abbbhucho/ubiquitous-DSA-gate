#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x) {
        vector<int> digits;
        int i = 0;
        while( x != 0 ){
            digits.push_back(x % 10);
            x = x/10;
            i++;
        }
        for(int j=0; j <= i; j++, i--){
            if(digits[j] != digits[i-1]){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int t;
    while( t-- ){
        int n1;
        cin >> n1;
        Solution s;
        cout<< "palindrome or not: " << std::boolalpha << s.isPalindrome(n1);
    
    }
    // int n1 = 121;
    // int n2 = -121;
    // int n3 = 14366341;
    // int n4 = 5678998765;
    // int n5 = 0;
    // int n6 = -346642;

    return 0;
}