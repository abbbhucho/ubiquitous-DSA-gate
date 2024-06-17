#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
     vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> countOfCommon;
        map<int, int> countOfUncommon;

        for (auto ele : arr2) {
            countOfCommon[ele] = 0;
        }

        for (auto ele : arr1) {
            if (countOfUncommon.find(ele) != countOfUncommon.end()) {
                countOfUncommon[ele]++;
            } else if (countOfCommon.find(ele) == countOfCommon.end()) {
                countOfUncommon[ele] = 1;
            } else {
                countOfCommon[ele]++;
            }
        }

        int i = 0;
        for (auto ele : arr2) {
            int count = countOfCommon[ele];
            while (count > 0) {
                arr1[i] = ele;
                i++;
                count--;
            }
        }

        for (auto ele : countOfUncommon) {
            int count = ele.second;
            while (count > 0) {
                arr1[i] = ele.first;
                i++;
                count--;
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

    vector<int> res1 = obj.relativeSortArray(arr1a, arr2a);// << "\n";
    vector<int> res2 = obj.relativeSortArray(arr1b, arr2b);// << "\n";
    
    cout << "[";
    for(int a : res1) {
        cout << a << ", " ;
    }
    cout << " ]\n";

    cout << "[";
    for(int a : res2) {
        cout << a << ", " ;
    }
    cout << " ]\n";
    return 0;
}