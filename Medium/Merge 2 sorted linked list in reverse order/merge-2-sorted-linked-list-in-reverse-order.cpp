//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * reverse(Node *node){
        if(node==NULL || node->next==NULL) return node;
        Node *d=NULL;
        while(node){
            Node *next = node->next;
            node->next=d;
            d=node;
            node=next;
        }
        return d;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        node1 = reverse(node1);
        node2 = reverse(node2);
        Node * head=NULL;
        Node *temp;
        while(node1 && node2){
            Node *ptr=new Node;
            if(node1->data>=node2->data){
                ptr->data=node1->data; node1=node1->next;
            }
            else{
                ptr->data=node2->data; node2=node2->next;
            }
            
            if(head==NULL){
                head=ptr; temp=ptr;
            }
            else{
                temp->next=ptr; temp=ptr;
            }
        }
        
        while(node1){
            Node *ptr=new Node;
            ptr->data=node1->data; node1=node1->next;
            if(head==NULL){
                head=ptr; temp=ptr;
            }
            else{
                temp->next=ptr; temp=ptr;
            }
        }
        while(node2){
            Node *ptr=new Node;
            ptr->data=node2->data; node2=node2->next;
            if(head==NULL){
                head=ptr; temp=ptr;
            }
            else{
                temp->next=ptr; temp=ptr;
            }
        }
        return head;
    }  
};

























//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends