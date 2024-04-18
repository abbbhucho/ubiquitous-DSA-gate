#include<bits/stdc++.h>

using namespace std;
/**
 * @brief Fastest Solution
 * 
 */

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
    void getLeaves(TreeNode* root, set<int>& leaves){
        if(root == nullptr)
             return;

        if( (root->left == nullptr) && (root->right == nullptr) )
             leaves.insert(root->val);
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    } 

    void getsum(TreeNode* root, int& sum){
        if(root == nullptr)
             return;

        //cout<< "Current root node is "<< root->val;
        if( root->left != nullptr  ){
            //cout<< "\t and its left child node is "<< root->left->val;
            //if( (leaves.find(root->left->val) != leaves.end()) && ( (root->left->left == nullptr)  && (root->left->right == nullptr) )  ){
            if(  (root->left->left == nullptr)  && (root->left->right == nullptr)  ){
                //cout<<" Adding "<< root->left->val << " to the sum"<<endl; 
                sum+= root->left->val;
            }
        }

        getsum(root->left,  sum);
        getsum(root->right, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {

        int sum = 0;
        getsum(root, sum);
        cout<< "The sum of left leaves is "<< sum<<endl;

        //for(auto it = leaves.begin(); it != leaves.end(); it++)
        //   cout<< *it << ", ";

        return sum;
        
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