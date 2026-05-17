class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Number of rows in the matrix
        int ROWS = matrix.size();

        // Number of columns (taken from first row since it's a vector of vectors)
        // matrix[0] = first row → matrix[0].size() = number of columns
        int COLS = matrix[0].size();

        // Treat the 2D matrix as a flattened 1D sorted array
        int l = 0;                  // left boundary (start index)
        int r = ROWS * COLS - 1;    // right boundary (last index)

        while(l <= r)
        {
            // Find the middle index (avoids overflow using l + (r-l)/2)
            int m = l + (r - l) / 2;

            // Convert the 1D middle index "m" back into 2D coordinates:
            // row = m / COLS → division gives which row we are in
            int rows = m / COLS;

            // col = m % COLS → remainder gives position inside that row
            int cols = m % COLS;

            // Now compare the target with the matrix element at (rows, cols)
            if(target < matrix[rows][cols])
            {
                r = m - 1;  // move search space to the left half
            }
            else if(target > matrix[rows][cols])
            {
                l = m + 1;  // move search space to the right half
            }
            else {
                return true; // target found
            }
        }
        // Target not found
        return false;
    }
};
