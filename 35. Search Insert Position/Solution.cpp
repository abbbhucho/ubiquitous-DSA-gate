#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid;
        while( low <= high ) {
            mid = low + ((high-low) >> 1);
            if (nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                low = mid +1;
            } else {
                high = mid -1;
            }
        }
        if(low > high) {
            return low;
        }
        return -1;
    }
};

int main()
{
    vector<int> num1 = {1,3,5,6};
    int target1 = 9;

    vector<int> num2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;

    vector<int> num3 = {5};
    int target3 = 5;

    int t1 = 5, t2 = 2, t3 = 7;
    Solution ob;
    int found = ob.searchInsert(num1, t2);
    cout << "found / can be inserted at index : " << found << endl; 
    
    return 0;
}