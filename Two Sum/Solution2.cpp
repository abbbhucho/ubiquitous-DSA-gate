#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        int size = nums.size();
        vector<int> result;
        sort(nums.begin(), nums.end()); // Time complexity: O(nlogn);
        /**
         * @brief Two Pointer concept
         * 
         */
        for(int i=0,j = size-1; i<j;){
            int sum = nums[i] + nums[j];
            if(sum == target){
                result.push_back(i+1);
                result.push_back(j+1);

            } else if(sum < target){
                // we need to increase the value, as nums is arranged in asc order 
                i++;
            } else {
                j--;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> v1 = {2,7,11,15};
    int t1 = 9;
    vector<int> v2 = {3,2,4};
    int t2 = 6;
    vector<int> v3 = {3,3};
    int t3 = 6;

    Solution s;
    vector<int> result = s.twoSum(v3, t3);
    cout<<"two Sum: \n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    
    return 0;
}