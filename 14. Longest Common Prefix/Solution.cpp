#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char first_char = '\0';
        string prefix = "";
        int j=0;
        // when first char is empty and first character is not yet added to it
        bool first_time = true; 
        for(auto i=0; i< strs.size(); i++) {
            string str = strs[i];
            if( j > str.size()-1) break;
            if (first_time) {
                first_char = str[j];
                first_time = false;
            }
            else {
                if(first_char != str[j]) {
                    break;
                }
                if( i == strs.size()- 1 ) {
                    // matches and is the last string in the array
                    prefix += first_char;
                    j++; // to check next character in each string
                    i = -1;
                    first_time = true;
                }
            }
            // j++;
        }
        return prefix;
    }
};

int main(){

    vector<string> strs = {"flower","flow","flight"};
    vector<string> strs2 = {"dog","racecar","car"};
    vector<string> strs3 = {"data", "database", "datawarehouse", "datastructures"};

    Solution obj;
    cout << "prefix: " << obj.longestCommonPrefix(strs3) << endl;

    return 0;
}