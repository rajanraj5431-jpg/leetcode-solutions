class Solution {
public:
    void dfs(int city,
             vector<vector<pair<int, int>>>& graph,
             vector<bool>& visited,
             int& count) {

        visited[city] = true;

        for (auto edge : graph[city]) {
            int nextCity = edge.first;
            int cost = edge.second;

            if (!visited[nextCity]) {
                count += cost;
                dfs(nextCity, graph, visited, count);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& edge : connections) {
            int from = edge[0];
            int to = edge[1];

            graph[from].push_back({to, 1});
            graph[to].push_back({from, 0});
        }

        vector<bool> visited(n, false);

        int count = 0;

        dfs(0, graph, visited, count);

        return count;
    }
};