#include <iostream>
#include <string>
using namespace std;

void printMazePathWithJumps(int sr, int sc, int dr, int dc, string path){
    
    if(sr == dr && sc == dc){
        cout<<path<<endl;
        return;
    }
    
    for(int i=1;i<=dc-sc;i++){
        printMazePathWithJumps(sr, sc+i, dr, dc, path+"h"+to_string(i));    
    }
    for(int i=1;i<=dr-sr;i++){
        printMazePathWithJumps(sr+i, sc, dr, dc, path+"v"+to_string(i));   
    }
    for(int i=1;i<=dr-sr && i<=dc-sc;i++){
        printMazePathWithJumps(sr+i, sc+i, dr, dc, path+"d"+to_string(i));   
    }
    
}

int main()
{
    int n=3,m=3;
    printMazePathWithJumps(0,0, m, n, "");
    
    return 0;
}