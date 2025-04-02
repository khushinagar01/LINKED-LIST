#include<iostream>
using namespace std;

//node creation

class Node
{
    public:
       int data;
       Node* next;
       Node(int data)
       {
        this->data=data;
        this->next=NULL;
       }
};

//creation of LL from array

Node* createList(int arr[],int n)
{
    if(n==0)
    {
        return NULL;
    }
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<n;i++)
    {
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }
    return head;
}

//print the LL

void print(Node*head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//1:insertion at head

Node* insertAtHead(Node* head, int data)
{
    if(head==NULL)
    {
        Node*newNode=new Node(data);
        head=newNode;
       
    }
    else
    {
        Node* newNode=new Node(data);
        newNode->next=head;
        head=newNode;
    }
    return head;
}



int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Node*head=NULL;
    Node*tail=NULL;
    head=createList(arr,n);
    cout<<"LL before insertion : "<<endl;
    print(head);
    int data;
    cin>>data;

    cout<<"LL after insertion at head : "<<endl;
    head=insertAtHead(head,data);
    print(head);
   
    return 0;
}