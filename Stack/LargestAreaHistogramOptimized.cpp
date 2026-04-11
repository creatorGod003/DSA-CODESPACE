#include <iostream>
#include <stack>
#include <vector>
#include "../utilities/utilities.h"

using namespace std;

int largestAreaHistogram(vector<int> values){

    if(values.size() == 0){
        return 0;
    }

    vector<int> mfl(values.size() , 0);
    stack<int> st1;
    st1.push(0);
    mfl[0] = 0;

    vector<int> mfr(values.size() , 0);
    stack<int> st2;
    st2.push(values.size()-1);
    mfr[values.size()-1] = values.size()-1;

    for(int i=1,j=values.size()-2;i<values.size() && j>=0;i++, j--){

        while(st1.size()!=0 && values[st1.top()]>=values[i]){
            st1.pop();
        }

        if(st1.size() == 0){
            mfl[i] = 0;
        }
        else{
            mfl[i] = st1.top() + 1;
        }

        st1.push(i);


        while(st2.size()!=0 && values[st2.top()]>=values[j]){
            st2.pop();
        }

        if(st2.size() == 0){
            mfr[j] = values.size() - 1;
        }
        else{
            mfr[j] = st2.top() -1;
        }
        st2.push(j);

    }

    int largestArea = 0;

    for(int i=0;i<values.size();i++){
        int area = (mfr[i]-mfl[i]+1)*values[i];
        if(area>largestArea){
            largestArea = area;
        }
    }

    return largestArea;

}

int main() {
    vector<int> values = {6,4,10,3,3,8,4,10};
    // vector<int> values = {3,6,2,4,8};
    int largestArea = largestAreaHistogram(values);
    cout<<largestArea;
    return 0;
} 