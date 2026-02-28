#include <iostream>
#include <string>
using namespace std;

void printEncoding(string str, string ans, char alphabets[]){
    
    if(str.size() == 0){
        if(ans.size() !=0){
            cout<<ans<<endl;
        }
        return;
    }
    
    string part1 = str.substr(0, 1);
    
    if(part1[0] == '0'){
        return;
    }
    
    int part1Index = stoi(part1);
    printEncoding(str.substr(1, str.size() - 1), ans+alphabets[part1Index], alphabets);
    
    if(str.size()>=2){
        
        string part2 = str.substr(0, 2);
        
        if(part2[0] == '0'){
            return;
        }
        
        int part2Index = stoi(part2);
        
        if(part2Index >26){
            return;
        }
        
        printEncoding(str.substr(2, str.size() - 2), ans+alphabets[part2Index], alphabets);
    }
    
}

int main()
{
    char alphabets[27];
    alphabets[0] = '_';
    for(int i=0;i<26;i++){
        alphabets[i+1] = 'a'+i;
    }
    
    string str;
    
    cout<<"Enter number:\n";
    cin>>str;

    printEncoding(str, "", alphabets);
    
    return 0;
}