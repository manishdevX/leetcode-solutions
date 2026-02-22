// LINK - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

// n = size of linkedlist

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head->next)
        {
            return nullptr;
        }

        ListNode *prev = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow->next;
        slow->next = middle->next;
        delete middle;
        return head;
    }
};