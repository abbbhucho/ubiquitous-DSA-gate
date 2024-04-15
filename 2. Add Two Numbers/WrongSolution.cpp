#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    int pow(int a, int b) { 
        if (b == 0) 
            return 1; 
        int answer = a; 
        int increment = a; 
        int i, j; 
        for(i = 1; i < b; i++) { 
            for(j = 1; j < a; j++) { 
                answer += increment; 
            } 
            increment = answer; 
        }
        return answer; 
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0, num2 = 0, sum = 0;
        ListNode* q = l1;
        ListNode* r = l2;
        for(int i=0; q != nullptr; i++) {
            num1 += q->val * this->pow(10, i);
            q = q->next;
        }
        for(int j=0; r != nullptr; j++) {
            num2 += r->val * this->pow(10, j);
            r= r->next;
        }
        sum = num1+num2;
        ListNode *lr = new ListNode(sum%10);
        ListNode *p = lr;
        sum = sum/10;
        while(sum != 0){
            int n  = sum%10;
            sum = sum/10;
            p->next = new ListNode(n);
            p = p->next;
        }
        // p->next = nullptr;
        return lr;
    }
};
ListNode * buildList(string str) {
    if(str.length() == 0 || str[0] == 'N') {
        return nullptr;
    }

    // creating vector of strings
    // string splitting done by whitespaces
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) {
        ip.push_back(str);
    }

    ListNode* l1 = new ListNode(stoi(ip[0]));
    ListNode* p = l1;
    for(int i=1; i < ip.size(); i++){
        p->next = new ListNode(stoi(ip[i]));
        p = p->next;
    }
    return l1;
}

int main()
{
    /*ListNode *n1 = new ListNode(2);
    n1->next = new ListNode(4);
    n1->next->next = new ListNode(3);

    ListNode *n2 = new ListNode(5);
    n2->next = new ListNode(6);
    n2->next->next = new ListNode(4);
    */
    int t;
    cout << "Enter testcases: \n";
    cin >> t;
    while(t--){
        string s1, s2;
        cout << "Enter linked list 1 as string with spaces , value range [0,9]\n";
        getline(cin >> ws, s1);
        ListNode* l1 = buildList(s1);

        cout << "Enter linked list 2 \n";
        getline(cin >> ws, s2);
        ListNode* l2 = buildList(s2);

        Solution s;
        ListNode *res = s.addTwoNumbers(l1, l2);

        while(res != nullptr){
            cout << " " << res->val;
            res = res->next;
        }
        cout << "\n";
    }

    return 0;
}