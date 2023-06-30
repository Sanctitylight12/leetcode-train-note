#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;


// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
//Time Complexity O(n+m)

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

struct ListNode {
    int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
//遞迴法
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         //誰空先返回另一串
//         if(list1==NULL){

//             return list2;
//         }
//         if(list2==NULL){

//             return list1;
//         }
//         //比大小
//         if(list1->val<=list2->val){
//             //小的那一串往下比下一個，由下一個繼續進行比較
//             list1->next=mergeTwoLists(list1->next,list2);
//             return list1;
//         }else{
//             list2->next=mergeTwoLists(list1,list2->next);
//             return list2;

//         }
  
//     }
// };

//疊代法

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
// 	    // if list1 happen to be NULL
// 		// we will simply return list2.
//         if(list1 == NULL)
//             return list2;
		
// 		// if list2 happen to be NULL
// 		// we will simply return list1.
//         if(list2 == NULL)
//             return list1;

//基本上就是多用ptr跟cur去存比較獲勝的值，之後再透過ptr回傳印出答案
        
//         ListNode * ptr = list1;
//         if(list1 -> val > list2 -> val)
//         {
//             ptr = list2;
//             list2 = list2 -> next;
//         }
//         else
//         {
//             list1 = list1 -> next;
//         }
//         ListNode *curr = ptr;
        
// 		// till one of the list doesn't reaches NULL
//         while(list1 &&  list2)
//         {
//             if(list1 -> val < list2 -> val){
//                 curr->next = list1;
//                 list1 = list1 -> next;
//             }
//             else{
//                 curr->next = list2;
//                 list2 = list2 -> next;
//             }
//             curr = curr -> next;
                
//         }
		
// 		// adding remaining elements of bigger list.
//         if(!list1)
//             curr -> next = list2;
//         else
//             curr -> next = list1;
            
//         return ptr;
       
//     }
// };