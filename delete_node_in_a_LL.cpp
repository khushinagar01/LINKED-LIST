#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//delete a node (except the tail) from the linked list.
void deleteNode(ListNode* node) 
{
    if (node == nullptr || node->next == nullptr) 
    {
        return;
    }
    ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
}

//print the linked list.
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

int main() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Original List: " << endl;
    printList(head);
    
    // Deleting node with value 3 (we pass pointer to the node with value 3)
    deleteNode(head->next->next);
    
    cout << "List after deleting node 3: " << endl;
    printList(head);
    
    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
