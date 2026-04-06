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
    int length(ListNode* head) {
        int count = 0;
        while (head != NULL) {
            head = head->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        int l = length(head);
        k = k % l;

        if (k == 0) return head;

        ListNode* curr = head;
        for (int i = 0; i < l - k - 1; i++) {
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = NULL;

        
        ListNode* tail = newHead;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = head;
        return newHead;
    }
};