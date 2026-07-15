class Solution {
public:
    double dfs(
        string current,
        string target,
        unordered_map<string, vector<pair<string, double>>>& graph,
        unordered_set<string>& visited,
        double product
    ) {
        if (current == target) {
            return product;
        }

        visited.insert(current);

        for (auto& edge : graph[current]) {
            string next = edge.first;
            double weight = edge.second;

            if (visited.find(next) == visited.end()) {
                double result = dfs(
                    next,
                    target,
                    graph,
                    visited,
                    product * weight
                );

                if (result != -1.0) {
                    return result;
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            graph[a].push_back({b, values[i]});
            graph[b].push_back({a, 1.0 / values[i]});
        }

        vector<double> answers;

        for (auto& query : queries) {
            string start = query[0];
            string target = query[1];

            if (graph.find(start) == graph.end() ||
                graph.find(target) == graph.end()) {
                answers.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;

            double result = dfs(
                start,
                target,
                graph,
                visited,
                1.0
            );

            answers.push_back(result);
        }

        return answers;
    }
};