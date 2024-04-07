#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/**
 * @brief separate digits from a list of integer numbers
 * 
 * @param nums 
 * @return vector<int>
 * 
 * Time Complexity: O(n^2) 
 */
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits = {}, result = {};
        for(int i=0; i < nums.size(); i++){
            int num = nums[i];
            if(num == 0) {
                digits.push_back(0);
            }
            while(num != 0){
                digits.push_back( num % 10 );
                num = num / 10;
            }
            while(!digits.empty()){
                result.push_back(digits.back());
                digits.pop_back();
            }
        }
        return result;
    }
};

int main()
{
    vector<int> num1 = { 13, 25, 83, 77 };
    vector<int> num2 = {567, 25, 75642, 1};
    vector<int> num3 = {22, 0, 0, 0, 10};
    vector<int> num4 = {7, 1, 3, 9};

    Solution s;
    cout << "separated digits in the array : " << "\n";
    vector<int> result = s.separateDigits(num1);
    vector<int> result2 = s.separateDigits(num2);
    vector<int> result3 = s.separateDigits(num3);
    vector<int> result4 = s.separateDigits(num4);

    cout<< "[ ";
    // for(auto p:result) {
    //     if( result[p] != result.back()) {
    //         cout << result[p] << ", ";
    //     } else {
    //         cout << result[p];
    //     }
    // }
    for(vector<int>::iterator it = result.begin() ; it != result.end(); ++it) {
        if(result.begin() != result.end() && it != prev(result.end())){
            cout << *it << ", ";
        } else {
            cout << *it;
        }
    }
    cout <<"] \n";
    for(vector<int>::iterator it2 = result2.begin() ; it2 != result2.end(); ++it2) {
        if(result2.begin() != result2.end() && it2 != prev(result2.end())){
            cout << *it2 << ", ";
        } else {
            cout << *it2;
        }
    }
    cout <<"] \n";
    for(vector<int>::iterator it3 = result3.begin() ; it3 != result3.end(); ++it3) {
        if(result3.begin() != result3.end() && it3 != prev(result3.end())){
            cout << *it3 << ", ";
        } else {
            cout << *it3;
        }
    }
    cout <<"] \n";
    for(vector<int>::iterator it4 = result4.begin() ; it4 != result4.end(); ++it4) {
        if(result4.begin() != result4.end() && it4 != prev(result4.end())){
            cout << *it4 << ", ";
        } else {
            cout << *it4;
        }
    }
    cout <<"] \n";
    return 0;
}