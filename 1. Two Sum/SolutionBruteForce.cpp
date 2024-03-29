#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /**
         * @brief Logic
         * second_number = target - nums[i] 
         * If we can find this number quickly, sort then use binary search
         */
        /*vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        for(int i=0; i<n; i++){
            int second_number = target - sorted_nums[i];
            if(binary_search(sorted_nums.begin(), sorted_nums.end(), second_number))
        }*/
        int i,j;
        int n = nums.size();
        for(i=0; i<n; i++){
            for(j=0; j<n;j++){
                if( i != j ){
                    if(nums[i] + nums[j] == target){
                        break;
                    }
                }
            }
            if(nums[i] + nums[j] == target){
                break;
            }
        }
        vector<int> result;
        result.push_back(i);
        result.push_back(j);
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