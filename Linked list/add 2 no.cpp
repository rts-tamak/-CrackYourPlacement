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

    ListNode* reverse(ListNode* list)
    {
        ListNode* curr = list;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* curr1, ListNode* curr2) {

        // ListNode* curr1 = reverse(l1);
        // ListNode* curr2 = reverse(l2);
        // cout << curr1 -> val << " " << curr2 -> val << '\n';
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        int count = 0;

        while(curr1 != NULL && curr2 != NULL)
        {
            int val = curr1 -> val + curr2 -> val;
            val += carry;
            cout << val << '\n';
            if(val <= 9)
            {
                ListNode* newNode = new ListNode(val);
                temp -> next = newNode;
                carry = 0;
            }
            else
            {
                int last = val%10;
                val /= 10;
                carry = val;
                ListNode* newNode = new ListNode(last);
                temp -> next = newNode;
            }
            temp = temp -> next;
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }

        while(curr1 != NULL)
        {
            count++;
            int val = curr1 -> val + carry;
            int last = val%10;

            ListNode* newNode = new ListNode(last);
            val/=10;
            temp -> next = newNode;
            temp = temp -> next;
            carry = val;
            curr1 = curr1 -> next;
        }

        while(curr2 != NULL)
        {
            int val = curr2 -> val + carry;

            int last = val%10;
            ListNode* newNode = new ListNode(last);

            val/=10;
            temp -> next = newNode;
            temp = temp -> next;
            carry = val;
            curr2 = curr2 -> next;
        }
        if(carry != 0)
        {
            ListNode* newNode = new ListNode(carry);
            temp -> next = newNode;
        }

        return head -> next;
    }
};