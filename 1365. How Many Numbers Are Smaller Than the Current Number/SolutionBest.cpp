#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::map<int, int> um;

        for (auto i : nums)
            ++um[i];

        int temp = 0;

        for (auto v : um) {
            um[v.first] = temp;
            temp += v.second;
        }

        vector<int> ans;
        ans.resize(nums.size());

        for (int j = 0; j < nums.size(); ++j)
            ans[j] = um[nums[j]];

        return ans;
    }
};


int main()
{
    vector<int> v1 = {8,1,2,2,3};
    vector<int> v2 = {6,5,4,8};
    vector<int> v3 = {7,7,7,7};

    Solution s;
    vector<int> result = s.smallerNumbersThanCurrent(v1);
    cout<<"store of all the count of elements smaller than the given index element: \n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    
    return 0;
}