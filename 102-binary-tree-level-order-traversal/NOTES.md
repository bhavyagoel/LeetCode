```java
class Solution {
public List<List<Integer>> levelOrder(TreeNode root) {
if(root == null) return new ArrayList<>();
List<List<Integer>> ans = new ArrayList<>() ;
ArrayList<Integer>miniAns  = new ArrayList<Integer>();
Queue<TreeNode>q = new LinkedList<TreeNode>();
q.add(root);
while(q.size() > 0){
int k = q.size();
for(int i=0 ; i < k ; i++){
TreeNode fr = q.remove();
if(fr != null ) miniAns.add(fr.val);
if(fr.left != null) q.add(fr.left);
if(fr.right != null) q.add(fr.right);
}
ans.add(new ArrayList<>(miniAns));
miniAns.clear();
}
return ans;
}
}
```
​