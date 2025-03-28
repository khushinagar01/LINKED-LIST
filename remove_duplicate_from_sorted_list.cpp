#include <iostream>
using namespace std;

//singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to insert nodes at the end of the linked list
ListNode* insert(ListNode* head, int val)
{
    if (!head) return new ListNode(val);
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
    return head;
}

//print the linked list
void printList(ListNode* head) 
{
    ListNode* temp = head;
    while (temp) 
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//free memory allocated for the linked list
void freeList(ListNode* head) 
{
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

//remove duplicates from sorted linked list
ListNode* deleteDuplicates(ListNode* head) 
{
    if (!head || !head->next) 
    {
        return head;
    }
    ListNode* temp = head;
    while (temp && temp->next) 
    {
        if (temp->val == temp->next->val) 
        {
            ListNode* nextNode = temp->next;
            temp->next = nextNode->next;
            delete nextNode;
        } 
        else 
        {
            temp = temp->next;
        }
    }
    return head;
}

int main() 
{
    ListNode* head = NULL;
    head = insert(head, 1);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 3);
    
    cout << "Original List: ";
    printList(head);
    
    head = deleteDuplicates(head);
    
    cout << "After Removing Duplicates: ";
    printList(head);
    
    freeList(head);
    return 0;
}