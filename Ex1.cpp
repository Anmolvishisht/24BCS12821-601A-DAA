#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next)
        return NULL;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  
        }
    }
    return NULL;
}

int main() {
    int N;
    cin >> N;
    vector<int> values(N);
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }
    int pos;
    cin >> pos;
    if (N == 0) {
        cout << "no cycle";
        return 0;
    }
    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;
    ListNode* cycleNode = NULL;

    if (pos == 0)
        cycleNode = head;

    for (int i = 1; i < N; i++) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;

        if (i == pos)
            cycleNode = temp;
    }
    if (pos != -1)
        temp->next = cycleNode;

    ListNode* result = detectCycle(head);

    if (result == NULL) {
        cout << "no cycle";
    } else {
        int index = 0;
        temp = head;
        while (temp != result) {
            temp = temp->next;
            index++;
        }
        cout << "tail connects to node index " << index;
    }

    return 0;
}