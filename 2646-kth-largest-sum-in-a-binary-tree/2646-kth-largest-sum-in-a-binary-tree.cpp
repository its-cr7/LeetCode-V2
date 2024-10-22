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
#define ll long long
class Solution {
private:
    ll sums[100000] = {0};
    int maxLevel = 0;       

    void solve(TreeNode* root, int lvl) {
        if (!root) return;
        sums[lvl] += root->val;
        maxLevel = max(maxLevel, lvl);

        solve(root->left, lvl + 1);
        solve(root->right, lvl + 1);
    }

public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        solve(root, 0);
        sort(sums, sums + maxLevel + 1, greater<ll>());
        return (k > maxLevel + 1) ? -1 : sums[k - 1];
    }
};