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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int length = 0;

        while(curr != NULL)
        {
            length++;
            curr = curr -> next;
        }
        curr = head;

        for(int i = 1; i <= length/2; i++)
        {
            curr = curr -> next;
        }
        return curr;

    }
};