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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0, cnt = k;
        ListNode* ptr = head;
        while(ptr) {ptr = ptr->next; n++;} 


        ListNode* newHead; ListNode* curr = head, *prev = NULL, *prevTail = NULL;
        while(n - k >= 0) {
            ListNode* tempStart = curr;

            while(cnt > 0) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                cnt -= 1;
            }
            cnt = k;
            if(!prevTail) newHead = prev;
            else prevTail->next = prev; 

            prevTail = tempStart;

            tempStart->next = curr;

            prev = NULL;

            n = n - k;

        }

        return newHead;
    }
};