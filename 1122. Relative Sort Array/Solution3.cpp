#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = *max_element(arr1.begin(), arr1.end());
        // max_element (ForwardIterator first, ForwardIterator last) returns a pointer to the largest
        // element in the range, and in case if there are more than one such element, then it points to the first one.
        vector<int> count(maxElement + 1);
        // read vector constructor (https://cplusplus.com/reference/vector/vector/vector/)

        // Count occurrences of each element
        for (int element : arr1) {
            count[element]++;
        }

        vector<int> result;
        // Add elements as per relative order
        for (int element : arr2) {
            while (count[element] > 0) {
                result.push_back(element);
                count[element]--;
            }
        }
        // Add remaining elements in ascending order
        for (int num = 0; num <= maxElement; num++) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        return result;
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