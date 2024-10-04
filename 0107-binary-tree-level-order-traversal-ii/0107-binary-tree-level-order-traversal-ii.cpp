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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        vector<int> curr;
        q.push(root);
        q.push(NULL); 
        while(!q.empty()){
            TreeNode *first = q.front();
            q.pop();
            if(first == NULL){
                ans.push_back(curr);
                curr = {};
                if(q.size() > 0){
                    q.push(NULL);
                }
            }
            else{
                curr.push_back(first -> val);
                if(first->left){
                    q.push(first->left);
                }
                if(first->right){
                    q.push(first->right);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};