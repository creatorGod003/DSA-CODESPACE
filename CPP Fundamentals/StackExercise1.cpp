/*
* Exercise 1: Stack
* Reverse a string using stack
* Key Takeways:
* 1. push(x) -> function adds an element to top of stack and returns nothing.
* 2. pop() -> function removes an element from top of stack and return void.
* 3. top() -> funtion return reference to top element of stack.
* 4. empty() -> returns true if stack is empty, else false.
* 5. size() -> returns the number of elements in stack.

Taking out values from stack is in reverse order of putting values in stack. This is the main property of stack which is LIFO (Last In First Out). So, we can use stack to reverse a string. We will push all characters of string into stack and then pop all characters from stack and print them. This will give us the reversed string.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str = "hello";
    stack<char> st;
    for(char ch: str){
        st.push(ch);
    } 
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}
