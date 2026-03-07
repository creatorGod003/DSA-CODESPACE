#include <iostream>
#include <vector>
using namespace std;

void printTargetSumSubset(vector<int> &arr, int sum, vector<int> &subset, int ind, int ssf){
    
    if(ind == arr.size()){
        
        if(ssf == sum){
            for(int x: subset){
                cout<< x << " ";
            }
            cout<<endl;
        }
        
        return;
    }
    
    printTargetSumSubset(arr, sum, subset, ind+1, ssf);
    subset.push_back(arr[ind]);
    printTargetSumSubset(arr, sum, subset, ind+1, ssf+arr[ind]);
    subset.pop_back();
    
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int sum = 6;
    vector<int> subset={};
    int ssf=0;
    printTargetSumSubset(arr, sum, subset, 0, ssf);
    return 0;
}