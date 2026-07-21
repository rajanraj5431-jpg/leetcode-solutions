class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        vector<int> prefS(n + 1, 0);
        int totalOnes = 0;
        for (int i = 0; i < n; i++) {
            totalOnes += (s[i] == '1');
            prefS[i + 1] = totalOnes;
        }

        vector<bool> ans;

        for (string &t : strs) {
            int fixedOnes = 0, q = 0;
            for (char c : t) {
                if (c == '1') fixedOnes++;
                else if (c == '?') q++;
            }

            int need = totalOnes - fixedOnes;

            if (need < 0 || need > q) {
                ans.push_back(false);
                continue;
            }

            vector<char> a(t.begin(), t.end());

            // Greedily place required '1's as far right as possible.
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] == '?') {
                    if (need > 0) {
                        a[i] = '1';
                        need--;
                    } else {
                        a[i] = '0';
                    }
                }
            }

            bool ok = true;
            int pref = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == '1') pref++;
                if (pref > prefS[i + 1]) {
                    ok = false;
                    break;
                }
            }

            ans.push_back(ok);
        }

        return ans;
    }
};