#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;
 
 
 struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans, * a = l1, * b = l2, *c;
        int jump = 0;
        int i, j, k;
        
        i = 0;
        j = 0;
        if(a != NULL){
            i = a->val;
            a = a->next;
        }
        if(b != NULL){
            j = b->val;
            b = b->next;
        }
        k = i + j + jump;
        jump = k/10;
        
        ListNode *ite = new ListNode(k % 10);
        ans = ite;
        
        while(a != NULL || b != NULL || jump == 1)
        {
            i = 0;
            j = 0;
            if(a != NULL){
                i = a->val;
                a = a->next;
            }
            if(b != NULL){
                j = b->val;
                b = b->next;
            }
            k = i + j + jump;
            jump = k/10;
            c = new ListNode(k % 10);
            ite->next = c;
            ite = c;
        }
        return ans;        
    }
};

int main(){

    return 0;
}