#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/**
 * @brief Time complexity : O(nlogn + logn) = O(nlogn)
 * 
 * @param nums 
 * @return int 
 */
    int missingNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int low = 0, high = nums.size()-1, mid;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(nums[mid] == mid) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> nums1 = {0, 7, 9, 3, 2, 4, 6, 8, 1};
    vector<int> nums2 = {3, 0, 1};
    vector<int> nums3 = {0, 1};
    vector<int> nums4 = {9, 6, 4, 2, 3, 5, 7, 0, 1};

    Solution s;
    cout << " num 1 : " << s.missingNumber(nums1) << endl;

    cout << " num 2 : " << s.missingNumber(nums2) << endl;

    cout << " num 3 : " << s.missingNumber(nums3) << endl;

    cout << " num 4 : " << s.missingNumber(nums4) << endl;
    return 0;
}