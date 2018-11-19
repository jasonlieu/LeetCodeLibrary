/**
 * Input: (2 -> 4 -> 3) + 
 *        (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */
#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(0);             //to keep track of head
    ListNode* current = new ListNode(0);
    result->next = current;
    int carry = 0;
    while(l1 || l2){                                //keep looping until both l1 and l2 are NULL
        int a = 0, b = 0;
        if(l1){
            a = l1->val;
        }
        if(l2){
            b = l2->val;
        }
        if( (a + b + carry) > 9){                   //to keep nodes single digit, if >9, carry 1
            current->val = ((a + b + carry)%10);
            carry = 1;
        }
        else{                                       //normal add, reset carry
            current->val = (a + b + carry);
            carry = 0;
        }
        if(l1 && l1->next != NULL){                 //if no next, set as null
            l1 = l1->next;
        }
        else{
            l1 = NULL;
        }
        if(l2 && l2->next != NULL){
            l2 = l2->next;
        }
        else{
            l2 = NULL;
        }
        if(l2 || l1){                               //create next node only if l1 or l2 is not finished
            ListNode* nextNode = new ListNode(0);
            current->next = nextNode;
            current = current->next;
        }
        else if(carry == 1){                        //carry at the end
            ListNode* endNode = new ListNode(1);
            current->next = endNode;
        }
    }
    return result->next;
};

int main(){
    ListNode* Aa = new ListNode(1);
    //ListNode* Ab = new ListNode(4);
    //ListNode* Ac = new ListNode(3);
    ListNode* Ba = new ListNode(9);
    ListNode* Bb = new ListNode(9);
    //ListNode* Bc = new ListNode(4);
    //Aa->next = Ab;
    //Ab->next = Ac;
    Ba->next = Bb;
    //Bb->next = Bc;

    ListNode* result = addTwoNumbers(Aa, Ba);
    cout<<result->val<<" ";
    cout<<result->next->val<<" ";
    cout<<result->next->next->val<<" ";


}
