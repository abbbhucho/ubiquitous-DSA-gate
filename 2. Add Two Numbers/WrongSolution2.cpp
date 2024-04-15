/**
 * @file Solution2.cpp
 * @approach 2
 * @brief 
 * @version 0.1
 * @date 2024-04-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // traverse to last node l1 and mark i places
        ListNode *p = l1;
        ListNode *q = l2;
        int i = 0, j = 0;
        stack<ListNode*> stk1;
        stack<ListNode*> stk2;
        
        while(p->next != NULL) {
            stk1.emplace(p);
            p = p->next;
            i++;
        }
        // stk1.emplace(p);
        // traverse to last node l2 and mark j places
        while(q->next != NULL) {
            stk2.emplace(q);
            q = q->next;
            j++;
        }
        // stk2.emplace(q);
        // for loop for a new linked list if out of i and j which is bigger start with that
        // then traverse backwards till i, j matches then add both of them checking carry 
        // from previous step carry can be 1 or 0 as val range given is 0 - 9
        bool carry = false, is_first_node = false;
        ListNode* lr = nullptr;
        is_first_node = true;
        while( i >= 0 && j >= 0) {
            int val = 0;
            if (carry) {
                val++;
            }
            if(i == j) {
                if(!is_first_node){
                    if(!(stk1.empty()))
                        p = stk1.top();
                    if(!stk2.empty())
                        q = stk2.top();
                    stk1.pop();
                    stk2.pop();
                }
                val += p->val + q->val;
                // check for carry 
                if(val / 10 != 0) {
                    carry = true;
                    val = val%10;
                }
                i--;j--;
                
            } else if(i < j) {
                val += q->val;
                j--;
                if(!is_first_node){
                    if(!stk2.empty()) q = stk2.top();
                    stk2.pop();
                }
            } else {
                val += p->val;
                i--;
                if(!is_first_node){
                    if(!stk1.empty()) p = stk1.top();
                    stk1.pop();
                }
            }
            ListNode* r;
            if(is_first_node){
                lr = new ListNode(val);
                is_first_node = false;
                r = lr;
            } else {
                r->next = new ListNode(val);
                r = r->next;
            }
        }
        return lr;
    }
};
/**
 * @brief to build singly linked list from string space separated values as node->val 
 * @param string str
 * @return ListNode 
 */
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