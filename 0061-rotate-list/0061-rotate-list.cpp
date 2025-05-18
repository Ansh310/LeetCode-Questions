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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n = 0;
        ListNode* ptr = head;

        while(ptr) {ptr = ptr->next; n++;} 

        k = k % n;

        if(k == 0) return head;

        ListNode* fast = head, * slow = head;

        while(fast->next) {
            if(k > 0) {fast = fast->next; k--;}

            else {slow = slow->next; fast = fast->next;}
        }

        ListNode* newHead = slow->next; slow->next = NULL; 

        fast->next = head;

        return newHead;
        
    }
};