#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s = 0, e = letters.size() - 1, mid;
        if (letters[e] <= target)
            // taking advantage of the fact that letters are in non dec order
            return letters[0];
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (letters[mid] > target)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return letters[s];
        // By separating the above if, we remove the case of s going beyond array index
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