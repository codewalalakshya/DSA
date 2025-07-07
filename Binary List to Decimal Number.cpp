
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    
    ListNode *reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode * prev=NULL;
        ListNode * curr=head;
        while(curr!=NULL){
            ListNode * NextNode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=NextNode;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        ListNode * reversedListHead = reverse(head);
        ListNode *temp=reversedListHead;
        double decimal = 0;

        int strt=0;
        while(temp!=NULL)
        {
            decimal=decimal+ pow(2,strt)*temp->val;
            strt++;
            temp=temp->next;
        }
        reverse(head);
        return decimal;
    }
};