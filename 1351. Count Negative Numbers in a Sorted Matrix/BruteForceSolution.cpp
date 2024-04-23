#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                   if(grid[i][j]<0){
                     cnt++;
                   }
            }
        }
        return cnt;
    }
};

int main(){

    vector<vector<int>> arr_2d = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}}; 
    vector<vector<int>> arr_2da = {{5,1,0},{-5,-5,-5}};
    vector<vector<int>> arr_2db = {{7,-3}};
    Solution s;
    cout << "# - negatives : " << s.countNegatives(arr_2db);
    return 0;
}