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

    ListNode* getkthnode(ListNode*temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
        temp=temp->next;
        }
        return temp;
    }

    ListNode*reverse(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*newhead=reverse(head->next);
        ListNode*front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*prevnode=NULL;
        while(temp!=NULL){
            ListNode*kthnode=getkthnode(temp,k);
            if(kthnode==NULL)
            {

            if(prevnode) prevnode->next=temp;
                break;
            }
        ListNode*newnode=kthnode->next;
        kthnode->next=NULL;
        reverse(temp);

    if(temp==head)
        head=kthnode;
    else
        prevnode->next=kthnode;
        prevnode=temp;
        temp=newnode;
        }
        return head;
    }
};