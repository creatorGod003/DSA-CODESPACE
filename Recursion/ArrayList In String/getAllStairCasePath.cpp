#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> getAllStairCasePaths(int n){
    
    if(n==0){
        vector<string> baseCase = {""};
        return baseCase;
    }
    else if(n<0){
        vector<string> baseCase={};
        return baseCase;
    }
    
    vector<string> allPath;
    
    vector<string> p1 = getAllStairCasePaths(n-1);
    for(string s: p1){
        allPath.push_back("1"+s);
    }
    
    vector<string> p2 = getAllStairCasePaths(n-2);
    for(string s: p2){
        allPath.push_back("2"+s);
    }
    
    vector<string> p3 = getAllStairCasePaths(n-3);
    for(string s: p3){
        allPath.push_back("3"+s);
    }   
    
    return allPath;
}

void printVector(vector<string> vec){
    for (string str: vec) {
        cout << str << " ";
    }
    cout << "\n";
}

int main()
{
    int stairLevel = 5;
    vector<string> stairPaths = getAllStairCasePaths(stairLevel);
    printVector(stairPaths);
    return 0;
}