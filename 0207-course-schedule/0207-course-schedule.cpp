class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adjList, vector<int>& state) {
        // Node is currently being explored
        state[i] = 1;

        for (auto adj : adjList[i]) {

            // Found a node already in the current DFS path
            if (state[adj] == 1) {
                return false;
            }

            // Not visited yet
            if (state[adj] == 0) {
                if (!dfs(adj, adjList, state)) {
                    return false;
                }
            }
        }

        // Completely processed
        state[i] = 2;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for (auto &p : prerequisites) {
            int course = p[0];
            int pre = p[1];

            adjList[pre].push_back(course);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adjList, state)) {
                    return false;
                }
            }
        }

        return true;
    }
};