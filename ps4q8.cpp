#include <bits/stdc++.h>
using namespace std;
int main()
{
    int rows, cols;
    cin >> rows >> cols;
    if (rows > cols)
        swap(rows, cols);
    int maxi = 1e9;
    vector<vector<int>> grid(rows, vector<int>(cols, maxi));
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; ++col)
        {
            if (row > col)
                grid[row][col] = grid[col][row];
            else if (row == col)
                grid[row][col] = 0;
            else
            {
                for (int i = 0; i < row; i++)
                {
                    int cut = 1 + grid[i][col] + grid[row - i - 1][col];
                    grid[row][col] = min(grid[row][col], cut);
                }
                for (int i = 0; i < col; i++)
                {
                    int cut = 1 + grid[row][i] + grid[row][col - i - 1];
                    grid[row][col] = min(grid[row][col], cut);
                }
            }
        }
    }
    cout << grid[rows - 1][cols - 1];
    return 0;
}
