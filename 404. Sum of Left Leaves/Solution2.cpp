#include<bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Utility function to create a new Tree Node
    TreeNode* newNode(int val) {
        TreeNode* temp = new TreeNode;
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
    TreeNode* buildTree(string str) {
        // corner case
        if(str.length() == 0 && str[0] == 'N') {
            return NULL;
        }
        // creating vector of strings
        // string after splitting by space
        vector<string> ip;

        istringstream iss(str);
        for(string str; iss >> str;)
            ip.push_back(str);

        // create the root of the tree
        TreeNode* root = new TreeNode(stoi(ip[0]));

        // push the root to the queue
        queue<TreeNode*> queue;
        queue.push(root);

        // starting from the second element
        int i = 1;
        while (!queue.empty() && i < ip.size()) {

            // get and remove from the front of the queue
            TreeNode* currNode = queue.front();
            queue.pop();

            // Get the current node's value from the string
            string currValue = ip[i];

            if(currValue != "N") {
                
                // create the left child for the current node
                currNode->left = newNode(stoi(currValue));
                // push it to the queue
                queue.push(currNode->left);
            }
            // For the right child
            i++;
            if( i >= ip.size()) {
                break;
            }
            currValue = ip[i];

            // If the right child is not NULL
            if( currValue != "N") {
                // create the right child of the current Node
                currNode->right = newNode(stoi(currValue));

                // Push it to the Queue
                queue.push(currNode->right);
            }
            i++;
        }

        return root;
    }
    int sumOfLeftLeaves(TreeNode *root, bool left = false)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (left && root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right);
    }
};

int main()
{
    int t = 0;
    cout << "Enter number of testcases: \n";
    cin >>t;
    while(t--){
        string s;
        cout << "Enter the tree elements: \n";
        getline(cin >> ws, s);
        Solution ob;
        TreeNode* root = nullptr;
        root = ob.buildTree(s);

        cout << "sum of left childs:" << ob.sumOfLeftLeaves(root);
        cout << "\n";
    }
    return 0;
}