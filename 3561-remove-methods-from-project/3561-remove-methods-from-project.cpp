class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<unordered_set<int>> graph(n);
        vector<int> inDegree(n, 0);

        for (auto& invocation : invocations) {
            int a = invocation[0], b = invocation[1];
            graph[a].insert(b);
            inDegree[b]++;
        }

        unordered_set<int> suspicious;
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (suspicious.find(current) == suspicious.end()) {
                suspicious.insert(current);
                for (int neighbor : graph[current]) {
                    q.push(neighbor);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (suspicious.find(i) == suspicious.end()) {
                for (int neighbor : graph[i]) {
                    if (suspicious.find(neighbor) != suspicious.end()) {
                        vector<int> allMethods(n);
                        for (int j = 0; j < n; ++j) {
                            allMethods[j] = j;
                        }
                        return allMethods;
                    }
                }
            }
        }

        vector<int> remaining;
        for (int i = 0; i < n; ++i) {
            if (suspicious.find(i) == suspicious.end()) {
                remaining.push_back(i);
            }
        }

        return remaining;
    }
};