#include <stdio.h>
#include <limits.h>
#define V 4 
#define N (1 << V)

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int graph[][V]) {
    int dp[N][V];
    for (int mask = 0; mask < N; mask++) {
        for (int i = 0; i < V; i++) {
            dp[mask][i] = INT_MAX;
        }
    }
    dp[1][0] = 0;
    
    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < V; u++) {
            if ((mask & (1 << u)) != 0) {
                for (int v = 0; v < V; v++) {
                    if ((mask & (1 << v)) != 0 && u != v) {
                        dp[mask][u] = min(dp[mask][u], dp[mask ^ (1 << u)][v] + graph[v][u]);
                    }
                }
            }
        }
    }
    
    int final_mask = N - 1;
    int minDistance = INT_MAX;
    
    for (int u = 1; u < V; u++) {
        minDistance = min(minDistance, dp[final_mask][u] + graph[u][0]);
    }
    
    return minDistance;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int minDistance = tsp(graph);

    printf("Minimum TSP distance: %d\n", minDistance);

    return 0;
}

