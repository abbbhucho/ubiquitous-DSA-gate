#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @brief uses simple iteration time complexity : O(n)
     * 
     * @param nums 
     * @param k 
     * @return int 
     */
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < k) {
                count++;
            }
        }
        return count;
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
    cout <<  "the minimum number of operations needed so that all elements of the array are greater than or equal to " << k1 << " : " << s.minOperations(nums1, k1) <<endl;
    return 0;
}