#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//print the linked list
void printList(ListNode* head)
 {
    while (head) 
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to create a linked list from an array
ListNode* createList(int arr[], int size) 
{
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to rearrange the linked list
ListNode* oddEvenList(ListNode* head) 
{
    if (head == NULL || head->next == NULL)
        return head;
    
    ListNode* h1 = head;
    ListNode* h2 = head->next;
    ListNode* evenHead = h2;
    
    while (h2 != NULL && h2->next != NULL) 
    {
        h1->next = h2->next;
        h2->next = h2->next->next;
        h1 = h1->next;
        h2 = h2->next;
    }
    
    h1->next = evenHead;
    return head;
}

template <size_t N>
void test(int (&arr)[N]) 
{
    ListNode* head = createList(arr, N);
    cout << "Original List: ";
    printList(head);
    
    head = oddEvenList(head);
    
    cout << "Modified List: ";
    printList(head);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    test(arr);
    return 0;
}

