/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;

typedef pair<ListNode *, int> front;

struct classcomp{
    bool operator() (front a,  front b) {
        if(a.first == NULL && b.first == NULL) return a.second < b.second;
        else if(a.first == NULL) return false;
        else if(b.first == NULL) return true;
        else if((a.first -> val) == (b.first -> val)) return a.second < b.second;
        else return (a.first -> val) < (b.first -> val);
    }
};


class Solution {
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        set<front, classcomp> bottom;
        ListNode * ans, * current;
        front t, u, v;
        int i, j, k, l;
        k = lists.size();
        for(i = 0; i < k; i++) {
            t.first = lists[i];
            t.second = i;
            bottom.insert(t);
        }
        
        auto it = bottom.begin();
        ans = (*it).first;
        current = ans;
        while(current != NULL){
            j = (*it).second;
            bottom.erase(it);
            u.first = lists[j] -> next;
            u.second = j;
            lists[j] = u.first;
            bottom.insert(u);
            
            it = bottom.begin();
            current -> next = (*it).first;
            current = current -> next;            
        }
        return ans;   
    }
};