#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextGreaterElementToRight(vector<int> arr){
    vector<int> result;
    stack<int> st;

    for(int i=arr.size()-1;i>=0;i--){
        if(st.empty()){
            result.push_back(-1);
            st.push(arr[i]);
        }
        else{
            
            while(!st.empty() and st.top() < arr[i]){
                st.pop();
            }
            if(st.empty())
                result.push_back(-1);
            else{
                result.push_back(st.top());
            }
            
            st.push(arr[i]);
            
        }
    }
    reverse(result.begin(), result.end());
    return result;

}

int main(){
 
    vector<int> arr = {2,5,9,3,1,12,6,8,7};
    vector<int> result = nextGreaterElementToRight(arr);

    for(int x: result){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}