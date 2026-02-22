#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getMazePaths(int sr, int sc, int dr, int dc){
    
    if(sc>dc || sr>dr){
        vector<string> baseCase;
        return baseCase;
    }
    if(sc == dc && sr == dr){
        vector<string> baseCase;
        baseCase.push_back("");
        return baseCase;
    }
    
    vector<string> paths;
    
    vector<string> hPaths = getMazePaths(sr, sc+1, dr, dc);
    for(string hPath: hPaths){
        paths.push_back("h"+hPath);
    }    
    
    vector<string> vPaths = getMazePaths(sr+1, sc, dr, dc);
    for(string vPath: vPaths){
        paths.push_back("v"+vPath);
    }    
    
    return paths;
}

void printVector(vector<string> v){
    for(string s: v){
        cout<< s << " ";
    }  
    cout<<endl;
}

int main()
{
    int dr, dc;
    cout<< "Enter No. of rows in maze: ";
    cin>>dr;
    cout<<"Enter No. of columns in maze: ";
    cin>>dc;
    
    vector<string> paths = getMazePaths(0, 0, dr, dc);
    cout<<"Possible paths are: "<<endl;
    printVector(paths);
    
    return 0;
}