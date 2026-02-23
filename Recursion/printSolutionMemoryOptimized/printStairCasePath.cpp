#include <iostream>
#include <string>
using namespace std;

void printStairCasePaths(int n, string ans){
    
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(n<0){
        return ;
    }
    
    printStairCasePaths(n-1, ans+"1");
    printStairCasePaths(n-2, ans+"2");
    printStairCasePaths(n-3, ans+"3");
    
}

int main()
{
    int n = 5;
    printStairCasePaths(n, "");
    return 0;
}