#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //  as sorted and distinct array use binary search
        int index = -1;
        int low = 0, high = nums.size() - 1, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if( nums[mid] == target ) {
                index = mid;
                break;
            }
            if(nums[low] <= nums[mid]) {
                // left side is sorted
                if (nums[low] <= target && target <= nums[mid]) {
                    // if there in sorted portion then move in 
                    high = mid-1;
                } else {
                    // otherwise remove the sorted portion
                    low = mid+1;
                }
            } else {
                // right side is sorted
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        return index;
    }
};

int main()
{
    vector<int> nums1 = { 4, 5, 6, 7, 0, 1, 2 }; int target1 = 0;
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2}; int target2 = 3;
    vector<int> nums3 = {1}; int target3 = 0;
    vector<int> nums4= {5, 1, 3}; int target4 = 3;
    
    Solution obj;
    // cout << "Search in nums1: " << obj.search(nums1, target1) << endl;
    
    // cout << "Search in nums2: " << obj.search(nums2, target2) << endl;
    
    // cout << "Search in nums3: " << obj.search(nums3, target3) << endl;
    
    cout << "Search in nums 4: " << obj.search(nums4, target4) << endl;
    
    return 0;
}