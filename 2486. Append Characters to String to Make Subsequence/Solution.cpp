#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int ns=s.size(), nt=t.size(), i=0, j=0;
        for(i=0; i<ns; i++){
            if(s[i]==t[j]) j++;
        }
        return nt-j;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main()
{
    string s1 = "coaching", t1 = "coding";
    string s2 = "abcde", t2 = "a";
    string s3 = "z", t3 = "abcde";

    Solution s;
    cout << "ichi: " << s.appendCharacters(s1,t1) << "\n";
    
    cout << "ni: " << s.appendCharacters(s2,t2) << "\n";

    cout << "san: " << s.appendCharacters(s3,t3) <<  "\n";

    return 0;
}