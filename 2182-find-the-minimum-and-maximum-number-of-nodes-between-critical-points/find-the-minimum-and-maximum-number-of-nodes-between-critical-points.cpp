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
private:
    vector<int> findcriticalpoint(ListNode* head){
        vector<int> criticalpoints;
        ListNode* prev=head;
        head=head->next;
        int i=1;
        while(head->next != NULL){
            if((prev->val > head->val && head->val< head->next->val)||(prev->val < head->val && head->val > head->next->val)){
                criticalpoints.push_back(i);

            }
            i++;
            prev=head;
            head=head->next;

        }
        return criticalpoints;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalpoints=findcriticalpoint(head);
        int mindis=-1;
        int maxdis=-1;
        if(criticalpoints.size()>1){
            maxdis=criticalpoints[criticalpoints.size()-1]-criticalpoints[0];
            mindis=INT_MAX;
            for(int i=1 ; i<criticalpoints.size() ; i++){
                mindis=min(mindis,criticalpoints[i]-criticalpoints[i-1]);

            }

        }
        return {mindis,maxdis};
    }
};