#include<bits/stdc++.h>
#include<vector>

using namespace std;
/*************************************
 * 
 *   TIME COMPLEXITY : O(nlog(n) + Ω(n) i.e time spent for only sorting)
 * 
*/
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end()); // sort the vector nums
        int count = 0; // variable to store the count
        int left = 0; // variable to store the left
        int right = nums.size()-1; // variable to store the right
        while(left < right){ // loop until left is less than right
            if(nums[left] + nums[right] < target){ // if nums[left] + nums[right] is less than target
                count += right-left; // update the count
                left++; // increment the left
            }
            else{ // else
                right--; // decrement the right
            }
        }
        return count; // return the count
    }
};

int main(){
    vector<int> v1 = {-1,1,2,3,1}; //2
    vector<int> v2 = {-6,2,5,-2,-7,-1,3}; //-2
    vector<int> v3 = {5,4,3,2,1,0,-1,-2}; //0

    Solution m;
    cout << "number of pairs:" << "\n"<< m.countPairs(v1, 2);
    
    return 0;
}