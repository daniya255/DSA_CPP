#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int row, int col)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;

    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + dRow[i];
            int ncol = c + dCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty() || grid[0].empty())
        return 0;

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int count = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] && grid[row][col] == '1')
            {
                count++;
                bfs(grid, vis, row, col);
            }
        }
    }

    return count;
}
int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    int count = numIslands(grid);
    cout << "Number of islands : " << count << endl;

    return 0;
}