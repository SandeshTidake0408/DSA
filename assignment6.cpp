// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 20

class Graph
{
public:
    int vertices;
    int g[MAX][MAX];
    vector<int> adjList[MAX]; // adj list
    bool visited[MAX];

    Graph(int val)
    {
        vertices = val;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                g[i][j] = 0;
            }
            visited[i] = false;
        }
    }

    void create(int v1, int v2)
    {
        if (v1 >= vertices || v2 >= vertices)
        {
            cout << "Invalid Vertex Value" << endl;
        }
        else
        {
            g[v1][v2] = 1; //for matrix
            g[v2][v1] = 1;

            adjList[v1].push_back(v2); // for list
            adjList[v2].push_back(v1);
        }
    }

    void display()
    {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Adjacency List:" << endl;
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vertex" << i << " --> ";
            for (int j = 0; j < adjList[i].size(); j++)
            {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int v)
    {
        cout << v << " ";
        visited[v] = true;
        for (int k = 0; k < vertices; k++)
        {
            if (g[v][k] == 1 && !visited[k])
            {
                dfs(k);
            }
        }
    }

    void bfs(int v)
    {
        queue<int> q;
        q.push(v);
        visited[v] = true;

        while (!q.empty())
        {
            int val = q.front();
            cout << val << " ";
            q.pop();

            for (int i = 0; i < adjList[val].size(); i++)
            {
                int neighbor = adjList[val][i];
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.create(0, 1);
    g.create(0, 2);
    g.create(0, 3);
    g.create(1, 4);
    g.create(2, 4);
    g.create(3, 4);
    g.create(5, 1);
    g.display();

    int v;
    cout << "Enter the Starting Vertex for DFS Traversal: ";
    cin >> v;
    if (v >= g.vertices)
    {
        cout << "Invalid Starting Vertex!" << endl;
    }
    else
    {
        cout << "DFS Traversal: ";
        g.dfs(v);
        cout << endl;
    }

    cout << "Enter the Starting Vertex for BFS Traversal: ";
    cin >> v;
    if (v >= g.vertices)
    {
        cout << "Invalid Starting Vertex!" << endl;
    }
    else
    {
        for (int i = 0; i < g.vertices; i++)
        {
            g.visited[i] = false;
        }
        cout << "BFS Traversal: ";
        g.bfs(v);
        cout << endl;
    }

    return 0;
}