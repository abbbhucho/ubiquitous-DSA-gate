#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countNegatives(vector<vector<int>>& grid){
        const int m=grid.size();
        const int n=grid[0].size();
        int ans=0;
        int i=m-1;
        int j=0;
        while(i>=0 && j<n){
            if(grid[i] [j] < 0){
                ans += n-j;
                --i;
            }
            else
                ++j;
        }
        return ans;
    }
};

int main(){

    vector<vector<int>> arr_2d = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}}; 
    vector<vector<int>> arr_2da = {{5,1,0},{-5,-5,-5}};
    vector<vector<int>> arr_2db = {{7,-3}};
    Solution s;
    cout << "# - negatives : " << s.countNegatives(arr_2d);
    return 0;
}