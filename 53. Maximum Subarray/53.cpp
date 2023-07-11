#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


/*

Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.


Example 2:
Input: nums = [1]
Output: 1


Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

Explanation: The subarray [5,4,-1,7,8] has the largest sum 23



*/


// C++ 語言定義了多種內建資料型別，並規定了它們應占用多少記憶體以及相應的最大/最小值。
// 像整數這樣的資料型別通常用於需要考慮其可能出現的最大值和最小值的計算中。
// 儘管限制取決於特定型別的儲存大小，但這些限制會根據硬體平臺而有所不同。
// 因此，我們需要使用固定的控制代碼訪問這些值，因此需要使用巨集表示式 INT_MIN 和 INT_MAX。
// 這些對應於 signed int 資料型別的最小值和最大值。下面的示例演示了 <climits> 標頭檔案下可​​用的多個巨集表示式。


// 暴力法


// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int maximumSumSubarray = INT_MIN;
//         for(int i=0; i<n; i++){
//             int currSum = 0;
//             for(int j=i; j<n; j++){
//                 currSum += nums[j];
//                 if(currSum > maximumSumSubarray){
//                     maximumSumSubarray = currSum;
//                 }
//             }
//         }
//         return maximumSumSubarray;
//     }
// };



// 分治法(Divide & conquer)

// class Solution {
// private:
//     int maxSubArray(vector<int>& nums, int low, int high){
//         if(low == high){
//             return nums[low];
//         }
//         int leftMaxSumSubarray = INT_MIN, rightMaxSumSubarray = INT_MIN;

//         int mid = (low + high) >> 1;
//         int currSum = 0;
//         for(int i=mid; i>=low; i--){
//             currSum += nums[i];
//             leftMaxSumSubarray = max(leftMaxSumSubarray, currSum);
//         }

//         currSum = 0;
//         for(int i=mid+1; i<=high; i++){
//             currSum += nums[i];
//             rightMaxSumSubarray = max(rightMaxSumSubarray, currSum);
//         }

//         int maxSumSubarray =  leftMaxSumSubarray +  rightMaxSumSubarray;
//         int leftAnsSum = maxSubArray(nums, low, mid);
//         int rightAnsSum = maxSubArray(nums, mid+1, high);

//         return max(maxSumSubarray, max(leftAnsSum, rightAnsSum));
//     }
// public:
//     int maxSubArray(vector<int>& nums) {
//         return maxSubArray(nums, 0, nums.size()-1);
//     }
// };





// 動態規劃

/*
    每一步和前面進行合併，找出最大的序列和
    -和前面合併
    -不和前面合併
*/


// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int dp[n];
//         dp[0] = nums[0];
//         int maximumSumSubarray = nums[0];
//         for(int i=1; i<n; i++){
//             dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
//             maximumSumSubarray = max(maximumSumSubarray, dp[i]);
//         }
//         return maximumSumSubarray;
//     }
// };



// Kadane's Algorithm

// Kadane’s Algorithm
// 如果已知 A[:i] 的 max sum，那麼 A[:i+1] 的 max sum 必定包含或不包含 A[:i] 的 prefix。

// 對每個 A 內的元素，求目前位置 i 所能達到的 sum 最大值，令其為 max_ending_here。

// 包含 prefix 的情況下，max_ending_here 等於 prefix 加上當前元素 a。

// 不包含 prefix 的情況下，max_ending_here 為 0，因為不包含的情況，表示 max_ending_here + a 小於 0，

// 所以我們可以直接捨棄掉 prefix 和當前元素 a，令 max_ending_here 歸零，從下一個元素開始累積 sum。




// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int currSum = 0, maximumSumSubarray = INT_MIN;
//         for(auto num : nums){
//             currSum += num;
//             if(currSum > maximumSumSubarray){
//                 maximumSumSubarray = currSum;
//             }
//             if(currSum < 0){
//                 currSum = 0;
//             }
//         }
//         return maximumSumSubarray;
//     }
// };

// class Solution3 {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int ans = INT_MIN;
//         int sum = 0;
//         for(auto &i: nums){
//             sum += i;
//             ans = max(ans,sum);
//             if(sum<0)sum = 0;
//         }
//         return ans;
//     }
// };



// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxSum=INT_MIN;
//         int currentSum = 0;

//         for(int i=0;i<nums.size();i++){
//             currentSum+=nums[i];

//             if(currentSum>maxSum){
//                 maxSum=currentSum;
//             }

//             if(currentSum<0){
//                 currentSum=0;
//             }


//         }
//         return maxSum;

//     }
// };


