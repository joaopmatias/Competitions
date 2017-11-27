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
    ListNode* swapPairs(ListNode* head) {
        ListNode ans(0), *current, * pre1st, * pre2nd;
        if(head == NULL || head -> next == NULL) return head;        
        pre1st = head;
        current = &ans;
        while(pre1st != NULL){
            pre2nd = pre1st -> next;
            if(pre2nd == NULL){
                current -> next = pre1st;
                current = ans.next;
                return current;
            }
            else{
                current -> next = pre2nd;
                current = pre1st;
                pre1st = pre2nd -> next;
                pre2nd -> next = current;
            }
        }
        current -> next = NULL;
        current = ans.next;
        return current;        
    }
};