
//  * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * revHead=reverse(head);
        ListNode * prev=revHead;
        ListNode * curr = revHead->next;
        int cnt=1;
        if (n==1) {
            revHead=revHead->next;
           ListNode *newhead= reverse(revHead);
            return newhead; 
        }
        while(curr!=NULL){
            cnt++;
            if(cnt==n){
                // ListNode * currNode=curr->next;
                prev->next=curr->next;
                delete(curr);
                break;
            }
            prev=curr;
            curr=curr->next;

        }
        ListNode * newhead=reverse(revHead);
        return newhead;
    }
};