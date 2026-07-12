class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        long long sum = 0;
        for (int x : nums) sum += x;

        long long ops = 0;
        if (sum > k) {
            ops = (sum - k + k - 1) / k;
        }

        long long a = ops % MOD;
        long long b = (ops + 1) % MOD;

        return a * b % MOD * ((MOD + 1) / 2) % MOD;
    }
};