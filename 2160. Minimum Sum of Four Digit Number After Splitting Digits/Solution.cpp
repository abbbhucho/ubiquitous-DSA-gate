#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int minimumSum(int num) {
        int newNum[2];
        int digits[4] = {0};//units, tens, hundreds, thousands;
        // separate digits
        int i = 0;
        while(num > 0) {
            digits[i] = num%10;
            num = num/10;
            i++;
        }
        // sort the digits
        sort(std::begin(digits), std::end(digits));

        /**
         * @brief Greedy Approach
         * 1. Notice that the most optimal way to obtain the minimum possible sum using 4 digits is by summing up two 2-digit numbers.
         * 2. We can use the two smallest digits out of the four as the digits found in the tens place respectively.
         * 3. Similarly, we use the final 2 larger digits as the digits found in the ones place.
        */
        newNum[0] = digits[0]*10 + digits[2];
        newNum[1] = digits[1]*10 + digits[3];
        return newNum[0] + newNum[1];
    }
};

int main(){
    int input1 = 2932;
    int input2 = 4009;
    int input3 = 1123;

    Solution s;
    cout << "Sum : " << s.minimumSum(input3);
    return 0;
}