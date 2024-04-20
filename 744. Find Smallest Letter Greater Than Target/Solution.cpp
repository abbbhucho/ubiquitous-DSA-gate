#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0, mid, end = letters.size() -1;
        int lub; // least upper bound char index

        while ( start <= end )
        {
            mid = start + ((end-start)/2);
            if(letters[mid] == target) {
                // given that letters array is in non-dec order so can be same, so finding upper bound of same chars + 1
                start = mid+1;
                lub = start; 
            }
            else if(letters[mid] < target) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        if(start <= (letters.size() -1) && letters[start] >= target) {
            lub = start;
            return letters[lub];
        } else {
            return letters[0];
        }
    }
};

int main()
{
    vector<char> letters1 = { 'c', 'f', 'j' };
    char target1 = 'a';
    char target2 = 'c';

    vector<char> letters2 = { 'x', 'x', 'y', 'y'};
    char target3 = 'z';

    Solution s;
    cout << "1st test case : " << s.nextGreatestLetter(letters1, target1) <<endl;

    cout << "2nd test case : " << s.nextGreatestLetter(letters1, target2) <<endl;

    cout << "3rd test case : " << s.nextGreatestLetter(letters2, target3) <<endl;
    return 0;
}