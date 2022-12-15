#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>

using namespace std;

vector<vector<int>> createAdjMatrix(string file_name)
{
    ifstream ss;
    ss.open(file_name);
    if (!ss.is_open())
        exit(6969669);

    int n = 0;
    ss >> n;

    vector<vector<int>> adjMatrix(size_t(n), vector<int>(size_t(n), 0));
    for (vector<int>& row : adjMatrix)
    {
        for (int& x : row)
            ss >> x;
    }

    return adjMatrix;
}


void DFStravel(vector<vector<int>> adjMatrix, int v, bool* isVisited)
{
    isVisited[v] = true;
    cout << v + 1 << " ";

    vector<int> c = adjMatrix[v];

    int numOfV = adjMatrix[v].size();
    for (int i = 0; i < numOfV; i++)
    {
        if (adjMatrix[v][i] != 0 && isVisited[i] == false)
            DFStravel(adjMatrix, i, isVisited);
    }
}


void DFS(vector<vector<int>> adjMatrix, int v)
{
    bool* isVisited = new bool[size_t(adjMatrix.size())]();
    DFStravel(adjMatrix, v, isVisited);
}

void BFS(vector<vector<int>> adjMatrix, int v)
{
    int numOfV = adjMatrix[v].size();
    bool* isVisited = new bool[size_t(numOfV)]();

    queue<int> q;
    q.push(v);

    isVisited[v] = true;
    cout << v + 1 << " ";
    
    int w = 0;
    while (!q.empty())
    {
        w = q.front();
        q.pop();

        for (int i = 0; i < numOfV; i++)
        {
            if (adjMatrix[w][i] != 0 && isVisited[i] == false)
            {
                q.push(i);
                cout << i + 1 << " ";
                isVisited[i] = true;
            }
        }
    }
}


int** convertAdjacencyMatrix(vector<vector<int>> edges, int n)
{
    int** adjMatrix = nullptr;
    adjMatrix = new int* [n];
    for (int i = 0; i < n; i++)
        adjMatrix[i] = new int[n]();

    for (vector<int> e : edges)
        adjMatrix[e[0]][e[1]] = 1;

    return adjMatrix;
}


void dijkstra(vector<vector<int>> adjMatrix, int start)
{
    int numberOfVertex = adjMatrix.size();
    vector<int> dist(numberOfVertex, 0);
    vector<bool> visited(numberOfVertex, false);

    for (int i = 0; i < numberOfVertex; i++) 
    {
        dist[i] = -INFINITY;
        visited[i] = false;
    }

    dist[start] = 0;
    for (int i = 0; i < numberOfVertex; i++) 
    {
        int u = -1;
        int min = -INFINITY;
        for (int j = 0; j < numberOfVertex; j++) 
        {
            if (!visited[j] && dist[j] < min) 
            {
                u = j;
                min = dist[j];
            }
        }

        if (u == -1) 
            return;

        visited[u] = true;
        for (int v = 0; v < numberOfVertex; v++) 
        {
            if (!visited[v] && adjMatrix[u][v] != -INFINITY 
                && dist[u] + adjMatrix[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    for (int i = 0; i < numberOfVertex; i++) {
        cout << dist[i] << " ";
    }
}