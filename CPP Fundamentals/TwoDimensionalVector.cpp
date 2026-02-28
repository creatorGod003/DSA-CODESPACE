#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int rows, cols;
    cout<< "Enter number of rows: ";
    cin >> rows;
    cout<< "Enter number of columns: ";
    cin >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    cout<<"== Matrix Initialized ==\n";
    
    cout << "Enter " << rows * cols << " integers:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(cin >> matrix[i][j])) {
                cerr << "Invalid input. Please enter integers only.\n";
                return 1;
            }
        }
    }
    
    cout << "Matrix is: "<<endl;
    
    for(const auto &row: matrix){
        for(int x: row){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}