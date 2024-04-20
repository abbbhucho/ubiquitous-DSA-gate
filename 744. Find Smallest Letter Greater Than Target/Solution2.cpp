#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/**
 * @brief Time complexity : O(n)
 * 
 * @param letters 
 * @param target 
 * @return char 
 */
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        for (int i = 0; i < letters.size(); i++)
        {
            if (letters[i] > target)
            {
                ans = letters[i];
                break;
            }
        }
        return ans;
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