#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int countEven(int num) {
        const int number = num;
        int sum = 0;
        while(num != 0){
            sum += (num%10);
            num = num / 10;
        }
        return sum % 2 == 0 ? number / 2 : (number-1) / 2;
    }
};

int main(){
    int num, t = 0;
    cout<<"Enter number of test cases\n";
    cin >> t;
    while(t--){
        cout<<"Enter number:  \n";
        cin >> num;
        Solution ob;
        cout << "even sum for all its digit count : " << ob.countEven(num) << endl;
    }

    return 0;
}