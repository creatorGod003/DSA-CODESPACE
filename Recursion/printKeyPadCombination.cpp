#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> numMap = {"?#", "abc", "def", "ghi", "jkl", "mnop", "qrst", "uv", "wxyz", ".;"};

vector<string> getKeyPadCombination(string numStr){
    
    if(numStr.size() == 0){
        vector<string> baseCase = {""};
        return baseCase;
    }
    
    vector<string> pNumComb = getKeyPadCombination(numStr.substr(1, numStr.size()-1));
    int asciiVal = numStr[0]-48;
    
    vector<string> numComb;
    
    for(char ch: numMap[asciiVal]){
        for(string str: pNumComb){
            numComb.push_back(ch+str);
        }
    }
    
    return numComb;
}

void printVector(vector<string> vec){
    for (string str: vec) {
        cout << str << " ";
    }
    cout << "\n";
}

int main()
{
    string str = "012";
    vector<string> keypadComb = getKeyPadCombination(str);
    printVector(keypadComb);
    cout<<keypadComb.size();
    return 0;
}