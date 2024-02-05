/** https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1 */

// TC - O(N+E) + O(E logE) + O(E*4α*2)   where N = no. of nodes and E = no. of edges. O(N+E) for extracting edge information from the adjacency list. O(E logE) for sorting the array consists of the edge tuples. Finally, we are using the disjoint set operations inside a loop. The loop will continue to E times. Inside that loop, there are two disjoint set operations like findUPar() and UnionBySize() each taking 4 and so it will result in 4*2. That is why the last term O(E*4*2) is added.

// SC - O(N) + O(N) + O(E) where E = no. of edges and N = no. of nodes. O(E) space is taken by the array that we are using to store the edge information. And in the disjoint set data structure, we are using two N-sized arrays i.e. a parent and a size array (as we are using unionBySize() function otherwise, a rank array of the same size if unionByRank() is used) which result in the first two terms O(N).

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt, u, v});
            }
        }
        
          sort(edges.begin(), edges.end());
          int minCost = 0;
          DisjointSet ds(V);
        
          for (int i = 0; i < edges.size(); i++) {
            int wt = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
        
            if (ds.findUPar(u) != ds.findUPar(v)) {
              minCost += wt;
              ds.unionBySize(u, v);
            } 
          }
        
          return minCost;
    }
};