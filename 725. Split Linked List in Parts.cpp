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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            sz++;
            temp = temp->next;
        }
        vector<ListNode*>ans;
        int len = 0 , rem = 0;
        if(sz<k)len = 1;
        else len = sz/k , rem = sz%k;
        int cnt = 0;
        ListNode* cur = head;
        ans.push_back(head);
        k--;
        while(true){
            cnt++;
            if(!k){
                break;
            }
            if(cnt==len+(rem>0?1:0)){
                ListNode* temp = cur;
                if(cur!=nullptr)
                    cur = cur->next;
                if(temp!=nullptr)
                    temp ->next = nullptr;
                ans.push_back(cur);
                cnt = 0;
                k--;
                rem--;
            }else {
                if(cur!=nullptr)
                    cur = cur->next;
            }
        }
        return ans;
    }
};