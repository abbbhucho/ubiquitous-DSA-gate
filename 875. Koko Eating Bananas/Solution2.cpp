#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0];
        int n = piles.size();
        for (int i = 0; i < n; i++)
            maxi = max(maxi, piles[i]);
        int low = 1, high = maxi;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            long long int time = 0;
            for (int j = 0; j < n; j++)
                time += ceil((double)(piles[j]) / (double)(mid));
            if (time <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    // int t;
    // cout << "Enter number of test cases\n";
    // cin >> t;
    // while(t) {

    // }
    vector<int> piles1 = {3,6,7,11};int h1 = 8;
    vector<int> piles2 = {30,11,23,4,20};int h2 = 5;
    vector<int> piles3 = {30,11,23,4,20};int h3 = 6;
    vector<int> piles4 = {312884470}; int h4 = 968709470;
    
    Solution obj;
    // cout << obj.minEatingSpeed(piles1, h1) << "\n";
    // cout << obj.minEatingSpeed(piles2, h2) << "\n";
    // cout << obj.minEatingSpeed(piles3, h3) << "\n";
    cout << obj.minEatingSpeed(piles4, h4) << "\n";
    return 0;
}