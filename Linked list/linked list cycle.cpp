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
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> m;

        while(head != NULL)
        {
            m[head]++;
            if(m[head] >= 2) return true;
            head = head -> next;
        }

        return false;

    }
};