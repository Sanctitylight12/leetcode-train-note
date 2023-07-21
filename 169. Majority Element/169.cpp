#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.

You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

*/

//簡單，但可能會有問題的寫法
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         return nums[n/2];
//     }
// };


// hash map ：常用於，統計一個字符串中，每個出現的字符次數

// key-value，key存數字，value存出現次數


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        for(int i = 0; i < n; i++){
            //假設num[0]=1，num[3]=1，代入就會變成 m[1]，也就是 1 這個元素出現，每次限一次m[1]++來統計次數
            m[nums[i]]++;
        }

        n = n/2;
        for(auto x: m){
            if(x.second > n){ // value值>數組一半的長度時，該元素為出現最多次的
                return x.first;
            }
        }
        return 0;
    }
};


// 補充資料 https://www.cprogramming.com/c++11/c++11-ranged-for-loop.html



// int main()
// {
    
//     vector<int> vec;
//     vec.push_back( 1 );
//     vec.push_back( 2 );
 
//     for (int &i : vec ) //要對裡面的參數進行修改時，i前要加&
//     {
//         i++; // increments the value in the vector
//     }
//     for (int i : vec ) //以i為容器，來便歷vec
//     {
//         // show that the values are updated
//         cout << i << endl;
//     }


//     return 0;
// }

