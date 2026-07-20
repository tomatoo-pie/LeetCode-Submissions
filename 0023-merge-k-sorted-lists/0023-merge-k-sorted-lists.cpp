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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   // Min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minheap;

        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i]==nullptr) continue;
            minheap.push(lists[i]);
        }

        if(minheap.empty()) return nullptr;

        ListNode* merged = minheap.top();
        minheap.pop();

        if(merged->next){
            minheap.push(merged->next);
        }

        ListNode* temp = merged;

        while(!minheap.empty()){
            ListNode* node = minheap.top();
            minheap.pop();

            temp->next = node;
            temp = temp->next;

            if(node->next){
                minheap.push(node->next);
            }
        }
        temp->next = nullptr;

        return merged;
    }
};