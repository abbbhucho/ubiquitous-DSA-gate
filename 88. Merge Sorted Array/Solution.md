# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The concept involves merging of two arrays.

# Approach
<!-- Describe your approach to solving the problem. -->
compare at each array element simultaneously to let arrange in a single pass within both the sorted array.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(m+n)
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(m+n) // As it uses auxiliary array to temprarily store data
# Code
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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
        for(int j=0; j<(m+n); j++){
            nums1[j] = mergedArray[j];
        }
    }
};
```
