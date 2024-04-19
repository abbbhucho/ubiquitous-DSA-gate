#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        return this->binarySearch(nums, low, high, target);
    }
    int binarySearch(vector<int> arr, int low, int high, int target) {
        if(low > high) {
            return -1;
        }
        int mid = low + ((high - low) >> 1); // to avoid overflow
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            return this->binarySearch(arr, mid+1, high, target);
        }
        else {
            return this->binarySearch(arr, low, mid-1, target);
        }

    }
};

int main(){
    vector<int> num1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;

    vector<int> num2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;

    vector<int> num3 = {5};
    int target3 = 5;
    Solution ob;
    int found = ob.search(num1, target1);
    if(found == -1 ) {
        cout << "not found : " << endl; 
    } else cout << "found at index : " << found << endl;

    return 0;
}