#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values)
{
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : values) 
    {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

//print linked list
void printLinkedList(ListNode* head) 
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

ListNode* mergeNodes(ListNode* head) {
    if (head == NULL) {
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    ListNode* newLastNode = NULL;
    int sum = 0;
    while (fast != NULL) 
    {
        if (fast->val != 0)
        {
            sum += fast->val;
        }
         else 
        {
            slow->val = sum;
            newLastNode = slow;
            slow = slow->next;
            sum = 0;
        }
        fast = fast->next;
    }
    ListNode* temp = newLastNode->next;
    newLastNode->next = NULL;
    while (temp != NULL) {
        ListNode* nxt = temp->next;
        delete temp;
        temp = nxt;
    }
    return head;
}

int main() {
    vector<int> values = {0, 3, 1, 0, 4, 5, 2, 0};
    ListNode* head = createLinkedList(values);
    cout << "Original List: ";
    printLinkedList(head);

    head = mergeNodes(head);
    cout << "Merged List: ";
    printLinkedList(head);
    return 0;
}


