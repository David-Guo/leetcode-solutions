# Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list.

## 思路

归并排序的指针实现。

## My solution

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *head = new ListNode(0);
        ListNode *pos = head;
        int temp;
        
        while(l1 && l2) {
            if (l1->val < l2->val) {
                temp = l1->val;
                l1 = l1->next;
            }
            else {
                temp = l2->val;
                l2 = l2->next;
            }
            pos->next = new ListNode(temp);
            pos = pos->next;
        }
        
        while(l1 != NULL) {
            pos->next = new ListNode(l1->val);
            pos = pos->next;
            l1 = l1->next;
        }
        
        while(l2 != NULL) {
            pos->next = new ListNode(l2->val);
            pos = pos->next;
            l2 = l2->next;
        }
        return head->next;
    }