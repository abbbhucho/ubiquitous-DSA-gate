#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto num: nums) {
            ans = ans ^ num;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums1 = { 2, 2, 1 };
    vector<int> nums2 = {4, 1, 2, 1, 2};
    vector<int> nums3 = {1};
    vector<int> nums4 = {0, 4, 3, 7, 2, 7, 3, 4, 2};

    Solution s;
    cout << "1 ; " << s.singleNumber(nums1) << "\n";
    cout << "2 : " << s.singleNumber(nums2) << "\n";
    cout << "3 : " << s.singleNumber(nums3) << "\n";

    cout << "4 : " << s.singleNumber(nums4) << "\n";
    return 0;
}