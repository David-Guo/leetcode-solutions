# Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.

For example,

    Given linked list: 1->2->3->4->5, and n = 2.
    
    After removing the second node from the end, the linked list becomes 1->2->3->5.

**Note:**

* Given n will always be valid.
* Try to do this in one pass. 

## 思路

last 指针向后移动 n 次后，pos 指针再随 last 向后移动，直到结束。

## My solution

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* last = head;
        ListNode* pos = head;
        if (last->next == NULL)
            return NULL;
        for (int i = 0 ; i < n; i++)
            last = last->next;
        if (last == NULL)
            return head->next;
        while (last->next != NULL) {
            last = last->next;
            pos = pos->next;
        }
        ListNode* temp = pos->next;
        pos->next = temp->next;
        delete temp;
        return head;
    }
```

