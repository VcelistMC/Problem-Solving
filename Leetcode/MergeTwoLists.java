
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class MergeTwoLists {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null && list2 == null)
            return null;
        ListNode mergedList = new ListNode();
        ListNode curr = mergedList;
        ListNode prev = mergedList;
        while(list1 != null && list2 != null){
            if(list1.val < list2.val){
                curr.val = list1.val;
                list1 = list1.next;
            }
            else{
                curr.val = list2.val;
                list2 = list2.next;
            }
            prev = curr;
            curr.next = new ListNode();
            curr = curr.next;
        }

        while(list1 != null){
            curr.val = list1.val;
            list1 = list1.next;
            prev = curr;
            curr.next = new ListNode();
            curr = curr.next;
        }
        
        while(list2 != null){
            curr.val = list2.val;
            list2 = list2.next;
            prev = curr;
            curr.next = new ListNode();
            curr = curr.next;
        }
        prev.next = null;
        return mergedList;
    }
}