#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        unordered_map<char, int> ump;

        for(char ch : s) {
            ump[ch]++;
            if (ump[ch] % 2 == 1)
                oddCount++;
            else    
                oddCount--;
        }

        if (oddCount > 1)
            return s.length() - oddCount + 1;
            
        return s.length();
    }
};

int main()
{
    string s1 = "abccccdd";
    string s2 = "a";

    Solution obj;
    cout << "s1: "<<obj.longestPalindrome(s1)<< "\n";
    cout << "s2: "<<obj.longestPalindrome(s2)<< "\n";

    return 0;
}