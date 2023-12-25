// rat maze problem

// in this method the different paths are created simultaneously creating a tree like structure // no pushabck/popback is required as we are adding the path in the recursive call itself(LDRU)

// time complexity O(4^n)
// space complexity O(n^2) for visited matrix

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ;

bool isSafe(vector<vector<int>> &maze, int n, int x, int y, vector<vector<int>> &visited){
    if(x < 0 || x >= n || y < 0 || y >= n || maze[x][y] == 0 || visited[x][y] == 1){
        return false ;
    }
    return true ;
}

void solveMaze(vector<vector<int>> &maze, int n, int srcX, int srcY, vector<vector<int>> &visited, string path, vector<string> &ans){
    // base case
    if(srcX == n-1 && srcY == n-1){
        ans.push_back(path) ;
        return ;
    }

    // recursive case
    // go down
    if(isSafe(maze, n, srcX+1, srcY, visited)){
        visited[srcX+1][srcY] = 1 ;
        solveMaze(maze, n, srcX+1, srcY, visited, path + "D", ans) ;
        visited[srcX+1][srcY] = 0 ;
    }

    // go left
    if(isSafe(maze, n, srcX, srcY-1, visited)){
        visited[srcX][srcY-1] = 1 ;
        solveMaze(maze, n, srcX, srcY-1, visited, path + "L", ans) ;
        visited[srcX][srcY-1] = 0 ;
    }

    // go right
    if(isSafe(maze, n, srcX, srcY+1, visited)){
        visited[srcX][srcY+1] = 1 ;
        solveMaze(maze, n, srcX, srcY+1, visited, path + "R", ans) ;
        visited[srcX][srcY+1] = 0 ;
    }

    // go up
    if(isSafe(maze, n, srcX-1, srcY, visited)){
        visited[srcX-1][srcY] = 1 ;
        solveMaze(maze, n, srcX-1, srcY, visited, path + "U", ans) ;
        visited[srcX-1][srcY] = 0 ;
    }
}

vector<string> findPath(vector<vector<int>> &maze, int n){
    vector<string> ans ;
    int srcX = 0, srcY = 0 ;

    if(maze[0][0] == 0 || maze[n-1][n-1] == 0){
        return ans ;
    }

    // initialize visited matrix
    vector<vector<int>> visited = maze ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0 ;
        }
    }

    string path = "" ;
    solveMaze(maze, n, srcX, srcY, visited, path, ans) ;
    sort(ans.begin(), ans.end()) ;
    return ans ;
}

int main(){

    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 1, 0},
                                {0, 1, 1, 1}} ;

    int n = maze.size() ;
    vector<string> ans = findPath(maze, n) ;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " " ;
    }
    cout << endl ;
    
    return 0 ;
}
