#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestAreaHistogram(vector<int> values){

    if(values.size() == 0){
        return -1;
    }

    int largestArea = -1;

    stack<int> st;
    st.push(0);

    vector<int> areaAtAIndex(values.size(), 0);

    areaAtAIndex[0] = values[0] * ( 0 - ( -1 ));

    if(largestArea < areaAtAIndex[0]){
        largestArea = areaAtAIndex[0];
    }

    for(int i=1;i<values.size(); i++){

        while(st.size()!=0 && values[st.top()] > values[i]){
            st.pop();
        }

        int minIndex = -1;

        if(st.size()!=0){
            minIndex = st.top();
        }

        cout<< "Inside for loop index ="<<i << "-> min index =" << minIndex<<endl;

        // Normal Area
        areaAtAIndex[i] = values[i] * ( i - minIndex);
        
        cout<<"Area at index "<< i << " "<<areaAtAIndex[i]<<endl;
        
        
        if(largestArea < areaAtAIndex[i]){
            largestArea = areaAtAIndex[i];
        }

        if(minIndex == -1){
            st.push(i);
            continue;
        }

        // Exploring Other Areas
        stack<int> tempStack;

        while(st.size()!=0){
            int ele = st.top();
            st.pop();

            int otherArea = areaAtAIndex[ele] + values[ele] * ( i - ele);
            cout<<"Other Area "<< ele << " to "<< i <<" "<<otherArea<<endl;
            tempStack.push(ele);

            if(otherArea > largestArea){
                largestArea = otherArea;
            }
        }

        while(tempStack.size()!=0){
            st.push(tempStack.top());
            tempStack.pop();
        }

        st.push(i);

    }
    

    return largestArea;

}

int main() {
    vector<int> values = {8,3,2,2,1};
    int largestArea = largestAreaHistogram(values);
    cout << largestArea << endl;
    return 0;
}