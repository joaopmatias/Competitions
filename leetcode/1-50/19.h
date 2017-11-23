/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



class Solution {
public:

    int lengthNode(ListNode * head){
        int i;
        ListNode * t = head;
        if(head == NULL) return 0;
        for(i = 1; t -> next != NULL; i++) t = t-> next;
        return i;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i, j, lenhead = lengthNode(head);
        ListNode * t = head;
        if(n == lenhead) return head -> next;
        for(j = 0; j < lenhead - n - 1; j++) t = t->next;
        t -> next = t-> next -> next;
        return head;
    }
};