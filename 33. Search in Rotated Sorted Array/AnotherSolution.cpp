#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotelem(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        while (s <= e) {
            cout << "\ns=" << s << " e=" << e << " mid=" << mid << endl;
            if (s == e) {
                cout << "edge case";
                return s;
            }
            if (mid + 1 <= e && nums[mid] > nums[mid + 1]) {
                cout << "first";
                return mid;
            }
            if (mid - 1 >= s && nums[mid] < nums[mid - 1]) {
                cout << "second";
                return mid - 1;
            }
            if (nums[mid] < nums[s]) {
                cout << "\nIn line B\n";
                e = mid - 1;
            } else {
                cout << "\nIn line A\n";
                s = mid + 1;
            }

            mid = s + (e - s) / 2;
        }
        return -1;
    }

    int BS(vector<int>& nums, int start, int end, int target) {
        int s = start;
        int e = end;
        int mid = s + (e - s) / 2;
        cout << "\n\nBS = ";
        while (s <= e) {
            cout << "\ns=" << s << " e=" << e << " mid=" << mid << endl;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int ans = pivotelem(nums);
        cout << ans << "\nval = " << nums[ans];
        int tarind = 0;
        if (target >= nums[0] && target <= nums[ans]) {
            tarind = BS(nums, 0, ans, target);
        } else {
            tarind = BS(nums, ans + 1, nums.size() - 1, target);
        }
        return tarind;
    }
};

int main()
{
    vector<int> nums1 = { 4, 5, 6, 7, 0, 1, 2 }; int target1 = 0;
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2}; int target2 = 3;
    vector<int> nums3 = {1}; int target3 = 0;
    vector<int> nums4= {5, 1, 3}; int target4 = 3;
    
    Solution obj;
    cout << "Search in nums1: " << obj.search(nums1, target1) << endl;
    
    cout << "Search in nums2: " << obj.search(nums2, target2) << endl;
    
    cout << "Search in nums3: " << obj.search(nums3, target3) << endl;
    
    cout << "Search in nums 4: " << obj.search(nums4, target4) << endl;
    
    return 0;
}