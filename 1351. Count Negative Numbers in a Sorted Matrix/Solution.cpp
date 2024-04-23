#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int negative_count = 0;
        for(int m=0; m < rows; m++) {
            if(grid[m][0] < 0 || grid[m][cols-1] < 0) {
                // then now we do binary search
                int low = 0, high = cols-1, mid;
                while(low <= high) {
                    mid = low + (high - low)/2;
                    if(grid[m][mid] < 0) {
                        if( mid != 0 && grid[m][mid-1] < 0 ) {
                            high = mid -1;
                        } else {
                            negative_count += (cols - mid);
                            break;
                        }
                    } else {
                        low = mid +1;
                    }
                }
            }
        }
        return negative_count;
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