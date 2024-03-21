#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }
};

int main(){

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