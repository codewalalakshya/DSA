// git init Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        
        Node * temp=head;
        int cnt=0;
        Node *prev=NULL;
        if(x==1)
        {
            temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        temp=head;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==x)
            {
               prev->next=prev->next->next;
               delete(temp);
               break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};