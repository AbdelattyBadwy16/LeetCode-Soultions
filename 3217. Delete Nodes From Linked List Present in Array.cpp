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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,bool>mp;
        for(auto it:nums)mp[it] = 1;
        ListNode* start = new ListNode();
        ListNode* par = start;
        ListNode* child = head;
        while(child!=nullptr){
            if(!mp[child->val]){
                par->next = child;
                par = par->next;
            }
            child = child->next;
        }
        par->next = child;
        return start->next;
    }
};