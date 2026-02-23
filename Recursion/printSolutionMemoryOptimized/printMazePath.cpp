#include <iostream>
#include <string>
using namespace std;

void printMazePath(int sr, int sc, int dr, int dc, string path){
    
    if(sr>dr || sc>dc){
        return;
    }
    if(sr==dr && sc==dc){
        cout<<path<<endl;
        return;
    }
    
    printMazePath(sr, sc+1, dr, dc, path+"h");
    printMazePath(sr+1, sc, dr, dc, path+"v");
    
}

int main()
{
    int n=2,m=2;
    printMazePath(0,0, m, n, "");
    
    return 0;
}