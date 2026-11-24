class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = static_cast<int>(isConnected.size());
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++provinces;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int nxt = 0; nxt < n; ++nxt) {
                        if (isConnected[curr][nxt] == 1 && !visited[nxt]) {
                            visited[nxt] = true;
                            q.push(nxt);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};