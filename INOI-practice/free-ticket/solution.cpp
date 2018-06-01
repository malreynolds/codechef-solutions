#include <iostream>

#define MAX 25600001

using namespace std;

int graph [256][256];

int main() {
    int n, e, x, y, p;
    cin >> n >> e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = -1;
        }
    }
    for (int i = 0; i < e; i++) {
        cin >> x >> y >> p;
        graph[x][y] = p;
        graph[y][x] = p;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == -1) graph[i][j] = MAX;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    int bestPrice = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) bestPrice = max(bestPrice, graph[i][j]);
        }
    }
    cout << bestPrice << endl;
}