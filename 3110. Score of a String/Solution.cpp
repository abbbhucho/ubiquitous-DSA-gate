#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int ch=0; s[ch+1] != '\0';ch++) {
            int val = (int)(s[ch+1] - s[ch]);
            val = val < 0 ? -val : val;
            sum += val;
        }
        return sum;
    }
};

int main()
{
    string s1 = "hello";
    string s2 = "zaz";
    string s3 = "goku";
    
    Solution s;
    cout << "one : \t" << s.scoreOfString(s1) << "\n";
    cout << "two : \t" << s.scoreOfString(s2) << "\n";
    cout << "three : \t" << s.scoreOfString(s3) << "\n";
    
    return 0;
}