#include<bits/stdc++.h>
#include <vector>

using namespace std;

#define ROW 100000
#define COLUMN 2

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
         int n = points.size();
        
        //sort the array on the first value in ascending order.
        sort(points.begin(), points.end());

        //Calculating Area between each points and maintining that in maxArea
        int maxArea = 0;
        for(int i=1;i<n;i++) {
            int currArea = points[i][0]-points[i-1][0];
            maxArea = max(maxArea, currArea);
        }

        return maxArea;

    }
};

int main(){
    vector<vector<int>> v1 = {{8,7},{9,9},{7,4},{9,7}};
    vector<vector<int>> v2 = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};
    vector<vector<int>> v3 = {{1,1},{1,2},{1,3}};

    Solution m;
    cout << "max area:" << "\n"<< "v1: " << m.maxWidthOfVerticalArea(v1) << "\nv2: "<< m.maxWidthOfVerticalArea(v2) << "\nv3: " << m.maxWidthOfVerticalArea(v3);

    return 0;
}