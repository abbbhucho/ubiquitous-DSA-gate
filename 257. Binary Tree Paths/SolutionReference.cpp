#include <bits/stdc++.h>
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
class Solution
{
public:
    // Utility function to create a new Tree Node
    TreeNode *newNode(int val)
    {
        TreeNode *temp = new TreeNode;
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
    // Function to Build Tree
    TreeNode *buildTree(string str)
    {
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
        TreeNode *root = newNode(stoi(ip[0]));

        // Push the root to the queue
        queue<TreeNode *> queue;
        queue.push(root);

        // Starting from the second element
        int i = 1;
        while (!queue.empty() && i < ip.size())
        {

            // Get and remove the front of the queue
            TreeNode *currNode = queue.front();
            queue.pop();

            // Get the current node's value from the string
            string currVal = ip[i];

            // If the left child is not null
            if (currVal != "N")
            {

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
            if (currVal != "N")
            {

                // Create the right child for the current node
                currNode->right = newNode(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void dfsFindPath(vector<string> &res, string cur, TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            cur += to_string(root->val);
            res.push_back(cur);
            cur.pop_back();
            return;
        }
        cur += to_string(root->val);
        cur += "->";

        if (root->left != nullptr)
            dfsFindPath(res, cur, root->left);
        if (root->right != nullptr)
            dfsFindPath(res, cur, root->right);

        cur.pop_back();
        cur.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        string cur;
        dfsFindPath(res, cur, root);
        return res;
    }
};

int main()
{
    string s;
    getline(cin >> ws, s);

    Solution ob;
    TreeNode *root = ob.buildTree(s);
    vector<string> output;
    output = ob.binaryTreePaths(root);

    for (auto i : output)
    {
        cout << i << "\n";
    }
    return 0;
}