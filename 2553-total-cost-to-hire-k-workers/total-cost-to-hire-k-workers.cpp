class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> left, right;

        int i = 0;
        int j = n - 1;

        // Fill left heap
        while (i <= j && left.size() < candidates) {
            left.push(costs[i++]);
        }

        // Fill right heap
        while (j >= i && right.size() < candidates) {
            right.push(costs[j--]);
        }

        long long ans = 0;

        while (k--) {
            if (right.empty() || (!left.empty() && left.top() <= right.top())) {
                ans += left.top();
                left.pop();

                if (i <= j) {
                    left.push(costs[i++]);
                }
            } else {
                ans += right.top();
                right.pop();

                if (i <= j) {
                    right.push(costs[j--]);
                }
            }
        }

        return ans;
    }
};