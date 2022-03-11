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
int findDiffDFS(TreeNode* node, int& tilt) {

    if (node == NULL) {
        return 0;
    }

    int l = findDiffDFS(node->left, tilt);
    int r = findDiffDFS(node->right, tilt);

    tilt += abs(l - r);

    return l + r + node->val;
}

int findTilt(TreeNode* root) {

    int tilt = 0;
    findDiffDFS(root, tilt);
    return tilt;
}
