class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& vis,int i){
        vis[i] = 1;
        for(auto it : adj[i]){
            if(vis[it] == 0)
                dfs(adj,vis,it);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adj(v);

        for(int i = 0 ; i < v ; i++){
            for(int j = 0 ; j < v ; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(v,0);
        int cnt = 0;
        for(int i = 0 ; i < v ; i++){
            if(vis[i] == 0){
                dfs(adj,vis,i);
                cnt++;
            }
        }

        return cnt;
    }
};