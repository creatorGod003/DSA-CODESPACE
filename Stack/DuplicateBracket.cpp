/*
Q: Duplicate Bracket
Given a string expression, find if there exist any duplicate parenthesis or not.
A bracket pair is said to be duplicate if the same sub-expression is enclosed within multiple parenthesis.
Input: ((a+b))
Output: Duplicate Paranthesis
Input: (a+(b)/c)
Output: No Duplicate Paranthesis

*/

#include <string> 
#include <stack>
using namespace std;

bool duplicateParanthesis(string &expr)
{
    int i=0;
    stack<char> st;
    while(i<expr.size()){
        char ch = expr[i];
        if(ch!=')'){
            st.push(ch);
        }
        else{
            bool isExpression = false;
            while(!st.empty() && st.top()!='('){
                st.pop();
                isExpression = true;
            }

            if(isExpression == false){
                return true;
            }
            else{
                if(!st.empty())
                    st.pop();
            }

        }
        i++;
    }

    return false;

}

int main()
{
    string expr = "((a+b))";
    if(duplicateParanthesis(expr)){
        printf("Duplicate Paranthesis\n");
    }
    else{
        printf("No Duplicate Paranthesis\n");
    }
}