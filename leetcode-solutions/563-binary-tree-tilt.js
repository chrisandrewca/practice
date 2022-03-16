/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var findTilt = function (root) {
    let tilt = 0;

    function findDiffDFS(node) {

        if (!node) {
            return 0;
        }

        let l = findDiffDFS(node.left);
        let r = findDiffDFS(node.right);

        tilt += Math.abs(l - r);

        return l + r + node.val;
    }

    findDiffDFS(root);

    return tilt;
};
