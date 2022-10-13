/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) return nullptr;
    ListNode *curr = head;
    ListNode *prev = curr;
    
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->val == curr->val) {
            while (curr->next != nullptr && curr->next->val == curr->val) {
                if (curr == head) head = curr->next;
                curr = curr->next;
            }
            if (curr == head) head = curr->next;
            curr = curr->next;
            prev->next = curr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
};
