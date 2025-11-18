#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// print the linked list
void printList(ListNode* head)
{
    while (head) 
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

//insert a node at the end of the linked list
ListNode* insert(ListNode* head, int val)
{
    if (!head)
    {
         return new ListNode(val);
    }
    ListNode* temp = head;
    while (temp->next)
    { 
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
    
}

// Recursive function to double the linked list values
void solve(ListNode* head, int &carry) 
{
    if (head == NULL) 
    { 
        return;
    }
    solve(head->next, carry);
    int prod = head->val * 2 + carry;
    head->val = prod % 10;
    carry = prod / 10;
}

//double the linked list values
ListNode* doubleIt(ListNode* head) 
{
    int carry = 0;
    solve(head, carry);
    if (carry != 0)
    {
        ListNode* carryNode = new ListNode(carry);
        carryNode->next = head;
        head = carryNode;
    }
    return head;
}

int main()
{
    ListNode* head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    
    cout << "Original List: ";
    printList(head);
    
    head = doubleIt(head);
    
    cout << "Doubled List: ";
    printList(head);
    
    return 0;
}



