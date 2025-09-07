#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ListNode{
    int val; // value to be added
    ListNode *next; //pointer to next value 
    ListNode() : val(0),next(nullptr){} // 0 value in linked list
    ListNode(int x) : val(x), next(nullptr) {} // any value but its a single element linked list
    ListNode(int x, ListNode *next) : val(x), next(next) {} // any value and any number of elements 
};

ListNode* createList(const vector<int> &nums){
    if(nums.empty()) return nullptr; 
    ListNode* head = new ListNode(nums[0]); // head pointer to the first element of the linkedlist
    ListNode* current = head; // next pointer (current) to the head pointer 
    for(int i = 1; i < nums.size(); i++){
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;

}

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    // Add your methods here
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode dummy(0); //create a dummy node with value 0
        ListNode* tail = &dummy; // attach pointer tail to the dummy node 

        while(list1 != nullptr && list2 != nullptr){ // if no null ptr in both the lists 
            if(list1->val < list2-> val){ // if list1 element is lesser than list2 element
                tail->next = list1; // point the tail to the element in list1 
                list1 = list1->next; // move to next element in list1
            }else{
                tail->next = list2; // point the tail to the element in list2 
                list2 = list2->next; // move to next element in list2
            }
            tail = tail->next; // move to next spot in the node

        }
        //used because if both linked list size is not same then one of the list runs out of elements 
        if (list1 != nullptr){
            tail->next = list1; 
        }else{
            tail->next = list2;
        }

        return dummy.next;

    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4,6};
    

    ListNode* list1 = createList(nums1);
    ListNode* list2 = createList(nums2);
    

    
    // Call your methods here
    ListNode* merged = sol.mergeTwoLists(list1,list2);
    cout << "Merged list: ";
    printList(merged);
    return 0;
}