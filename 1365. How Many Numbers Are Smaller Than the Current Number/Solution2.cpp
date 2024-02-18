#include<bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
/***
 * Time Complexity: O(nlog(n) , Space Complexity too high and out of place : 2 * O(n))
*/
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> sorted_nums = nums;  
        sort(sorted_nums.begin(), sorted_nums.end());
        unordered_map<int, int> index_map;

        for (int i = 0; i < n; ++i) {
            if (index_map.find(sorted_nums[i]) == index_map.end()) {
                index_map[sorted_nums[i]] = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            result[i] = index_map[nums[i]];
        }

        return result;
        /*
        vector<int> ans = nums;
        unordered_map<int, int> m;
        sort(ans.begin(), ans.end());
        for (int i = nums.size() - 1; i >= 0; i--)
            m[ans[i]] = i;
        for (int i = 0; i < nums.size(); i++)
            nums[i] = m[nums[i]];
        return nums;
        */
    }
};


int main()
{
    vector<int> v1 = {8,1,2,2,3};
    vector<int> v2 = {6,5,4,8};
    vector<int> v3 = {7,7,7,7};

    Solution s;
    vector<int> result = s.smallerNumbersThanCurrent(v3);
    cout<<"store of all the count of elements smaller than the given index element: \n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    
    return 0;
}