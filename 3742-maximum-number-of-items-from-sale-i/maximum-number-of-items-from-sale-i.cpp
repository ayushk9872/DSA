class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        vector<int> gain(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    ++gain[i];
                }
            }
        }

        vector<pair<int, int>> sortedItems;
        sortedItems.reserve(n);
        for (int i = 0; i < n; ++i) {
            sortedItems.emplace_back(items[i][1], gain[i]);
        }
        sort(sortedItems.begin(), sortedItems.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        const int NEG_INF = -1e9;
        vector<int> dp(budget + 1, NEG_INF);
        dp[0] = 0;

        int ans = 0;
        for (const auto& [price, g] : sortedItems) {
            if (price > budget) continue;

            for (int c = budget; c >= price; --c) {
                if (dp[c - price] != NEG_INF) {
                    int total = dp[c - price] + g + (budget - c) / price;
                    if (total > ans) {
                        ans = total;
                    }
                }
            }

            for (int c = budget; c >= price; --c) {
                if (dp[c - price] != NEG_INF && dp[c - price] + g > dp[c]) {
                    dp[c] = dp[c - price] + g;
                }
            }
        }

        return ans;
    }
};