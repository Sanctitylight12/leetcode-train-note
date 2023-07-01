#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;

//parentheses 括號


// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]


class Solution {

public:
    void generateBracket( vector<string>&result,string current,int left,int right,int n){

        if(current.size()==2*n){//bracket成對，故 *2，數量等於時，代表跑完了
            result.push_back(current);
            return;
        }

        if(left<n){//left bracket 還有沒trace過的，繼續往下trace left bracket
            generateBracket(result, current + '(', left + 1, right, n);
        }
         if(right<left){//right bracket 還有沒trace過的，繼續往下trace right bracket
             generateBracket(result, current + ')', left, right+1, n);

        }

    }




    vector<string> generateParenthesis(int n) {
        //n 表示有多少對bracket 
        vector<string>result;//空列表，為最終返回結果的列表
        generateBracket(result,"",0,0,n);//str 暫存當前所能獲取到的括號的樣子
        return result;
        
    }
};