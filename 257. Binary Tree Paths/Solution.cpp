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
    vector<string> binaryTreePaths(TreeNode* root) {
        TreeNode *t = root;
        vector<string> output;
        string op = "";
        stack<TreeNode *> st;
        while((t->left != NULL || t->right != NULL) || !st.empty()){
            t == root ? op.append(to_string(t->val)) : op.append("->" + to_string(t->val));
            if(t->left != NULL){
                st.emplace(t);
                t = t->left;
            } else if(t->right != NULL) {
                st.emplace(t);
                t = t->right;
            } else {
                output.push_back(op);
                TreeNode *temp = t;
                t = st.top();
                if( t->left == temp) {
                    t->left = NULL;
                    temp = NULL;
                    op.erase(op.end()-3);
                } else if(t->right == temp) {
                    t->right == NULL;
                    temp = NULL;
                    op.erase(op.end()-3);
                }
                st.pop();
                TreeNode *p = st.top();
                op.erase(op.end()-3);
                // if(t->right != NULL) {
                //     st.emplace(t);     
                //     t = t->right;
                // } else {

                // }
            }
        }
    }
};

int main()
{

    return 0;
}