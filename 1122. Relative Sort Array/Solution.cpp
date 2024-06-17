#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/**
 * @brief BRUTE FORCE
 * 
 * @param arr1 
 * @param arr2 
 * @return vector<int> 
 */
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        for(int j=0, k=0, i=k; j< arr2.size(); j++) {
            for(i=k; i< arr1.size(); i++) {
                if(arr2[j] == arr1[i]) {
                    swap(arr1[i], arr1[k]); k++;
                }
            }
            if(i != k && j == arr2.size()-1) {
                sort(arr1.begin() + k, arr1.end());
            }
        }
        return arr1;
    }
};

int main()
{
    vector<int> arr1a = {2,3,1,3,2,4,6,7,9,2,19}, arr2a = {2,1,4,3,9,6};
    vector<int> arr1b = {28,6,22,8,44,17}, arr2b = {22,28,8,6};

    Solution obj;

    // vector<int> res1 = obj.relativeSortArray(arr1a, arr2a);// << "\n";
    vector<int> res2 = obj.relativeSortArray(arr1b, arr2b);// << "\n";
    
    // cout << "[";
    // for(int a : res1) {
    //     cout << a << ", " ;
    // }
    // cout << " ]\n";

    cout << "[";
    for(int a : res2) {
        cout << a << ", " ;
    }
    cout << " ]\n";
    return 0;
}
