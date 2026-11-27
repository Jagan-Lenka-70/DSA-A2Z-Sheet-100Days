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
int maxP = INT_MIN;
int maxPath(TreeNode* root){
    if(root == nullptr) return 0;
    int l = max(0,maxPath(root->left));
    int r = max(0,maxPath(root->right));
    maxP = max(maxP,root->val+l+r);
    return root->val+max(l,r);
}
    int maxPathSum(TreeNode* root) {
       
       maxPath(root);
        return maxP;
    }
};