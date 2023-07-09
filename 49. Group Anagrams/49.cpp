
#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 

// typically using all the original letters exactly once.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

         /*
                Consider example 1 : strs = ["eat","tea","tan","ate","nat","bat"]
                
                After the below opeartion of for loop map will contain
                
                aet -- eat, tea, ate
                ant -- tan, nat
                abt -- bat
        */

        for(auto x:strs){
            string word=x;
            sort(word.begin(),word.end());//排序
            mp[word].push_back(x);//push_back ，往陣列最後一個位置塞入
        }

         //now simply put the elements  of second column of map in ans

        vector<vector<string>> ans;

        for(auto x:mp){

            ans.push_back(x.second);//x.second 指的是key-value中的value，
        }
        return ans;

    }
};

// 例如
// map<string, int> m;
// m["one"] = 1;

// map<string, int>::iterator p = m.begin();
// p->first; // 這個是 string 值是 "one"
// p->second; //這個是 int 值是 1


// vector<vector<string>>用法概念：This is definition of 2 dimension-array of strings with size n.
// int main()
// {
//   string a = "AAAA";
//   string b = "BBBB";
//   string c = "CCCC";
//   int n = 3;
//   vector<vector<string>> arr(n);

//   arr[0].push_back(a); // I add string 'a' to end of first vector in 'arr' 
//   arr[0].push_back(b);
//   arr[1].push_back(c);
//   for (int i = 0; i < arr[0].size() ; i++) { // print all string in first vector of 'arr'
//      cout << arr[0][i] << " ";
//   }
// } 