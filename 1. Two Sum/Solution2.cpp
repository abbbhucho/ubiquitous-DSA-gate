#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        int size = nums.size();
        vector<int> result;
        vector<int> orig = nums;
        sort(nums.begin(), nums.end()); // Time complexity: O(nlogn);
        /**
         * @brief Two Pointer concept
         * 
         */
        for(int i=0,j = size-1; i<j;){
            int sum = nums[i] + nums[j];
            if(sum == target){
                auto start = std::find(orig.begin(), orig.end(), nums[i]);// - orig.begin();
                auto end = std::find(orig.begin(), orig.end(), nums[j]);
                if(start == end && end != orig.end()) {
                    end = std::find(end+1, orig.end(), nums[j]);// - orig.begin();
                }
                result.push_back(start - orig.begin());
                result.push_back(end - orig.begin());
                break;

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
    vector<int> result = s.twoSum(v1, t1);
    cout<<"two Sum: \n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    
    return 0;
}