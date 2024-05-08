#include<iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<char> window;
        int maxlength = 0;
        for (int i = 0; i < n; i++)
        {
            auto it = find(window.begin(), window.end(), s[i]);
            if (it != window.end())
            {
                window.erase(window.begin(), it + 1);
            }
            window.push_back(s[i]);
            maxlength = max(maxlength, static_cast<int>(window.size()));
        }

        return maxlength;
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