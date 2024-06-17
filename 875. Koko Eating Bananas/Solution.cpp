#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // we have to find min rate of bananas per hour feasible
        int low = 0, high = maxInPile(piles), mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(rateHrCount(piles, mid) <= h) {
                // if takes more time than given
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
    // find rate of bananas to eat per hour for the whole array sum 
    int rateHrCount(vector<int> &piles, int hr){
        int rate = 0;
        // if(hr == 0) return INT_MAX;  for special case where all the values of piles are always less than hr
        for(int pile : piles) {
            rate += ceil((float)pile / hr);
        }
        return rate;
    }
    // find the max banana pile of piles
    int maxInPile(vector<int> &piles)
    {
        int maxPile = INT_MIN;
        for(int pile : piles) {
            maxPile = max(maxPile, pile);
        }
        return maxPile;
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