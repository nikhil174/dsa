// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<pair<int, int>> edges;
    edges.push_back({ 0, 1});
    edges.push_back({ 1, 2});
    edges.push_back({ 2, 3});
    edges.push_back({ 2, 4});

    // adjacency matrix
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (auto it : edges) {
        int u = it.first;
        int v = it.second;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            cout << adj[u][v] << " ";
        }
        cout << endl;
    }

    // list representation
    vector<int> adjList[n];
    for (auto it : edges) {
        int u = it.first;
        int v = it.second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int node = 0; node < n; node++) {
        cout << node << " == ";
        for (auto it : adjList[node]) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}