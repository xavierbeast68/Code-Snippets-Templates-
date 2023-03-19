// Function returns true if the
// move taken is valid else
// it will return false.
bool isSafe(int row, int col, int m[][MAX], int n, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1 || col == n || visited[row][col] || m[row][col] == 0)
        return false;

    return true;
}

// Function to print all the possible
// paths from (0, 0) to (n-1, n-1).
void printPathUtil(int row, int col, int m[][MAX], int n, string &path, vector<string> &possiblePaths, bool visited[][MAX])
{
    // This will check the initial point
    // (i.e. (0, 0)) to start the paths.
    if (row == -1 || row == n || col == -1 || col == n || visited[row][col] || m[row][col] == 0)
        return;

    // If reach the last cell (n-1, n-1)
    // then store the path and return
    if (row == n - 1 && col == n - 1)
    {
        possiblePaths.push_back(path);
        return;
    }

    // Mark the cell as visited
    visited[row][col] = true;

    // Try for all the 4 directions (down, left,
    // right, up) in the given order to get the
    // paths in lexicographical order

    // Check if downward move is valid
    if (isSafe(row + 1, col, m, n, visited))
    {
        path.push_back('D');
        printPathUtil(row + 1, col, m, n, path, possiblePaths, visited);
        path.pop_back();
    }

    // Check if the left move is valid
    if (isSafe(row, col - 1, m, n, visited))
    {
        path.push_back('L');
        printPathUtil(row, col - 1, m, n, path, possiblePaths, visited);
        path.pop_back();
    }

    // Check if the right move is valid
    if (isSafe(row, col + 1, m, n, visited))
    {
        path.push_back('R');
        printPathUtil(row, col + 1, m, n, path, possiblePaths, visited);
        path.pop_back();
    }

    // Check if the upper move is valid
    if (isSafe(row - 1, col, m, n, visited))
    {
        path.push_back('U');
        printPathUtil(row - 1, col, m, n, path, possiblePaths, visited);
        path.pop_back();
    }

    // Mark the cell as unvisited for
    // other possible paths
    visited[row][col] = false;
}



//* -----another template-----
// void dfs(temp, ans, vector<vector<int>>& m, int n, int row, int col){
//     if(row == (n-1) && col == (n-1)){
//         // ans++;
//         return;
//     }
    
//     // down
//     if(row+1 < n && m[row+1][col] == 1){
//         m[row][col] = 0; // marked visited
//         dfs(temp, ans, m, n, row+1, col);
//         m[row][col] = 1;
//     }
    
//     // up
//     if(row-1 >= 0 && m[row-1][col] == 1){
//         m[row][col] = 0; // marked visited
//         dfs(temp, ans, m, n, row-1, col);
//         m[row][col] = 1;
//     }
    
//     // right
//     if(col+1 < n && m[row][col+1] == 1){
//         m[row][col] = 0; // marked visited
//         dfs(temp, ans, m, n, row, col+1);
//         m[row][col] = 1;
//     }
    
//     // left
//     if(col-1 >= 0 && m[row][col-1] == 1){
//         m[row][col] = 0; // marked visited
//         dfs(temp, ans, m, n, row, col-1);
//         m[row][col] = 1;
//     }
// }