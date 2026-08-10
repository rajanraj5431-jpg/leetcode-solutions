class Solution {
public:
    int numSplits(string s) {
        int n = s.length();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int freq[26] = {0};
        int distinct = 0;

        // Distinct characters from left
        for(int i = 0; i < n; i++) {
            if(freq[s[i] - 'a'] == 0)
                distinct++;

            freq[s[i] - 'a']++;
            left[i] = distinct;
        }

        // Reset
        memset(freq, 0, sizeof(freq));
        distinct = 0;

        // Distinct characters from right
        for(int i = n - 1; i >= 0; i--) {
            if(freq[s[i] - 'a'] == 0)
                distinct++;

            freq[s[i] - 'a']++;
            right[i] = distinct;
        }

        int ans = 0;

        // Split between i and i+1
        for(int i = 0; i < n - 1; i++) {
            if(left[i] == right[i + 1])
                ans++;
        }

        return ans;
    }
};