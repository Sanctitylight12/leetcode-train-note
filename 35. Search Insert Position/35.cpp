
#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;


// Given a sorted array of distinct integers and a target value, 

// return the index if the target is found. If not, 

// return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2


// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1


// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4


//常規法-線性搜尋：

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // By using the linear search

        int n = nums.size();
        for(int i = 0; i<n;i++)
        {
            if(nums[i]>=target)
                return i;
        }
        return n;
    }
};
   


// 二分法



// class Solution2 {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int left =0;
//         int right = nums.size()-1;
//         //Binary Search Algo
//         while(left<= right){
//             int mid = left + (right-left)/2;

//             // if target is found return its index
//             if(nums[mid] == target) return mid;

//             else if(nums[mid] > target) right = mid-1;
//             else left = mid+1;

//         }
//         //returning left index as it contains the position where it would be if it were inserted in order.
//         return left;
//     }
    
// };




// class Solution2 {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int n=nums.size();
//         int l=0,r=n-1;
//         while(l<=r){
//             int m=l+(r-1)/2;
//             if(nums[m]==target)return m;
//             if(nums[m]<target) l=m+1;
//             else r=m-1;
//         }
//         return l;
//     }
// };