#include<bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
/***
 * Time Complexity : O(n^2)
*/
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        const int size = nums.size();
        vector<int> sizeStore;
        int count = 0;
        for(int i=0; i < size; i++){
            for(int j=0; j<size; j++){
                if(i != j && nums[i] > nums[j]) {
                    count++;
                }
            }
            sizeStore.push_back(count);
            count = 0;
        }

        return sizeStore;
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