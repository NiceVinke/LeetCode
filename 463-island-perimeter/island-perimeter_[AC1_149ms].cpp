// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
//
// Example:
//
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]
//
// Answer: 16
// Explanation: The perimeter is the 16 yellow stripes in the image below:


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int count = 0;
        int xSize = grid.size();
        int ySize = grid[0].size();
        for (int x = 0; x < xSize; x++) {
            for (int y = 0; y < ySize; y++) {
                if (grid[x][y] == 1) {
                    if (x - 1 < 0 || grid[x - 1][y] == 0)
                        ++count;
                    if (x + 1 > xSize - 1 || grid[x + 1][y] == 0)
                        ++count;
                    if (y - 1 < 0 || grid[x][y - 1] == 0)
                        ++count;
                    if (y + 1 > ySize - 1 || grid[x][y + 1] == 0)
                        ++count;
                }
            }
        }
        return count;
    }

};
