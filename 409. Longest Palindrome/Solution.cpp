#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_set<char> charSet;
        int length = 0;
        //  to find all pair if chars in string
        for (char c : s) {
            if (charSet.find(c) != charSet.end()) {
                charSet.erase(c);
                length += 2;
            } else {
                charSet.insert(c);
            }
        }
        // if charset is not empty means it has some characters with single occurrence 
        if (!charSet.empty()) {
            length += 1;
        }
        
        return length;
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