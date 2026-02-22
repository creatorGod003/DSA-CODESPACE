#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> numMap = {"?#", "abc", "def", "ghi", "jkl", "mnop", "qrst", "uv", "wxyz", ".;"};

void printKeyPadCombination(string s, string ans){
    if(s.size() == 0){
        cout<<ans<<endl;
        return;
    }
    
    int asciiValue = s[0] - 48; 
    for(char ch: numMap[asciiValue]){
        printKeyPadCombination( s.substr(1, s.size()-1), ans+ch);
    }
}

int main()
{
    string s = "123";
    string ans = "";
    printKeyPadCombination(s, ans);
    return 0;
}