#include <iostream>
#include <vector> // for using vector
#include <string> // for using string and its functions
#include <algorithm> // for using min function
using namespace std;

vector<string> getMazePathsWithJumps(int sr, int sc, int dr, int dc){
    
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
    
    for(int i=1;i<=dc;i++){
        vector<string> hPaths = getMazePathsWithJumps(sr, sc+i, dr, dc);
        for(string hPath: hPaths){
            paths.push_back("h"+to_string(i)+hPath);
        }   
    } 
    
    for(int i=1;i<=dr;i++){
        vector<string> vPaths = getMazePathsWithJumps(sr+i, sc, dr, dc);
        for(string vPath: vPaths){
            paths.push_back("v"+to_string(i)+vPath);
        }   
    }    
    
    for(int i=1;i<=min(dr, dc);i++){
        vector<string> dPaths = getMazePathsWithJumps(sr+i, sc+i, dr, dc);
        for(string dPath: dPaths){
            paths.push_back("d"+to_string(i)+dPath);
        }   
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
    
    vector<string> paths = getMazePathsWithJumps(0, 0, dr, dc);
    cout<<"Possible paths are: "<<endl;
    printVector(paths);
    
    return 0;
}