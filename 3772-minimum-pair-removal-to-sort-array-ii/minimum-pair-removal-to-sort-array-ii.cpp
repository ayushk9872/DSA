class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<int> left(n), right(n);
        vector<long long> val(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            val[i] = nums[i];
            left[i] = i - 1;
            right[i] = i + 1;
        }
        right[n - 1] = -1;

        int bad = 0;
        for (int i = 1; i < n; i++) {
            if (val[i] < val[i - 1]) bad++;
        }

    
        priority_queue<pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>> pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({val[i] + val[i + 1], i});
        }

        int ops = 0;

        while (bad > 0) {
            
            auto [s, i] = pq.top();
            pq.pop();

            if (!alive[i] || right[i] == -1) continue;
            int j = right[i];
            if (!alive[j]) continue;
            if (val[i] + val[j] != s) continue;

            if (left[i] != -1 && val[i] < val[left[i]]) bad--;
            if (val[j] < val[i]) bad--;
            if (right[j] != -1 && val[right[j]] < val[j]) bad--;

            val[i] += val[j];
            alive[j] = false;

            int r = right[j];
            right[i] = r;
            if (r != -1) left[r] = i;

            if (left[i] != -1 && val[i] < val[left[i]]) bad++;
            if (r != -1 && val[r] < val[i]) bad++;

            if (left[i] != -1)
                pq.push({val[left[i]] + val[i], left[i]});
            if (right[i] != -1)
                pq.push({val[i] + val[right[i]], i});

            ops++;
        }

        return ops;
    }
};
