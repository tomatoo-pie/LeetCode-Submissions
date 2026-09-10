class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, 
             vector<int>& vis, vector<int>& pathvis, 
             vector<int>& order) {
        
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathvis, order))
                    return true;
            }
            else if (pathvis[it]) {
                return true;  // cycle found
            }
        }

        pathvis[node] = 0;
        order.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);

        // prerequisite: [course, prerequisite]
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathvis, order))
                    return {};
            }
        }

        reverse(order.begin(), order.end());

        return order;
    }
};