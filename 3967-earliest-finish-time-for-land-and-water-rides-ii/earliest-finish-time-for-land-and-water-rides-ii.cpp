class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        
        vector<pair<int,int>> water;
        for (int i = 0; i < m; i++) {
            water.push_back({waterStartTime[i], waterDuration[i]});
        }

        sort(water.begin(), water.end());

        vector<int> wStarts(m);
        vector<long long> prefDur(m), suffFinish(m);

        for (int i = 0; i < m; i++) {
            wStarts[i] = water[i].first;

            if (i == 0)
                prefDur[i] = water[i].second;
            else
                prefDur[i] = min(prefDur[i - 1],
                                 (long long)water[i].second);
        }

        for (int i = m - 1; i >= 0; i--) {
            long long cur =
                (long long)water[i].first + water[i].second;

            if (i == m - 1)
                suffFinish[i] = cur;
            else
                suffFinish[i] = min(suffFinish[i + 1], cur);
        }

        for (int i = 0; i < n; i++) {
            long long A =
                (long long)landStartTime[i] + landDuration[i];

            int idx = upper_bound(wStarts.begin(),
                                  wStarts.end(),
                                  A) - wStarts.begin();

            long long best = LLONG_MAX;

            if (idx > 0) {
                best = min(best, A + prefDur[idx - 1]);
            }

            if (idx < m) {
                best = min(best, suffFinish[idx]);
            }

            ans = min(ans, best);
        }

        // ---------- Water -> Land ----------
        vector<pair<int,int>> land;
        for (int i = 0; i < n; i++) {
            land.push_back({landStartTime[i], landDuration[i]});
        }

        sort(land.begin(), land.end());

        vector<int> lStarts(n);
        vector<long long> prefDurLand(n), suffFinishLand(n);

        for (int i = 0; i < n; i++) {
            lStarts[i] = land[i].first;

            if (i == 0)
                prefDurLand[i] = land[i].second;
            else
                prefDurLand[i] = min(prefDurLand[i - 1],
                                     (long long)land[i].second);
        }

        for (int i = n - 1; i >= 0; i--) {
            long long cur =
                (long long)land[i].first + land[i].second;

            if (i == n - 1)
                suffFinishLand[i] = cur;
            else
                suffFinishLand[i] = min(suffFinishLand[i + 1], cur);
        }

        for (int i = 0; i < m; i++) {
            long long B =
                (long long)waterStartTime[i] + waterDuration[i];

            int idx = upper_bound(lStarts.begin(),
                                  lStarts.end(),
                                  B) - lStarts.begin();

            long long best = LLONG_MAX;

            if (idx > 0) {
                best = min(best, B + prefDurLand[idx - 1]);
            }
            if (idx < n) {
                best = min(best, suffFinishLand[idx]);
            }

            ans = min(ans, best);
        }

        return (int)ans;
    }
};