#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/


class Solution {//Brute Force
public:
   vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {//目標加總值
                    return {i, j};//找到回傳tag
                }
            }
        }
        return {}; // No solution found
    }
};


int main(void)
{
    
    Solution testObj;
    
    vector<int> vect{2,7,11,15};
    vector<int> ace;
    int t=9;
    ace=testObj.twoSum(vect,t);

    for (int i : ace)
        cout << i << " ";

}

// class Solution2 {//(Two-pass Hash Table)
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> numMap;
//         int n = nums.size();

//         // Build the hash table
//         for (int i = 0; i < n; i++) {
//             numMap[nums[i]] = i;
//         }

//         // Find the complement
//         for (int i = 0; i < n; i++) {
//             int complement = target - nums[i];
//             if (numMap.count(complement) && numMap[complement] != i) {
//                 return {i, numMap[complement]};
//             }
//         }

//         return {}; // No solution found
//     }
// };




// class Solution3 {//(One-pass Hash Table)
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> numMap;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             int complement = target - nums[i];
//             if (numMap.count(complement)) {
//                 return {numMap[complement], i};
//             }
//             numMap[nums[i]] = i;
//         }

//         return {}; // No solution found
//     }
// };