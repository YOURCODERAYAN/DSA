/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*temp=head;
        unordered_map<ListNode*,int> mp;

    while(temp!=NULL){
        if(mp.find(temp)!=0){
            return temp;
        }
    
    mp[temp]=1;
    temp=temp->next;
    }
    return nullptr;
    }
};*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        
        slow=slow->next;
        fast=fast->next->next;

    if(slow==fast){
        slow=head;
    
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
    }
    }
    return NULL;
    }
};
