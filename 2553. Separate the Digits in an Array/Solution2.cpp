#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--){
            int n = nums[i];
            while(n!=0){
                int digit = n%10;
                ans.push_back(digit);
                 n /= 10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    // Function to build vector from string
    vector<int> buildVector(string str) {
        if(str.length() == 0 || str[0] == 'N'){
            return {};
        }

        // creating vector of int to store from space separated string numbers
        vector<int> nums;

        istringstream iss(str);
        for(string str; iss >> str;) {
            nums.push_back(stoi(str));
        }

        return nums;
    }
};

int main()
{
    int t = 0;
    cout<<"Enter number of test cases: \n";
    cin >> t;
    while( t-- ) {
        string s;
        cout << "Enter Array : \n";
        getline(cin >> ws, s);
        
        Solution ob;
        vector<int> nums = ob.buildVector(s);

        vector<int> result = ob.separateDigits(nums);
        cout << "Separate digits : \n";// << ob.separateDigits(nums);
        cout<< "[ ";
        for(vector<int>::iterator it = result.begin() ; it != result.end(); ++it) {
            if(result.begin() != result.end() && it != prev(result.end())){
                cout << *it << ", ";
            } else {
                cout << *it;
            }
        }
        cout <<"] \n";
    }
    return 0;
}