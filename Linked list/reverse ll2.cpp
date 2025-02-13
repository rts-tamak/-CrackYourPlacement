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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* it = dummy;
        ListNode* prevIt = NULL;
        // finding left and previous of left for reversing
        for(int i = 0; i < left; i++){
            prevIt = it;
            it = it->next;
        }
        ListNode* prevItR = prevIt;
        ListNode* itR = it;
        // loop till previous node is not equal to right node i.e. 4 in example
        for(int i = left; i <= right; i++){
            // itR is curr node
            ListNode* forward = itR->next;
            itR->next = prevItR;
            prevItR = itR;
            itR = forward;
        }

        // making connection
        
        prevIt->next = prevItR;
        it->next = itR;

        return dummy->next;
    }
};