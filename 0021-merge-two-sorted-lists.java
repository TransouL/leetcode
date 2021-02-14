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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		if(l1 == null && l2 == null) {
			return null;
		} else if(l1 == null) {
			return l2;
		} else if(l2 == null) {
			return l1;
		} 
		
    	ListNode current1 = l1;
    	ListNode current2 = l2;

		ListNode result;
    	if(l1.val <= l2.val) {
    		result = l1;
    		current1 = l1.next;
    	} else {
    		result = l2;
    		current2 = l2.next;
    	}
    	
    	ListNode current = result;
    	while(true) {
    		if(current1 == null) {
    			current.next = current2;
    			break;
    		} else if(current2 == null) {
    			current.next = current1;
    			break;
    		} else {
    			if(current1.val <= current2.val) {
    	    		current.next = current1;
    	    		current1 = current1.next;
    	    	} else {
    	    		current.next = current2;
    	    		current2 = current2.next;
    	    	}
                current = current.next;
    		}
    	}
    	
    	return result;
    }
}