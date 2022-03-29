/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root==null) return new ArrayList<>();
        
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> temp = new LinkedList<>();
        
        temp.add(root);
        while(!temp.isEmpty()) {
            
            int n = temp.size(); 
            List<Integer> tmp = new ArrayList<>(); 
            while(n-- != 0) {
                TreeNode here = temp.remove(); 
                tmp.add(here.val); 
                // temp.pop(); 
                
                if(here.left != null) temp.add(here.left);
                if(here.right != null) temp.add(here.right); 
            }
            res.add(tmp); 
            
        }   
        
        return res; 
        
    }
}