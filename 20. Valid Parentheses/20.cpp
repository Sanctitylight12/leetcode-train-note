#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;


/*
Given a string s containing just the characters 
'(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
*/


class Solution {
public:
    bool isValid(string s) {

        stack<char> sBracket;

        for(auto c:s){
            if(c=='('||c=='{'||c=='['){
                sBracket.push(c);
            }else{
                if(sBracket.empty()){
                    return false;
                }
                if(c==')' && sBracket.top()=='('){//識別()是否成對
                    sBracket.pop();
                }else if(c=='}' && sBracket.top()=='{'){
                    sBracket.pop();

                }else if(c==']' && sBracket.top()=='['){
                    sBracket.pop();
                }
                else{
                    return false;
                }
            }
         }
        return sBracket.empty();
    }
};

int main(void)
{
    
    //mock
    //Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
    //Output: [1,2,3,4]


    Solution testObj;
    
    // vector<int> vect{2,7,11,15};
    char p[10] ="()[]{}";
    char sflag;
    sflag=testObj.isValid(p);

    // cout << sflag << " ";


    if(sflag==true){
        printf("True!\n");
    }else{
        printf("False!\n");
    }
    
    

    // for (int i : store)
    //     cout << i << " ";

}