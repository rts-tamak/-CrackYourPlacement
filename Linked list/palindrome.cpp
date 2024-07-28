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
private:
    int len(ListNode* head)
    {
        int count = 0;
        while(head != NULL)
        {
            head = head -> next;
            count++;
        }
        return count;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = head;
        
        while(curr!=NULL)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
        {
            return true;
        }
        
        if(head -> next == NULL)
        {
            return true;
        }
        int length = len(head);
        
        ListNode* middlehead = head;
        
        for(int i=1;i<(length/2)+1; i++)
        {
            middlehead = middlehead -> next;
        }
        
        middlehead = reverse(middlehead);
        for(int i=1; i<=length/2;i++)
        {
            if(head -> val != middlehead -> val)
            {
                return false;
            }
            if(head -> next != NULL)
            {
                head = head -> next;
            }
            if(middlehead -> next != NULL)
            {
                middlehead = middlehead -> next;
            }
        }
        return true;
    }
};