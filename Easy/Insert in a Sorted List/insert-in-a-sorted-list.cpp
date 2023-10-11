//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        Node *temp=head;
        Node *ptr=new Node(data);
        Node *ptr2=new Node(1);
        if(temp->data>=ptr->data){
            ptr->next=head;
            head=ptr;
            return head;
        }
        while(temp!=NULL){
            if(temp->data<ptr->data){
                if(temp->next==NULL) {temp->next=ptr; return head;}
                temp=temp->next;
            }
            else if(temp->data>=ptr->data){
                ptr2->data=temp->data;
                temp->data=ptr->data;
                ptr->data=ptr2->data;
                ptr2->next= temp->next;
               temp->next=ptr;
               ptr->next=ptr2->next;
               delete(ptr2);
               break;
            }
        }
        return head;

        
    }
};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends