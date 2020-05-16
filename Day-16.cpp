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
    ListNode* oddEvenList(ListNode* head) {
        int count = 1;
        
        if(!head) return head;
        
        ListNode* evenPtr = NULL;
        ListNode* oddPtr = NULL;
        ListNode* evenStart = NULL;
        ListNode* tempPtr = head;
        ListNode* start = NULL;
        
        while(tempPtr){
            ListNode* newNode = new ListNode(tempPtr->val);
            if(count % 2 == 0){
                if(count == 2) {
                    evenPtr = newNode;
                    evenStart = evenPtr;
                }else{
                    evenPtr->next = newNode;
                    evenPtr = evenPtr->next;
                }
                
            }else{
                if(count == 1){
                    oddPtr = newNode;
                    start = oddPtr;
                }else{
                    oddPtr->next = newNode;
                    oddPtr = oddPtr->next;
                }
            }
            tempPtr = tempPtr->next;
            count++;
        }
   
        
        oddPtr->next = evenStart;
        
        
        return start;
    
    }
};
