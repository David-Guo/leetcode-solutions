#2. Add Two Numbers

You are given two linked lists representing two non-negative numbers.

The digits are stored in reverse order and each of their nodes contain a single digit. 

Add the two numbers and return it as a linked list.

**Input:**  (2 -> 4 -> 3) + (5 -> 6 -> 4)

**Output:**  7 -> 0 -> 8

My solution: 

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head;
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    head = l3;
    int carry = 0;
    
    while (l1 || l2 || carry != 0) {
        int sum = 0;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
		carry = sum/10;
		l3->val = sum%10;
		
		if (l1 || l2 || carry != 0) {
		    l3->next = malloc(sizeof(struct ListNode));
		    l3 = l3->next;
		    l3->next = NULL;
		}
    }
    
	return head;
}
```