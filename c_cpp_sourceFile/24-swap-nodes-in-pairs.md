# 24. Swap Nodes in Pairs

> Given a linked list, swap every two adjacent nodes and return its head.

> For example,
> Given 1->2->3->4, you should return the list as 2->1->4->3.

> Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 


```cpp
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *p1 = head;
        ListNode *p0 = head;
        ListNode *temp;
        ListNode *pre;
        if (p1->next == NULL)
            return head;
        
        p1 = p1->next;
        p0->next = p1->next;
        p1->next = p0;
        temp = p1;
        p1 = p0;
        p0 = temp;
        head = p0;
        // pre 记忆 p0 的前躯
        pre = p1;
        while(p0->next->next && p1->next->next) {
            p1 = p1->next->next;
            p0 = p0->next->next;
            
            p0->next = p1->next;
            p1->next = p0;
            pre->next = p1;
            temp = p1;
            p1 = p0;
            p0 = temp;
            pre = p1;

        }
        return head;
    }

```