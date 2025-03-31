#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//find the next larger node
vector<int> nextLargerNodes(ListNode* head) 
{
    //Step 1:convert ll into vector
    vector<int> LL;
    while (head) 
    {
        LL.push_back(head->val);
        head = head->next;
    }
    stack<int> st;
    vector<int> ans(LL.size());
    for (int i = 0; i < LL.size(); i++) 
    {
        while (!st.empty() && LL[i] > LL[st.top()]) 
        {
            int idx = st.top();
            st.pop();
            ans[idx] = LL[i];
        }
        st.push(i);
    }
    return ans;
}

//create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values)
{
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}


void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

\
int main() {
    vector<int> values = {2, 1, 5}; 
    ListNode* head = createLinkedList(values);
    
    vector<int> result = nextLargerNodes(head);
    
    cout << "Next Larger Nodes: ";
    printVector(result);
    
    return 0;
}
