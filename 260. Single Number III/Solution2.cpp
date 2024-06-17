#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
        int rsbm;
        for(auto x:nums){
            ans=ans^x;
        }
        if (ans != INT_MIN) { // Check if ans is not INT_MIN to avoid overflow
            rsbm = ans & -ans; // Find the rightmost set bit
        }
        int x1=0;
        int y=0;

        for(auto x:nums){
            if((rsbm & x)==0){
                x1=x1^x;
            }
            else{
                y=y^x;
            }
        }
        return {x1,y};
        
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 1, 3, 2, 5};
    vector<int> nums2 = {-1, 0};
    vector<int> nums3 = {0, 1};
    Solution s;
    vector<int> res = s.singleNumber(nums1);
    cout << "{ " << res[0] << ", " << res[1] << "}" << endl;
    return 0;
}