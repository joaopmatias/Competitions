/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;

bool checkforward(ListNode* head, int k){
    int i, j;
    ListNode * current;
    current = head -> next;
    for(i = 0; i < k && current != NULL ; i++) current = current -> next;
    if(i == k) return true;
    else return false;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i, j;
        if(k == 1) return head;
        ListNode ans(0), * current, * prevblock, * tail, * t;
        ans.next = head;
        prevblock = &ans;
        while(checkforward(prevblock, k)){
            tail = prevblock -> next;
            t = tail;
            current = tail -> next;
            for(i = 0; i < k - 1 ; i++){
                tail -> next = current -> next;
                current -> next = t;
                t = current;
                current = tail -> next;
            }
            prevblock -> next = t;
            prevblock = tail;
            
        }
        return ans.next;
    }
};