#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        int low = 0, mid, high = nums.size()-1;
        
        while(low <= high) 
        {
            mid = (low+high)/2;
            if(target < nums[mid]) {
                high = mid-1;
            } else if(target > nums[mid]) {
                low = mid+1;
            } else if(target == nums[mid]) {
                index = mid;
                break;
            }
        }
        return index;
    }
};

int main()
{
    vector<int> num1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;

    vector<int> num2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;

    vector<int> num3 = {5};
    int target3 = 5;
    Solution ob;
    int found = ob.search(num3, target3);
    if(found == -1 ) {
        cout << "not found : " << endl; 
    } else cout << "found at index : " << found << endl; 
    
    return 0;
}