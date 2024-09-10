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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* first = head->next;
        ListNode* last = head;
        while(first!=nullptr){
            ListNode* temp = new ListNode();
            temp->val = __gcd(first->val,last->val);
            last->next = temp;
            temp->next = first;
            first = first->next;
            last = temp->next;
        }
        return head;
    }
};