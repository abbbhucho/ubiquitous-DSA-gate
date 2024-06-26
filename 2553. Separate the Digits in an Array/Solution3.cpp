#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/**
 * Time complexity
 * O(n * m) : n - length of array, m - average length of string
 * 
 * @param nums 
 * @return vector<int> 
 */
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto num:nums){
            string n = to_string(num);
            for(auto x:n){
                ans.push_back(x-'0'); // any single char subtracted by '0' converts it to int
            }
        }
        return ans;
    }
};

int main() {
    vector<int> num1 = {467, 24 , 67, 88, 0, 0, 2, 19999};

    Solution ob;
    vector<int> result = ob.separateDigits(num1);
    cout << "[";
    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
        if(result.begin() != result.end() && it != prev(result.end()))
            cout << *it << ", ";
        else 
            cout << *it;
    }
    cout << "]";
    return 0;
}