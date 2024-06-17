#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,bool> isRepeated;
        vector<int> ans;
        for(auto num : nums) {
            auto finder = isRepeated.find(num);
            if(finder != isRepeated.end()) {
                isRepeated[num] = true;
            } else {
                isRepeated[num] = false;
            }
        }
        for (auto i = isRepeated.begin(); i != isRepeated.end(); i++) { 
            if(i->second == false) {
                ans.push_back(i->first);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}