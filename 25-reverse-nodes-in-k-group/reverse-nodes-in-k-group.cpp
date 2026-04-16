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
        
        ListNode* curr = head;
        int count = 0;

        // check k nodes exist or not
        while(curr != NULL && count < k) {
            curr = curr->next;
            count++;
        }

        // agar k nodes hain tabhi reverse karo
        if(count == k) {
            curr = head;
            ListNode* prev = NULL;
            ListNode* next = NULL;
            count = 0;

            // reverse k nodes
            while(curr != NULL && count < k) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }

            // recursive call for next part
            if(next != NULL) {
                head->next = reverseKGroup(next, k);
            }

            return prev;
        }

        return head;
    }
};