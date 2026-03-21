/*
    Q: Balanced Brackets
    Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“ and “]” are correct in exp.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string expr){
    stack<char> charStack;
    for(int i=0;i<expr.size();i++){
        char ch = expr[i];
        if(ch!='}' && ch!=']' && ch!=')'){
            charStack.push(ch);
        }
        else{

            if(charStack.size() == 0){
                return false;
            }

            while(!charStack.empty()){
                int topEle = charStack.top();
                if(topEle!='{' && topEle!='[' && topEle!='('){
                    charStack.pop();
                }
                else{
                    if( (ch == ')' && topEle == '(' ) || ( ch == '}' && topEle == '{' ) || ( ch == ']' && topEle == '[' )){
                        charStack.pop();
                        break;
                    }
                    else{
                        return false;
                    }
    
                }
            }
        }
    }
    
    return charStack.size()==0 ;

}

int main(){
    string expr = "(a+b)";
    cout<< "String " << expr << " is " << (isBalanced(expr)?"balanced" : "not balanced");
}