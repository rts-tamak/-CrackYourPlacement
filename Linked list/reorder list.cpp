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
    void reorderList(ListNode* head) {
        map<ListNode*, ListNode*> m;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        int count = 0;
        while(curr != NULL)
        {
            count++;
            forward = curr -> next;
            m[curr] = prev;
            prev = curr;
            curr = forward;
        }
        curr = head;
             
        for(int i = 0; i < count; i++)
        {
            if(i%2 == 0)
            {
                forward = curr -> next;
                curr -> next = prev;
                curr = forward;
                if(i == count - 1)
                {
                    prev -> next = NULL;
                }
            }
            else
            {
                prev -> next = curr;
                prev = m[prev];
                if(i == count - 1)
                {
                    curr -> next = NULL;
                }
            }
        }

    }
};