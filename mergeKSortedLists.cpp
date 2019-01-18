#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* result = new ListNode(0);
    ListNode* output = new ListNode(0);
    output = result;
    vector<int> holder;
    for(int i = 0 ;i < lists.size(); i++){
        while(lists[i]){
            holder.push_back(lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    sort(holder.begin(), holder.begin() + holder.size());
    for(int i = 0; i < holder.size(); i++){
        ListNode* nextNode = new ListNode(holder[i]);
        result->next = nextNode;
        result = result->next;
    }
    return output->next;
};
