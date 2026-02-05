/*
Description

You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.
Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.
The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.
Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

Constraints:

2 <= n <= 5 * 104
1 <= edges.length <= 105
edges[i] = [ui, vi, wi]
0 <= ui, vi <= n - 1
1 <= wi <= 1000

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        //code
    }
};

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Build adjacency list: outgoing edges
        vector<vector<pair<int, int>>> adj(n);           // adj[u] = {v, w}
        // Also build incoming for each node to quickly get reversal candidates
        vector<vector<pair<int, int>>> in_adj(n);        // in_adj[u] = {x, w} where x→u with weight w
        
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            in_adj[v].emplace_back(u, w);   // x = u, target = v, so incoming to v from u
        }
        
        // dist[node][used] : 0 = not used switch yet, 1 = already used
        const long long INF = 1LL << 60;
        vector<vector<long long>> dist(n, vector<long long>(2, INF));
        dist[0][0] = 0;
        
        // {cost, node, used_flag}
        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(0, 0, 0);
        
        while (!pq.empty()) {
            auto [cost, u, used] = pq.top();
            pq.pop();
            
            if (cost > dist[u][used]) continue;
            
            // 1. Normal outgoing edges
            for (auto [v, w] : adj[u]) {
                long long ncost = cost + w;
                int next_used = 0;  // arriving at v, switch still available
                if (ncost < dist[v][next_used]) {
                    dist[v][next_used] = ncost;
                    pq.emplace(ncost, v, next_used);
                }
            }
            
            // 2. Reversal — only if we still have the switch at u
            if (used == 0) {
                for (auto [x, w] : in_adj[u]) {   // x → u originally with weight w
                    long long ncost = cost + 2LL * w;
                    int next_used = 0;  // arriving at x, its switch is still available
                    if (ncost < dist[x][next_used]) {
                        dist[x][next_used] = ncost;
                        pq.emplace(ncost, x, next_used);
                    }
                }
                // Note: after reversal we could also stay conceptually at u with used=1,
                // but since reversal forces immediate move, we don't add (u,1) explicitly here
            }
        }
        
        long long ans = min(dist[n-1][0], dist[n-1][1]);
        return (ans >= INF) ? -1 : (int)ans;
    }
};


int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {3, 1, 1},
        {2, 3, 4},
        {0, 2, 2}
    };
    cout << sol.minCost(n, edges) << endl; // Output the minimum cost
    return 0;
}
