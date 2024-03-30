#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumSum(int num)
    {
        vector<int> v(4);

        for (int i = 0; i < 4; i++)
        {
            v[i] = num % 10;
            num /= 10;
        }

        std::sort(v.begin(), v.end());

        return 10 * (v[0] + v[1]) + (v[2] + v[3]);
    }
};


int main(){
    int input1 = 2932;
    int input2 = 4009;
    int input3 = 1123;

    Solution s;
    cout << "Sum : " << s.minimumSum(input3);
    return 0;
}