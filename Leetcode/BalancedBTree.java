class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class BalancedBTree {
    public int height(TreeNode node){
        if (node == null) return 0;
        return Math.max(height(node.left), height(node.right)) + 1;
    }
    public boolean isBalanced(TreeNode root) {
        if(root == null) return true;
        int rH = height(root.left);
        int lH = height(root.right);

        return isBalanced(root.left) 
            && isBalanced(root.right) 
            && (Math.abs(rH - lH) <= 1);

    }
}
