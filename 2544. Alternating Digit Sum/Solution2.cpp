#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        vector <int> nums;
        int ans = 0, l = 1;
        while (n != 0){
            nums.push_back(n % 10);
            n /= 10;
        }
        for (int i = nums.size() - 1; i >= 0; --i){
            ans += nums[i] * l;
            l *= (-1);
        }
        return ans;
    }
};

int main()
{
    int n1 = 521;
    int n2 = 111;
    int n3 = 886996;

    Solution s;

    cout<< "Alternating Sum: "<< s.alternateDigitSum(n3);
    return 0;
}