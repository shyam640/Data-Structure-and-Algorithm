void dfs(vector<int> &arr, vector<int> &positions, int currentCell, int totalLengthCovered, vector<int> &visited, int &res){
// If the current cell is already visited
    if (visited[currentCell] == 1){
        return;
    }

    // If there is no exit from this cell
    if (arr[currentCell] == -1){
        visited[currentCell] = 1;
        return;
    }

    // We have found a cycle.
    if (positions[currentCell] != -1){
        // Update the maximum length.
        res = max(res, totalLengthCovered - positions[currentCell]);
        visited[currentCell] = 1;
        return;
    }


    positions[currentCell] = totalLengthCovered;

    // Recur for the next cell.
    dfs(arr, positions, arr[currentCell], totalLengthCovered + 1, visited, res);

    // Mark the current cell as visited.
    visited[currentCell] = 1;
    positions[currentCell] = -1;
}


int findLongestCycle(vector<int> &arr){
    int n = arr.size();
    // For storing the visited vertices.
    vector<int> visited(n, 0);
    vector<int> positions(n, -1);
    int res = 0;

    // Iterate through the cells.    
    for (int i = 0; i < n; i++){
        if (visited[i] == 0){
            dfs(arr, positions, i, 0, visited, res);
        }
    }

    // There is no cycle
    if (res == 0){
        return -1;
    }

    return res;
}
