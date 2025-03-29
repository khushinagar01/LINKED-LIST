#include <iostream>
#include<vector>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//create a linked list from a vector
ListNode* createLinkedList(vector<int> values) 
{
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;
    for (size_t i = 1; i < values.size(); i++) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    return head;
}

// print a linked list
void printLinkedList(ListNode* head) 
{
    while (head) 
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Merging function 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    ListNode* ans = new ListNode(-1);
    ListNode* mptr = ans;
    while (list1 && list2)
    {
        if (list1->val <= list2->val) 
        {
            mptr->next = list1;
            mptr = list1;
            list1 = list1->next;
        } 
        else
        {
            mptr->next = list2;
            mptr = list2;
            list2 = list2->next;
        }
    }
    if (list1)
    {
      mptr->next = list1;
    }
    if (list2) 
    {
        mptr->next = list2;
    }
    return ans->next;
}

int main() 
{
    
    vector<int> list1_values = {1, 3, 5};
    vector<int> list2_values = {2, 4, 6};

    ListNode* list1 = createLinkedList(list1_values);
    ListNode* list2 = createLinkedList(list2_values);

    cout << "List 1: ";
    printLinkedList(list1);
    cout << "List 2: ";
    printLinkedList(list2);

    ListNode* mergedList = mergeTwoLists(list1, list2);
    cout << "Merged List: ";
    printLinkedList(mergedList);

    return 0;
}
