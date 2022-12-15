// GRAPH

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

#define MAX 50
#define INF 999999

struct Graph {
    int numberOfVertex;
    int adjMatrix[MAX][MAX];
};

void createGraph(Graph& graph, int numberOfVertex) {
    graph.numberOfVertex = numberOfVertex;
    for (int i = 0; i < numberOfVertex; i++) {
        for (int j = 0; j < numberOfVertex; j++) {
            graph.adjMatrix[i][j] = INF;
        }
    }
}

void addEdge(Graph& graph, int u, int v, int weight) {
    graph.adjMatrix[u][v] = weight;
    graph.adjMatrix[v][u] = weight;
}

// BFS - Breadth First Search for disconnected graph
void BFS(Graph graph, int start) {
    bool visited[MAX];
    for (int i = 0; i < graph.numberOfVertex; i++) {
        visited[i] = false;
    }
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v = 0; v < graph.numberOfVertex; v++) {
            if (graph.adjMatrix[u][v] != INF && !visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

// Find the path from a source to a destination using BFS
void findPath(Graph graph, int source, int destination) {
    bool visited[MAX];
    int path[MAX];
    for (int i = 0; i < graph.numberOfVertex; i++) {
        visited[i] = false;
    }
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < graph.numberOfVertex; v++) {
            if (graph.adjMatrix[u][v] != INF && !visited[v]) {
                q.push(v);
                visited[v] = true;
                path[v] = u;
            }
        }
    }
    if (visited[destination] == true) {
        int current = destination;
        while (current != source) {
            cout << current << " ";
            current = path[current];
        }
        cout << source << endl;
    }
    else {
        cout << "No path from " << source << " to " << destination << endl;
    }
}

// DFS - Depth First Search for disconnected graph (using recursion)
void DFS(Graph graph, int start, bool visited[]) {
    visited[start] = true;
    cout << start << " ";
    for (int v = 0; v < graph.numberOfVertex; v++) {
        if (graph.adjMatrix[start][v] != INF && !visited[v]) {
            DFS(graph, v, visited);
        }
    }
}

// DFS - Depth First Search for disconnected graph (not using recursion)
void DFSV2(Graph graph, int start) {
    bool visited[MAX];
    for (int i = 0; i < graph.numberOfVertex; i++) {
        visited[i] = false;
    }
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        cout << u << " ";
        for (int v = graph.numberOfVertex - 1; v >= 0; v--) {
            if (graph.adjMatrix[u][v] != INF && !visited[v]) {
                s.push(v);
                visited[v] = true;
            }
        }
    }
}

// Dijkstra - Shortest path from start to all other vertex
void Dijkstra(Graph graph, int start) {
    int dist[MAX];
    bool visited[MAX];
    for (int i = 0; i < graph.numberOfVertex; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[start] = 0;
    for (int i = 0; i < graph.numberOfVertex; i++) {
        int u = -1;
        int min = INF;
        for (int j = 0; j < graph.numberOfVertex; j++) {
            if (!visited[j] && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }
        if (u == -1) {
            return;
        }
        visited[u] = true;
        for (int v = 0; v < graph.numberOfVertex; v++) {
            if (!visited[v] && graph.adjMatrix[u][v] != INF && dist[u] + graph.adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph.adjMatrix[u][v];
            }
        }
    }
    for (int i = 0; i < graph.numberOfVertex; i++) {
        cout << dist[i] << " ";
    }
}

// Find all paths from a source to a destination
void findAllPaths(Graph graph, int source, int destination, bool visited[], int path[], int& pathIndex) {
    visited[source] = true;
    path[pathIndex] = source;
    pathIndex++;
    if (source == destination) {
        for (int i = 0; i < pathIndex; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else {
        for (int v = 0; v < graph.numberOfVertex; v++) {
            if (graph.adjMatrix[source][v] != INF && !visited[v]) {
                findAllPaths(graph, v, destination, visited, path, pathIndex);
            }
        }
    }
    pathIndex--;
    visited[source] = false;
}

// Graph input
// 0 1
// 0 3
// 1 2
// 1 3
// 1 5
// 2 5
// 3 4
// 3 5

int main() {
    Graph graph;
    createGraph(graph, 6);
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 1);