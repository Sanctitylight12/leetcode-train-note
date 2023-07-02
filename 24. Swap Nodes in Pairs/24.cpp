#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;


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
/*

// Given a linked list, swap every two adjacent nodes and return its head. 

//You must solve the problem without modifying the values in the list's nodes 

//(i.e., only nodes themselves may be changed.)

// Example 1:

// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

// Example 2:

// Input: head = []
// Output: []

// Example 3:
// Input: head = [1]
// Output: [1]

*/

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


//迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;//小於兩個節點，就不用繼續swap

        ListNode* resultNode = new ListNode();//暫存

        ListNode* prevNode = resultNode;//在頭前做一個節點，來做為中繼的node
        //1.R(prev)->2.Head(cur)->3.headnextnode->4.elsenode
        ListNode* currNode = head;//暫存原本的頭

        while(currNode && currNode->next){
            prevNode->next=currNode->next;//R(1)->cur(3)//(也就是head指向下一節點的線headnextnode)
            currNode->next=prevNode->next->next;//cur的線即headnextnode(3)->Head(2)
            prevNode->next->next=currNode;//Head(2)->elsenode
            //now  1->3->2->4，完成2&3的swap

            prevNode=currNode;//前綴指針於交換完後，往後移至要交換的前一個節點
            currNode=currNode->next;//移至要交換的第一個節點

        }
        return resultNode->next;

    }
};

//遞迴法

class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *temp = head->next;
        head->next = swapPairs(temp->next); 
        temp->next = head;
        
        return temp;
    }
};