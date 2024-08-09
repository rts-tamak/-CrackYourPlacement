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
        void f(ListNode* head, int &value, int &ans)
        {
            if(head == NULL)
            {
                return ;
            }
            
            f(head -> next, value, ans);
            ans += (head->val)*value;
            
            value *= 2;
            
        }
public:
    int getDecimalValue(ListNode* head) {
        int val = 1;
        int ans = 0;
        
        f(head, val , ans);
        return ans;
    }
};