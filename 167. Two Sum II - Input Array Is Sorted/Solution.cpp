#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n-1;
        vector<int> result = {};
        while(i < j){
            int rem = target - numbers[i];
            if(rem == numbers[j]){
                result = {i, j};
                break;
            } else if(rem < numbers[j]) {
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

    vector<int> v2 = {2,3,4};
    int t2 = 6;

    vector<int> v3 = {-1,0};
    int t3 = -1;

    Solution s;
    vector<int> result = s.twoSum(v1, t1);
    for(auto i:result){
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}