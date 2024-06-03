#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int s = 1, e = x;
        long long int m;
        long long int val = m*m;
        while(s <= e) {
            m = s + (e-s)/2;
            if(val > x) {
                e = m-1;
            }
            else {
                s = m+1;
            }
        }
        return e;
    }
};

int main()
{
    int x1[4] = { 4, 8, 16, 815 };
    Solution s;
    for(int x : x1) {
        cout << "\t" << s.mySqrt(x) <<"\n";
    }
    return 0;
}