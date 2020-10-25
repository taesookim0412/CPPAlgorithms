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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val){
            ListNode* pHead = head;
            head = head->next;
            delete pHead;
        }
        if (head == nullptr){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = head;
        while (curr){
            ListNode* pCurr = nullptr;
            if (curr->val == val){
                prev->next = curr->next;
                pCurr = curr;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
            delete pCurr;
        }
        return head;
    }
};