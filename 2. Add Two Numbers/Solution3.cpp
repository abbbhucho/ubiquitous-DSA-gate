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

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1;
        ListNode *q = l2;
        bool carry_flag = false;
        int sum = 0;
        ListNode *lr = new ListNode();
        ListNode *r = lr;
        while (p != NULL || q != NULL)
        {
            sum = 0;
            if (p != NULL && q != NULL)
            {
                if (carry_flag)
                    sum++;
                sum += p->val + q->val;
                if (sum / 10 != 0)
                {
                    sum = sum % 10;
                    carry_flag = true;
                }
                else
                    carry_flag = false;
                r->val = sum;
                if (p->next != NULL || q->next != NULL)
                {
                    r->next = new ListNode();
                    r = r->next;
                }
                p = p->next;
                q = q->next;
            }
            else if (p == NULL)
            {
                if (carry_flag)
                    sum++;
                sum += q->val;
                if (sum / 10 != 0)
                {
                    sum = sum % 10;
                    carry_flag = true;
                }
                else
                    carry_flag = false;
                r->val = sum;
                if (q->next != NULL)
                {
                    r->next = new ListNode();
                    r = r->next;
                }
                q = q->next;
            }
            else
            {
                if (carry_flag)
                    sum++;
                sum += p->val;
                if (sum / 10 != 0)
                {
                    sum = sum % 10;
                    carry_flag = true;
                }
                else
                    carry_flag = false;
                r->val = sum;
                if (p->next != NULL)
                {
                    r->next = new ListNode();
                    r = r->next;
                }
                p = p->next;
            }
        }
        if (carry_flag)
        {
            r->next = new ListNode(1);
            r = r->next;
        }
        return lr;
    }
};
/**
 * @brief to build singly linked list from string space separated values as node->val
 * @param string str
 * @return ListNode
 */
ListNode *buildList(string str)
{
    if (str.length() == 0 || str[0] == 'N')
    {
        return nullptr;
    }

    // creating vector of strings
    // string splitting done by whitespaces
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
    {
        ip.push_back(str);
    }

    ListNode *l1 = new ListNode(stoi(ip[0]));
    ListNode *p = l1;
    for (int i = 1; i < ip.size(); i++)
    {
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
    while (t--)
    {
        string s1, s2;
        cout << "Enter linked list 1 as string with spaces , value range [0,9]\n";
        getline(cin >> ws, s1);
        ListNode *l1 = buildList(s1);

        cout << "Enter linked list 2 \n";
        getline(cin >> ws, s2);
        ListNode *l2 = buildList(s2);

        Solution s;
        ListNode *res = s.addTwoNumbers(l1, l2);

        while (res != nullptr)
        {
            cout << res->val << " ";
            res = res->next;
        }
        cout << "\n";
    }

    return 0;
}