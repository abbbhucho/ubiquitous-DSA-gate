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

class Solution{
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
public:
    vector<int> vec;

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
    
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    /**
     * @brief Two pointer approach
     * 
     * @param root 
     * @param k 
     * @return true 
     * @return false 
     */
    bool findTarget(TreeNode* root, int k) {
        inorder(root);

        int n = vec.size();

        int i = 0;
        int j = n - 1;

        while (i < j) {
            int sum = vec[i] + vec[j];

            if (sum == k)
                return true;
            else if (sum < k)
                i++;
            else if (sum > k)
                j--;
        }

        return false;
    }
/***
 * WRONG ANSWER FIGURE OUT WHY
    bool findTarget(TreeNode* root, int k) {
        if(!root->left && !root->right){
            return false;
        }
        int complement = k - root->val;
        while( root != NULL){
            if(root->val == complement){
                // return findTarget(root->right, );
                return true;
            }
            else if(root->val > complement){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return false;
    }
*/
};

int main()
{
    // std::cout << std::boolalpha << false << std::endl;
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin >> ws, s);
        int x;
        cin >> x;

        Solution ob;
        TreeNode* root = ob.buildTree(s);
        cout << std::boolalpha << ob.findTarget(root, x) << endl;
    }
    return 0;
}