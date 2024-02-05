/* https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1 */

// TC = O(E log E) + O(E) for PQ, SC = O(E)
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> vis(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, 0});
        int sum = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            if (vis[node]) continue;
            vis[node] = true;
            sum += dis;
            
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edWt = it[1];
                
                if (!vis[adjNode])
                    pq.push({ edWt, adjNode});
            }
        }
        
        return sum;
    } 