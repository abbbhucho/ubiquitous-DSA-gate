#include<bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* newNode(int val){
        ListNode* node = new ListNode();
        node->val = val;
        node->next = NULL;

        return node;
    }
public:
    ListNode* formLinkedList(string str) {
        // Corner Case
        if (str.length() == 0 || str[0] == 'N')
            return NULL;

        // Creating vector of strings from input
        // string after spliting by space
        vector<string> ip;

        istringstream iss(str);
        for (string str; iss >> str;)
            ip.push_back(str);

        ListNode* head = newNode(stoi(ip[0]));

        // push head to queue
        queue<ListNode*> queue;
        queue.push(head);

        // starting from second element
        int i=1;
        while(!queue.empty() && i < ip.size()) {

            // Get and remove the front of queue
            ListNode* currNode = queue.front();
            queue.pop();
            // Get the current node's value
            string currVal = ip[i];
            // if the node is not null given as 'N' in user input 
            if(currVal != "N") {
                // create the next node for the current value
                currNode->next = newNode(stoi(currVal));
                // push the node to the queue
                queue.push(currNode->next);
            }
            i++;
        }
        return head;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head, *q = head;
        if(head == NULL) {
            return NULL;
        }
        if(head->next == NULL) {
            return head;
        }
        while(q != nullptr || q->next != nullptr) {
            if( q->next == nullptr) {
                // has one center
                return p;
            } else if( q->next != nullptr && q->next->next == nullptr ){
                // more than one center
                return p->next;
            }
            q = q->next->next;
            p = p->next;
        }
        return p;
        /**
         * @brief Solution 1 
         * 
         ListNode* middleNode(ListNode* head) {
            ListNode *fast = head;
            ListNode *slow = head;
            while(fast != NULL && fast->next != NULL){
                fast=fast->next->next;
                slow=slow->next;
            }
            return slow;
        }
         */
        /**
         * @brief Solution 2
         ListNode* middleNode(ListNode* head) {
            int count=0;
            ListNode* tort=head,*hare=head;
            while(hare->next){
                tort=tort->next;
                hare=hare->next;
                if(hare->next)hare=hare->next;
            }
            return tort;
        }
        */
    }

};

int main()
{
    int t;
    cout<<"enter number of testcases\n";
    cin>>t;
    cout<<"\n";
    while(t--){
        string s;
        cout << "Enter ll values with spaces\n";
        getline(cin >> ws, s);
        Solution obj;
        struct ListNode* head = obj.formLinkedList(s);
        struct ListNode* mid = obj.middleNode(head);
        int val = mid != nullptr ? mid->val : 0;
        cout << "mid node value : " << val << "\n";
    }
    return 0;
}