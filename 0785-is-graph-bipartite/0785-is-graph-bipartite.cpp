class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        queue<int> q;

        for(int i = 0; i < n; i++) {

            if(vis[i] != -1)
                continue;

            q.push(i);
            vis[i] = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(int j = 0; j < graph[node].size(); j++) {
                    int nod = graph[node][j];

                    if(vis[nod] == -1) {
                        vis[nod] = 1 - vis[node];
                        q.push(nod);
                    }
                    else if(vis[nod] == vis[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};