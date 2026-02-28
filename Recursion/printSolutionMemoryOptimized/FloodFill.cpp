#include <iostream>
#include <vector>
using namespace std;

void floodFill(vector<vector<int>> maze, int rows, int cols, string psf, vector<vector<bool>> &visited){
    
    if(rows == maze.size()-1 && cols == maze[0].size() - 1){
        cout<<psf<<endl;
        return;
    }
    else if(maze[rows][cols] == 1 || visited[rows][cols] == true){
        return;
    }
    
    visited[rows][cols] = true;
    
    if(rows>=1)
        floodFill(maze, rows-1, cols, psf+"t", visited);
    
    if(cols<maze[0].size()-1)
        floodFill(maze, rows, cols+1, psf+"r", visited);
    
    if(rows<maze.size() -1)
        floodFill(maze, rows+1, cols, psf+"d", visited);
    
    if(cols>=1)
        floodFill(maze, rows, cols-1, psf+"l", visited);
    
    visited[rows][cols] = false;
    
}

int main()
{
    int rows, cols;
    cout<< "Enter number of rows: ";
    cin >> rows;
    cout<< "Enter number of columns: ";
    cin >> cols;
    
    vector<vector<int>> maze(rows, vector<int>(cols, 0));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    cout<<"== Maze Initialized ==\n";
    
    cout << "Enter " << rows * cols << " integers:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(cin >> maze[i][j])) {
                cerr << "Invalid input. Please enter integers only.\n";
                return 1;
            }
        }
    }
    
    floodFill(maze, 0, 0, "", visited);
    
    cout << "Maze is: "<<endl;
    
    for(const auto &row: maze){
        for(int x: row){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}