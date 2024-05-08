#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // first traverse the string
        string res = "";
        int str_count = 0, max_count = 0;
        if(s.length() != 0) {
            for(auto &ch : s) {
                int pos = res.find_first_of(ch) != string::npos ? res.find_first_of(ch) : string::npos;
                if(pos != string::npos) {
                    res.erase(0, pos+1); // as the range of erase is [first, last)
                    res += ch;
                    str_count = res.length();
                } else {
                    // if not found
                    res += ch;
                    str_count++;
                }
                if(max_count < str_count) {
                    max_count = str_count;
                }
            }
        }
        // if char not found in string then add the char to the res string
        // Use std::string::find(char c)
        // use count to get string length
        // if char found then remove all chars before and at the match and then  use count 
        return max_count;
    }
};

int main()
{
    string s1 = "abcabcbb";
    string s2 =  "bbbbb";
    string s3 = "pwwkew";

    Solution obj;
    cout << "ans : " << obj.lengthOfLongestSubstring(s2) << endl;
    return 0;
}