// Phạm Quang Đại Phúc
// 22521137

#include <iostream>
using namespace std;

const int INF = 1e9; // Giá trị lớn để biểu diễn vô cực

int findMinDistance(int dist[], bool visited[], int N) {
    int minDist = INF;
    int minIndex = -1;

    for (int i = 0; i < N; ++i) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[100][100], int N, int source) {
    int dist[N];
    bool visited[N];

    for (int i = 0; i < N; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[source] = 0;

    for (int count = 0; count < N - 1; ++count) {
        int u = findMinDistance(dist, visited, N);
        visited[u] = true;

        for (int v = 0; v < N; ++v) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Khoảng cách ngắn nhất từ nút " << source << ":\n";
    for (int i = 0; i < N; ++i) {
        if (dist[i] == INF) {
            cout << "Nút " << i << ": Không thể tới\n";
        }
        else {
            cout << "Nút " << i << ": " << dist[i] << "\n";
        }
    }
}

int main() {
    int N = 5;
    int graph[100][100] = {
        {0, 2, 4, 0, 0},
        {2, 0, 1, 7, 0},
        {4, 1, 0, 3, 0},
        {0, 7, 3, 0, 1},
        {0, 0, 0, 1, 0}
    };

    int source = 0;
    dijkstra(graph, N, source);

    return 0;
}