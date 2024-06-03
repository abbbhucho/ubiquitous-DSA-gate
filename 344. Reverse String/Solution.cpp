#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for(int c=0; c < size/2; c++) {
            swap(s[c],s[size-1-c]);
        }
        /**Other method
            int a=0;
            int b=s.size()-1;
            while(a<b){
                swap(s[a++],s[b--]);
            
            
            }
        * 
        */
    }
};

int main()
{
    vector<char> str1 = {'h','e','l','l','o'};
    vector<char> str2 = {'H','a','n','n','a','h'};

    Solution s;
    s.reverseString(str1);
    s.reverseString(str2);
    
    for(char ch: str1) {
        cout << ch << "\t";
    }
    cout<< "\n";
    
    for(char ch: str2) {
        cout << ch << "\t";
    }
    cout<< "\n";

    return 0;
}