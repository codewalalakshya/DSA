// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {

public:
    ListNode *reverse(ListNode *head){
        ListNode *prev=NULL;
        ListNode* curr=head;
        if(head==NULL || head->next==NULL) return head;
        while(curr!=NULL)
        {
            ListNode *nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
         if(head==NULL || head->next==NULL) return true;
          ListNode* slow=head;
          ListNode* fast=head;
          while(fast->next!=NULL && fast->next->next!=NULL)
          {
            slow=slow->next;
            fast=fast->next->next;
          }
          
          ListNode *secondHead=reverse(slow->next);
          ListNode *first=head;
          ListNode *second=secondHead;
          bool palindrome=true;
          while(second!=NULL)
          {
            if(first->val!=second->val)
            {
                palindrome=false;
                break;
            }
            first=first->next;
            second=second->next;
          }
          reverse(secondHead);
          return palindrome;

    }
};