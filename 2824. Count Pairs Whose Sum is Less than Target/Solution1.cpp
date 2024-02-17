#include<bits/stdc++.h>
#include<vector>

using namespace std;
/*************************************
 * 
 *   TIME COMPLEXITY : O(n^2)
 * 
*/
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        // somewhat based on bubble sort
        const int size = nums.size();
        int no_of_pairs = 0;
        for(int i=0; i< size; i++) {
            for(int j=i+1; j<size; j++) {
                if((nums[i] + nums[j]) < target)
                    no_of_pairs++;
            }
        }
        return no_of_pairs;
    }
};

int main(){
    vector<int> v1 = {-1,1,2,3,1}; //2
    vector<int> v2 = {-6,2,5,-2,-7,-1,3}; //-2
    vector<int> v3 = {5,4,3,2,1,0,-1,-2}; //0

    Solution m;
    cout << "number of pairs:" << "\n"<< m.countPairs(v3, 0);
    
    return 0;
}