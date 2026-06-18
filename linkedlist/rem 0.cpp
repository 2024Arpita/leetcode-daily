//lc 1171

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>mp;
        int sum=0;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        for(ListNode* curr=dummy;curr;curr=curr->next){
            sum+=curr->val;
            mp[sum]=curr;
        }
        sum=0;
        for(ListNode* curr=dummy;curr;curr=curr->next){
            sum+=curr->val;
            curr->next=mp[sum]->next;
        }
        return dummy->next;
    }
};
