class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix[i] = total stones from i to n-1
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M] = maximum stones current player can get
        // starting from index i with current M
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int M = n; M >= 1; M--) {

                // Can take all remaining piles
                if (i + 2 * M >= n) {
                    dp[i][M] = suffix[i];
                    continue;
                }

                for (int X = 1; X <= 2 * M; X++) {
                    int nextM = max(M, X);

                    // Current player gets:
                    // total remaining - opponent's best possible score
                    dp[i][M] = max(
                        dp[i][M],
                        suffix[i] - dp[i + X][nextM]
                    );
                }
            }
        }

        return dp[0][1];
    }
};