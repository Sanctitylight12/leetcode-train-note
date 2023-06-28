#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


/*題目

You are given two non-empty linked lists representing two non-negative integers. 

The digits are stored in reverse order, and each of their nodes contains a single digit. 

Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


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

迭代法：

簡單來說，一位對一位，有進位就多一個carry，依托此進行遍歷，並新建一個node


遞迴法：

A鍊點1+B鍊點1，當作一層遞迴，遞迴在跳轉時，要帶上進位的值carry，一併參與下一輪遞迴


時間複雜度:O(MAX(M,N))  根據進來的兩條鍊有多長決定，基本上為了一位對一位，故取長的。
空間複雜度:O(MAX(M,N))  if tResult counted O(1)

*/



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


// class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
// //參考資料  http://alrightchiu.github.io/SecondRound/linked-list-xin-zeng-zi-liao-shan-chu-zi-liao-fan-zhuan.html

// class LinkedList{
// private:
//     // int size;                // size是用來記錄Linked list的長度, 非必要
//     ListNode *first;            // list的第一個node
// public:
//     LinkedList():first(0){};
//     void PrintList();           // 印出list的所有資料
//     void Push_front(int x);     // 在list的開頭新增node
//     void Push_back(int x);      // 在list的尾巴新增node
//     void Delete(int x);         // 刪除list中的 int x
//     void Clear();               // 把整串list刪除
//     void Reverse();             // 將list反轉: 7->3->14 => 14->3->7
// };



//  struct ListNode {
//      int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}

//       // friend class LinkedList;
// };


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         
//          ListNode* tResult=new ListNode();//存結果
//          ListNode* temp=tResult;//暫存位

//          int carry=0;//進位暫存

//         while(l1!=NULL || l2!=NULL||carry){//但凡還有一真，繼續跑或繼續進位
            
//              int sum=0;//用sum暫存兩鍊合
//             if(l1!=NULL){
//                 sum+=l1->val;//第一鍊數字塞入暫存兩鍊合
//                 l1=l1->next;//往後移去下一個node
//             }

//             if(l2!=NULL){
//                 sum+=l2->val;//第二鍊數字塞入暫存兩鍊合
//                 l2=l2->next;//往後移去下一個node

//             }
//             sum+=carry;//進位運算
//             carry=sum/10;

//             ListNode* tnewNode=new ListNode(sum%10);//把計算後，剩餘的位數塞入新的node
//             temp->next=tnewNode;//下一個節點指向node
//             temp=temp->next;//位移，之後以這個新節點開啟新一輪循環   


//         }
//         return tResult->next;


        
//     }
// };


// int main(void)
// {
    
//     //mock，實際要能跑應該要多補一個LinkedList，不過不太確定。尤其是塞資料的部分
//     //Input: l1 = [2,4,3], l2 = [5,6,4]
//     //Output: [7,0,8]


//     Solution testObj;
    
//     ListNode* test1=new ListNode();
//     ListNode* test2=new ListNode();
//     testObj.addTwoNumbers(test1,test2);


// }
