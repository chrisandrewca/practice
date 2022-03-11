/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {

    private int tilt = 0;

    private int tiltDFS(TreeNode node) {
        
        if (node == null) {
            return 0;
        }
        
        int l = tiltDFS(node.left);
        int r = tiltDFS(node.right);
        
        tilt += Math.Abs(l - r);
        
        return l + r + node.val;
    }

    public int FindTilt(TreeNode root) {
        tiltDFS(root);
        return tilt;
    }
}
