#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL) 
        {
            return nullptr;
        }
        ListNode* a = headA;
        ListNode* b = headB;
        
        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }
        
        return a;
    }
};

// function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) 
    {
        return NULL;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print linked list
void printList(ListNode* head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to create an intersection between two linked lists
void createIntersection(ListNode* headA, ListNode* headB, int intersectVal) {
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    
    // Find the intersection node in A
    while (tempA && tempA->val != intersectVal) {
        tempA = tempA->next;
    }

    // Traverse B till the end
    while (tempB->next) {
        tempB = tempB->next;
    }

    // Link B to intersection node in A
    tempB->next = tempA;
}

int main() {
    Solution solution;

    // Creating first list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    int arrA[] = {1, 2, 3, 4, 5};
    ListNode* headA = createLinkedList(arrA, 5);

    // Creating second list: 10 -> 20 -> NULL
    int arrB[] = {10, 20};
    ListNode* headB = createLinkedList(arrB, 2);

    // Creating intersection at node with value 3
    createIntersection(headA, headB, 3);

    // Printing lists
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    // Finding intersection
    ListNode* intersectionNode = solution.getIntersectionNode(headA, headB);

    if (intersectionNode) 
    {
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    } 
    else 
    {
        cout << "No intersection found." << endl;
    }

    return 0;
}










