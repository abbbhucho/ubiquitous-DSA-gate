#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    vector<string> out;

    void dfs(TreeNode *root, string s)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL and root->right == NULL)
        {
            out.push_back(s + to_string(root->val));
        }
        dfs(root->left, s + to_string(root->val) + "->");

        dfs(root->right, s + to_string(root->val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {

        dfs(root, "");
        return out;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = nullptr;
    root->left->right = new TreeNode(5);
    root->right->left = nullptr;
    root->right->right = nullptr;
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;

    Solution s;
    vector<string> output;
    output = s.binaryTreePaths(root);

    for(auto i: output) {
        cout << i << "\n";
    }
    return 0;
}