public class ReverseLinkedList {
    public ListNode reverseList(ListNode head) {
        ListNode newHead =  null;
        while(head != null){
            ListNode newerHead = new ListNode(head.val);
            newerHead.next = newHead;
            newHead = newerHead;
            head = head.next;
        }
        return newHead;
    }
}
