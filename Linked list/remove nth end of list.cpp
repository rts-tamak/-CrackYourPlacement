/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* curr = head;

        while(curr != NULL)
        {
            length++;
            curr = curr -> next;
        }
        if(length == 1) return NULL;
        int steps = length - n;
        curr = head;
        if(steps == 0)
        {
            head = head -> next;
            return head;
        }
        for(int i = 1;  i < steps; i++)
        {
            curr = curr -> next;
        }
        
        curr -> next = curr -> next -> next;
        return head;
    }
};