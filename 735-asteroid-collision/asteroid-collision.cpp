class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int x : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && x < 0) {
                if (st.top() < -x) {
                    st.pop();                 // Top asteroid explodes
                }
                else if (st.top() == -x) {
                    st.pop();                 // Both explode
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;         // Current asteroid explodes
                    break;
                }
            }

            if (!destroyed)
                st.push(x);
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};