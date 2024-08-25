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
class Solution {
public:
    void PostOrder(TreeNode* p,vector<int>&v){
        if(p==nullptr)return;
        PostOrder(p->left,v);
        PostOrder(p->right,v);
        v.push_back(p->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        PostOrder(root,v);
        return v;
    }
};