/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode sum=new ListNode();
        add(0,l1,l2,sum);
        return sum.next;
    }
    public void add(int carry,ListNode l1,ListNode l2, ListNode sum){
        if(l1==null && l2==null){
            if(carry==1){
                sum.next=new ListNode(1);
                // sum.next.val=1;
                sum=sum.next;
            }
            return;
        }
        
        if(l1==null && l2!=null){
            while(l2!=null){
                sum.next=new ListNode();
                sum.next.val=(l2.val+carry)%10;
                sum=sum.next;
                if((l2.val+carry)>9)
                    carry=1;
                else
                    carry=0;
                l2=l2.next;
            }
            if(carry==1){
                sum.next=new ListNode(1);
                // sum.next.val=1;
                sum=sum.next;
            }
            return;
        }
        if(l1!=null && l2==null){
            while(l1!=null){
                sum.next=new ListNode();
                sum.next.val=(l1.val+carry)%10;
                sum=sum.next;
                if((l1.val+carry)>9)
                    carry=1;
                else
                    carry=0;
                l1=l1.next;
            }
            if(carry==1){
                sum.next=new ListNode(1);
                // sum.next.val=1;
                sum=sum.next;
            }
            return;
        }
        int s=l1.val+l2.val+carry;
        if(s>9)
            carry=1;
        else
            carry=0;
        sum.next=new ListNode();
        sum.next.val=s%10;
        sum=sum.next;
        add(carry,l1.next,l2.next,sum);
        return;
        
    }
}