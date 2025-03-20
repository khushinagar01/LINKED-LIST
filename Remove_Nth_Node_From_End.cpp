#include <iostream>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse a linked list
ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    
    while (curr != NULL) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Function to remove the nth node from the end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) return nullptr;  // Edge case: empty list
   
    // Step 1: Reverse the list
    head = reverse(head);  

    // If the node to be removed is the first node
    if (n == 1) 
    {
        ListNode* toDelete = head;
        head = head->next;
        delete toDelete;
        return reverse(head);  // Reverse again before returning
    }

    ListNode* temp = head;
    int pos = 1;

    // Traverse to the (n-1)th node
    while (temp != NULL && pos < n - 1) {
        temp = temp->next;
        pos++;
    }

    // Remove nth node if it's valid
    if (temp != NULL && temp->next != NULL) {
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    head=reverse(head);

    // Step 3: Reverse again to restore order
    return head;  
}

// Function to print the linked list
void printList(ListNode* head) 
{
    while (head != NULL) 
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" <<endl;
}


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, 3);

    cout << "Updated List: ";
    printList(head);

    return 0;
}
