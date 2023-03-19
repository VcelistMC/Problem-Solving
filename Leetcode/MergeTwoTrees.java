
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

    @Override
    public String toString() {
        return val+"";
    }
}

class MergeTwoTrees {
    
    public TreeNode merge(TreeNode n1, TreeNode n2, TreeNode parent, boolean isRight){
        if(n1 == null && n2 == null)
            return null;
        
        else if(n1 == null){
            n1 = new TreeNode(n2.val);
            if(parent != null){
                if(isRight)
                    parent.right = n1;
                else
                    parent.left = n1;
            }
        }

        else if(n2 != null)
            n1.val = n1.val + n2.val;
        else
            return n1;
        merge(n1.left, n2.left, n1, false);
        merge(n1.right, n2.right, n1, true);
        return n1;
    }


    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        root1 = merge(root1, root2, null, false);
        return root1;
    }
    public static void main(String[] args) {
        TreeNode root1 = null;
        TreeNode root2 = new TreeNode(1);
        // root1.left = new TreeNode(3);
        // root2.left = new TreeNode(1);
        // root1.right = new TreeNode(2);
        // root2.right = new TreeNode(3);
        // root1.left.left = new TreeNode(5);
        // root2.left.left = null;
        // root1.left.right = null;
        // root2.left.right = new TreeNode(4);
        // root2.right.right = new TreeNode(7);

        MergeTwoTrees trees = new MergeTwoTrees();
        trees.mergeTrees(root1, root2);
    }
}