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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * t1 = l1, * t2 = l2, * ans, * current;
        if(t1 == NULL) return t2;
        else if(t2 == NULL) return t1;
        else if(t1 -> val < t2 -> val){
            ans = t1;
            t1 = t1 -> next;
        }
        else{
            ans = t2;
            t2 = t2 -> next;
        }
        current = ans;
        while(t1 != NULL && t2 != NULL){
            if(t1 -> val < t2 -> val){
                current -> next = t1;
                current = t1;
                t1 = t1 -> next;                
            }
            else {
                current -> next = t2;
                current = t2;
                t2 = t2 -> next;
            }
        }
        if(t1 == NULL) current -> next = t2;
        else current -> next = t1;
        return ans;        
    }
};