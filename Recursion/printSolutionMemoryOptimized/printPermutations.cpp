#include <iostream>
#include <string>
using namespace std;

void printPermutation(string s, string ans){
    if(s.size() == 0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        int n = s.size();
        string firstHalf=s.substr(0,i);
        string secondHalf = s.substr(i+1, n-i-1);
        printPermutation(firstHalf+secondHalf, ans+s[i]);
    }   
}

int main()
{
    string s="abc";
    printPermutation(s, "");
    return 0;
}