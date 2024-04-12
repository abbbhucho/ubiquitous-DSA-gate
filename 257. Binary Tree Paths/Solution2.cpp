/**
 * WRONG SOLUTION
 * WRONG SOLUTION
 * WRONG SOLUTION 
 * WRONG SOLUTION
 * @date 2024-04-12
 * 
 * WRONG SOLUTION
 * 
 */
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
public:
    // Utility function to create a new Tree Node
    TreeNode* newNode(int val) {
        TreeNode* temp = new TreeNode;
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
    // Function to Build Tree
    TreeNode* buildTree(string str) {
        // Corner Case
        if (str.length() == 0 || str[0] == 'N')
            return NULL;

        // Creating vector of strings from input
        // string after spliting by space
        vector<string> ip;

        istringstream iss(str);
        for (string str; iss >> str;)
            ip.push_back(str);
                                                    
        // Create the root of the tree
        TreeNode* root = newNode(stoi(ip[0]));

        // Push the root to the queue
        queue<TreeNode*> queue;
        queue.push(root);

        // Starting from the second element
        int i = 1;
        while (!queue.empty() && i < ip.size()) {

            // Get and remove the front of the queue
            TreeNode* currNode = queue.front();
            queue.pop();

            // Get the current node's value from the string
            string currVal = ip[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = newNode(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= ip.size())
                break;
            currVal = ip[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = newNode(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        /**
         * @brief WRONG SOLUTION
         * WRONG SOLUTION
         */
        TreeNode *t = root;
        string op = "";
        vector<string> output;
        stack<TreeNode *> stk;
        vector<TreeNode *> avail;
        int num_of_nodes = numberOfNodes(root);
        while(num_of_nodes != avail.size()){

            while(t->left != nullptr || t->right != nullptr) {
                if(t->left != NULL) {
                    avail.push_back(t);
                    stk.emplace(t);
                    t = t->left;
                } else if(t->right != NULL) {
                    avail.push_back(t);
                    stk.emplace(t);
                    t = t->right;
                }
            }
            if((t->left == NULL && t->right == NULL) && avail.end() == find(avail.begin(), avail.end(), t)){
                avail.push_back(t);
                TreeNode *q = t;
                while(!stk.empty()) {
                    // non root keys push
                    op.insert(0, "->"+to_string(q->val));

                    q = stk.top();
                    stk.pop();
                    if(stk.empty())
                        t = q;
                }
                if (q == root) 
                    op.insert(0, to_string(q->val));

                output.push_back(op);
            } else {
                if(!stk.empty()){
                    t = stk.top();
                    stk.pop();
                }
            }
        }
        return output;
    }

    int numberOfNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);   
    }
};

int main()
{
    string s;
    getline(cin >> ws, s);

    Solution ob;
    TreeNode* root = ob.buildTree(s);
    vector<string> output;
    output = ob.binaryTreePaths(root);

    for(auto i: output) {
        cout << i << "\n";
    }
    return 0;
}