bool reachDestinationHelper(vector<vector<int>> &maze, int m, int n, int startX, int startY, int destX, int destY, vector<bool> visited[])
{

    // Return true if coordinates of start and destination are same.
    if (startX == destX && startY == destY)
        return true;

    // Return false if current cell is already visited.
    if (visited[startX][startY] == true)
        return false;

    // Initializing 1-D array to store directions.
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Mark current cell as visited.
    visited[startX][startY] = true;

    // Iterate for every direction.
    for (int i = 0; i < 4; i++)
    {
        // Variables to store starting position.
        int currentX = startX;
        int currentY = startY;

        // Variables to store shift in horizontal or vertical direction.
        int shiftX = directions[i][0];
        int shiftY = directions[i][1];

        // Increment the shift values until wall is not reached or cell value is not '1'
        while (currentX >= 0 && currentX < m && currentY >= 0 && currentY < n && maze[currentX][currentY] == 0)
        {
            currentX = currentX + shiftX;
            currentY = currentY + shiftY;
        }

        // Decrement current position by shift values.
        currentX = currentX - shiftX;
        currentY = currentY - shiftY;

        // Recursively check for current cell it value at current cell is not '0'.
        if (!visited[currentX][currentY] && reachDestinationHelper(maze, m, n, currentX, currentY, destX, destY, visited))
            return true;
    }
    
    // Return false if no path is found to reach destination.
    return false;
}

bool reachDestination(vector<vector<int>> &maze, int m, int n, int startX, int startY, int destX, int destY)
{
    // Initializing 'visited' array.
    vector<bool> visited[m];
    for (int i = 0; i < m; i++)
    {
        vector<bool> v(n);
        visited[i] = v;
    }

    // Recursive function to check if there is path or not.
    return reachDestinationHelper(maze, m, n, startX, startY, destX, destY, visited);
}
