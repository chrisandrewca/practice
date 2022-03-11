/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int tiltDFS(struct TreeNode* root, int* tilt) {
    
    if (root == NULL) {
        return 0;
    }
    
    int l = tiltDFS(root->left, tilt);
    int r = tiltDFS(root->right, tilt);
    
    *tilt += abs(l - r);
    
    return l + r + root->val;
}

int findTilt(struct TreeNode* root){
    
    int tilt = 0;
    tiltDFS(root, &tilt);
    return tilt;
}
