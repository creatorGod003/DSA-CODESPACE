#include <iostream>
#include <string>
using namespace std;

void printAllSubsequence(string s, string ans){
    
    if(s.size() == 0){
        if(ans.size()!=0)
            cout<<ans<<endl;
        else{
            cout<<"\"\""<<endl;
            cout<<R"("")"<<endl;
        }
        return;
    }
    
    string subString = s.substr(1, s.size()-1);
    char firstChar = s[0];
    
    printAllSubsequence(subString, ans+firstChar);
    printAllSubsequence(subString, ans);
    
    return;
}

int main()
{
    string s = "abc";
    string ans = "";
    printAllSubsequence(s, ans);
    return 0;
}