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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int min_dist = INT_MAX, max_dist = INT_MIN, prev_idx = -1, first_idx = -1, last_idx = -1, curr_idx = 0;

        ListNode* prev = NULL;
        while(head->next) {
            if(prev) {
                if((prev->val > head->val && head->next->val > head->val) || 
                   (prev->val < head->val && head->next->val < head->val)) {
                    if(prev_idx != -1) min_dist = min(min_dist, curr_idx - prev_idx);
                    prev_idx = curr_idx;
                    if(first_idx == -1) first_idx = curr_idx;
                    last_idx = curr_idx;
                    if(first_idx != -1 && last_idx != -1) max_dist = max(max_dist, last_idx - first_idx);
                    
                }
            }

            curr_idx++;
            prev = head;
            head = head->next;

        }

        if(min_dist == INT_MAX || max_dist == INT_MIN) return {-1, -1};

        return {min_dist, max_dist};
    }
};