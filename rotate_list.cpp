#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//print the linked list
void printList(ListNode* head)
{
    ListNode* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// Function to append a new node at the end
void append(ListNode*& head, int val)
{
    if (head == NULL) 
    {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

//length of the linked list
int getLength(ListNode* head)
{
    int len = 0;
    ListNode* temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

//rotate the linked list to the right
ListNode* rotateRight(ListNode* head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int len = getLength(head);
    int actualRotateK = (k % len);
    if (actualRotateK == 0) 
    {
        return head;
    }
    int newLastNodePos = len - actualRotateK - 1;
    ListNode* newLastNode = head;
    for (int i = 0; i < newLastNodePos; i++) 
    {
        newLastNode = newLastNode->next;
    }
    ListNode* newHead = newLastNode->next;
    newLastNode->next = NULL;
    ListNode* it = newHead;
    while (it->next != NULL) 
    {
        it = it->next;
    }
    it->next = head;
    return newHead;
}

int main() {
    ListNode* head = NULL;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    cout << "Original List: ";
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);
    
    return 0;
}
