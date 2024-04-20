#include<bits/stdc++.h>
#include <random>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n, mid;
        while( start <= end ) {
            mid = start + ((end - start) / 2);
            if( isBadVersion(mid) ) {
                // all version after mid are bad
                end = mid - 1;
            } else {
                // if at halfway version is good then find over higher half to know which version atmost is bad
                start = mid +1;
            }
        }
        return start;
    }

    bool isBadVersion(int n) {
        // In modern C++ there is a dedicated way to generate random booleans - via a bernoulli distribution:

        static std::default_random_engine generator(std::random_device{}());
        // With p = 0.5 you get equal probability for true and false
        static std::bernoulli_distribution distribution(0.5);
        return distribution(generator);
    }
};

int main()
{
    int n = 5;
    Solution ob;
    cout << "bad version start from : " << ob.firstBadVersion(n);
    return 0;
}