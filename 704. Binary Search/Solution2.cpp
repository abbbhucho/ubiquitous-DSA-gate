#include<bits/stdc++.h>
using namespace std;

int init = [] {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ofstream out("user.out");
  cout.rdbuf(out.rdbuf());
  for (string s; getline(cin, s); cout << '\n') {
    string t;
    getline(cin, t);
    int tar = stoi(t);
    for (int i = 0, _i = 1, _n = s.length(); _i < _n; ++i, ++_i) {
      bool _neg = 0;
      if (s[_i] == '-')
        ++_i, _neg = 1;
      int v = s[_i++] & 15;
      while ((s[_i] & 15) < 10)
        v = v * 10 + (s[_i++] & 15);
      if (_neg)
        v = -v;
      if (v == tar) {
        cout << i;
        goto next;
      }
      if (v > tar)
        break;
    }
    cout << -1;
  next:;
  }
  exit(0);
  return 0;
}();



class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);
        int st = 0, en = nums.size()-1, mid;
        while (st <= en) {
            mid = st + ((en-st)>>1);
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                st = mid+1;
            } else {
                en = mid-1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> num1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;

    vector<int> num2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;

    vector<int> num3 = {5};
    int target3 = 5;
    Solution ob;
    int found = ob.search(num3, target3);
    if(found == -1 ) {
        cout << "not found : " << endl; 
    } else cout << "found at index : " << found << endl; 

    return 0;
}