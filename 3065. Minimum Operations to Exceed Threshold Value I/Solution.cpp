#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @brief uses binary search principle so, need of sorting : nlogn + logn = : O(nlogn) 
     * 
     * @param nums 
     * @param k 
     * @return int 
     */
    int minOperations(vector<int>& nums, int k) {
        /*
        * Question involves treating k as the lower bound
        */
        int start = 0, end = nums.size()-1, mid;
        bool match_found = false;
        int lowerIndex = -1;
        sort(nums.begin(), nums.end());
        while(start <= end) {
            mid = start + ((end - start) / 2);
            if(nums[mid] == k) {
                lowerIndex = mid;
                end = mid -1; // check for lowest duplicate value
                match_found = true; // used for not matching case
            } else if (nums[mid] < k) {
                start = mid +1;
            } else {
                end = mid -1;
            }
        }
        if(!match_found) {
            lowerIndex = start;
        }
        return lowerIndex;
    }
};

int main()
{
    vector<int> nums1 = { 2, 11, 10, 1, 3 };
    int k1 = 10;

    vector<int> nums2 = { 1, 1, 2, 4, 9 };
    int k2 =1, k3 = 9;

    vector<int> nums3 = {15136, 34673, 45724, 25657, 45723, 97563, 76777, 10001, 83672 };
    int k4 = 77000;

    Solution s;
    cout <<  "the minimum number of operations needed so that all elements of the array are greater than or equal to " << k4 << " : " << s.minOperations(nums3, k4) <<endl;
    return 0;
}