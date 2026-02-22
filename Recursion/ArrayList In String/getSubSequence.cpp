#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> getSS(string str){
    
    if(str.size() == 0){
        vector<string> baseSS = {""};
        return baseSS;
    }
    
    char ch = str[0];
    string pString = str.substr(1, str.size()-1);
    vector<string> pss = getSS(pString);
    
    vector<string> ss;
    
    for(string tempStr: pss){
        ss.push_back(tempStr);
        ss.push_back(ch+tempStr);
    }
    return ss;
}

void printVector(vector<string> vec){
    for (string str: vec) {
        cout << str << " ";
    }
    cout << "\n";
}

int main()
{
    string str = "aaa";
    vector<string> ss = getSS(str);

    printVector(ss);
    cout<<ss.size();
    
    return 0;
}