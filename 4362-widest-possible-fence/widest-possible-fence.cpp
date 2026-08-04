class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long, int> freq;
        for (int x : planks) freq[x]++;

        vector<pair<long long,int>> vals(freq.begin(), freq.end());
        int m = vals.size();

        unordered_map<long long,int> pairCount; // target height -> max disjoint pairs summing to it

        for (int i = 0; i < m; i++) {
            // pair value i with every later distinct value j (avoids double counting)
            for (int j = i + 1; j < m; j++) {
                long long h = vals[i].first + vals[j].first;
                pairCount[h] += min(vals[i].second, vals[j].second);
            }
            // self-pair: two planks of the SAME value combined together
            long long h2 = 2LL * vals[i].first;
            int selfAdd = vals[i].second / 2;
            if (selfAdd > 0) pairCount[h2] += selfAdd;
        }

        int ans = 0;
        // case 1: target height is itself an original value (use as singles + any pairs hitting it)
        for (auto& [v, c] : vals)
            ans = max(ans, c + (pairCount.count(v) ? pairCount[v] : 0));
        // case 2: target height only reachable via pairs, no original plank has that height
        for (auto& [h, pc] : pairCount)
            ans = max(ans, pc + (freq.count(h) ? freq[h] : 0));

        return ans;
    }
};