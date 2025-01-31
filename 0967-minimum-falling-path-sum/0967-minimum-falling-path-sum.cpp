class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n==1) return mat[0][0];  // If there's only one row, return the only element.

        int ans = INT_MAX;  // Initialize the answer to maximum value
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the first row of DP table
        for(int j = 0; j < n; j++) {
            dp[0][j] = mat[0][j];
        }

        // Fill the DP table starting from the second row
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int down = 1e9, leftDiagonal = 1e9, rightDiagonal = 1e9;

                // Consider the downward path
                down = mat[i][j] + dp[i-1][j];
                // Consider the left diagonal path
                if(j - 1 >= 0) leftDiagonal = mat[i][j] + dp[i-1][j-1];
                // Consider the right diagonal path
                if(j + 1 < n) rightDiagonal = mat[i][j] + dp[i-1][j+1];

                // Update the DP table with the minimum of the three possible paths
                dp[i][j] = min({down, leftDiagonal, rightDiagonal});
                
                // For the last row, update the answer with the minimum value
                if(i == n - 1) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }

        // Return the minimum falling path sum
        return ans;
    }
};