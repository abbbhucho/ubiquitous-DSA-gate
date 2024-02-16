#include<bits/stdc++.h>
#include <vector>

using namespace std;

#define ROW 100000
#define COLUMN 2

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int x_coordinates[100000];
        int number_of_points = points.size();
        for (int i = 0; i < number_of_points; i++) {
            x_coordinates[i] = points[i][0];
        }
        
        //sort the x-coordinates
        //const int size = sizeof(x_coordinates)/sizeof(int);
        //sort(x_coordinates.begin(), x_coordinates.end()); 
        sort(x_coordinates, x_coordinates + number_of_points);
        //check the maximum distance between x_coordinates
        int max_distance = 0;
        for(int n=0; n < number_of_points; n++) {
            if((x_coordinates[n+1]- x_coordinates[n]) > max_distance){
                max_distance = (x_coordinates[n+1] - x_coordinates[n]);
            }
        }
        return max_distance;

    }
};

int main(){
    vector<vector<int>> v1 = {{8,7},{9,9},{7,4},{9,7}};
    vector<vector<int>> v2 = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};
    vector<vector<int>> v3 = {{1,1},{1,2},{1,3}};

    Solution m;
    cout << "max distance:" << "\n"<< m.maxWidthOfVerticalArea(v3);
    
    return 0;
}