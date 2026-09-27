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
    ListNode* reverseList(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = nullptr;
        ListNode* prev = nullptr;

        while (p1){
            p2 = p1->next;
            p1->next = prev;
            prev = p1;
            p1 = p2;
        }

        // p1->next = prev;

        return prev;
    }
};
