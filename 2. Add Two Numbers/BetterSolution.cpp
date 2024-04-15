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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(0);
        ListNode* s = sum; 
        while (s) {
            if (l1) {
                s->val += l1->val; 
                l1 = l1->next; 
            }
            if (l2) {
                s->val += l2->val; 
                l2 = l2->next; 
            }
            if (s->val >= 10) {
                s->val -= 10; 
                s->next = new ListNode(1); 
            } else if (l1 || l2) {
                s->next = new ListNode(0); 
            }
            s = s->next; 
        }
        return sum; 
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

/**
 * @brief Other solutions
 * 
 */
/*
ListNode* dummy=new ListNode();
ListNode* temp = dummy;
int carry= 0;
while(l1 != NULL || l2 != NULL || carry == 1){
    int sum =0;
    if(l1 != NULL){
        sum += l1->val;
        l1 = l1->next;
    }
    if(l2 != NULL){
        sum += l2->val;
        l2 = l2->next;
    }
    sum += carry;
    carry = sum/10;
    ListNode* node = new ListNode(sum%10);
    temp->next = node;
    temp = temp->next;
}
return dummy->next;
*/

/**
 * @brief Other SOlution 2
 * 
 */
/*
ListNode* newList = new ListNode(0);
ListNode* temp = newList;
int carry = 0;
while (l1 || l2) {
    int x = ((l1 != nullptr) ? l1->val : 0) + ((l2 != nullptr) ? l2->val : 0) + carry;
    carry = x / 10;
    temp->next = new ListNode(x % 10);
    temp = temp->next;

    if (l1) l1 = l1->next;
    if (l2) l2 = l2->next;
}

if (carry == 1) {
    temp->next = new ListNode(carry);
}

return newList->next;
*/

/**
 * @brief Other SOlution 3
 * 
 */
/*
int r = 0;  
ListNode *l = nullptr, *root = nullptr;
while (true) {
    int d = r;
    if (l1) d += l1->val;
    if (l2) d += l2->val;
    if (d == 0 && l1 == nullptr && l2 == nullptr) break;
    r = d / 10;
    d %= 10;

    if (l) {
        l->next = new ListNode(d);
        l = l->next;
    } else {
        root = l = new ListNode(d);
    }

    if (l1) l1 = l1->next;
    if (l2) l2 = l2->next;
}
return root;
*/