#include<bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // find the size of nums1 array
        // this is done in order to find from where zeroes start 
        /*
        int count1 = 0;
        while(nums1[count1] == 0 && nums2[count1] == 0){
            count1++;
        } */
        /*
        int i, j = 0;
        while(i < m || j < n){
            if(nums1[i] < nums2[j]){
                nums1[m+i] = nums1[i+1];
                nums1[i+1] = nums2[j];
                i++;
            } else {
                nums1[m+i] = nums1[i+1];
            }
        }
        */
        int indexofMergedArray = 0;
        int *mergedArray = new int[m+n];
        int indexOfNums1 = 0, indexOfNums2 = 0;
        while(indexOfNums1 < m && indexOfNums2 < n) {
            if(nums1[indexOfNums1] <= nums2[indexOfNums2]){
                mergedArray[indexofMergedArray] = nums1[indexOfNums1];
                indexOfNums1++;
            } else {
                mergedArray[indexofMergedArray] = nums2[indexOfNums2];
                indexOfNums2++;
            }
            indexofMergedArray++;
        }
        while(indexOfNums2 < n){
            mergedArray[indexofMergedArray] = nums2[indexOfNums2];
            indexOfNums2++;
            indexofMergedArray++;
        }while(indexOfNums1 < m) {
            mergedArray[indexofMergedArray] = nums1[indexOfNums1];
            indexOfNums1++;
            indexofMergedArray++;   
        }
        //return mergedArray;
        for(int j=0; j<(m+n); j++){
            nums1[j] = mergedArray[j];
        }
        return nums1;
    }
};

void printarray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main(){
    vector<int> inputArray1 = {2,4,7,13,25,0,0,0,0,0};
    vector<int> inputArray2 =  {3,6,9,11,14};
    Solution m;
    vector<int> outputArr;
    outputArr = m.merge(inputArray1, 10, inputArray2, 5);
    cout << "\nArray after sorting \n";
    printarray(outputArr, 10);
    return 0;
}