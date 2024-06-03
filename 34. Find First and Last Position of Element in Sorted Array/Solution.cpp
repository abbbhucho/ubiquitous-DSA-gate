#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        // finding lower bound
        int lb = -1;
        while(low <= high) {
            mid = low + (high - low) / 2; 
            if(target == nums[mid]) {
                if(mid-1 >=0 && nums[mid-1] == target) {
                    high = mid - 1;
                } else {
                    lb = mid;
                    break;
                }
            }
            else if(target < nums[mid]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        // finding upper bound
        low = 0, high = nums.size()-1,mid;
        int ub = -1;
        while(low <= high) {
            mid = low + (high - low) / 2; 
            if(target == nums[mid]) {
                if( mid+1 <= (nums.size()-1) && nums[mid+1] == target) {
                    low = mid + 1;
                } else {
                    ub = mid;
                    break;
                }
            }
            else if(target < nums[mid]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return {lb,ub};
    }
};

int main()
{
    vector<int> nums1 = {5,7,7,8,8,10}; int target1 = 8;
    vector<int> nums2 = {5,7,7,8,8,10}; int target2 = 6;
    vector<int> nums3 = {}; int target3 = 0;

    Solution s;
    vector<int> f1 = s.searchRange(nums1, target1);
    vector<int> f2 = s.searchRange(nums2, target2);
    vector<int> f3 = s.searchRange(nums3, target3);
    for(auto e1: f1) {
        std::cout << e1 <<"\t";
    }
    std::cout << "\n";
    for(auto e2: f2) {
        std::cout << e2 <<"\t";
    }
    std::cout << "\n";
    for(auto e3: f3) {
        std::cout << e3 <<"\t";
    }
    std::cout << "\n";
    
    return 0;
}