// PROBLEM STATEMENT : You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities.You want a set of lines that connects all your offices with minimum total cost.Solve the problem by suggesting appropriate data structures.
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void prims(vector<pair<int, int>> adj[], int n)
{
    vector<bool> visited(n, false);
    vector<int> key(n, 9999);
    vector<int> parent(n, -1);

    key[0] = 0; // staring from vetex zero

    for (int count = 0; count < n; count++)
    {
        int min = 9999;
        int u;

        for (int k = 0; k < n; k++)
        {
            if (visited[k] == false && key[k] < min)
            {
                min = key[k];
                u = k;
            }
        }
        visited[u] = true;

        for (auto x : adj[u])
        {
            int vertex = x.first;
            int wt = x.second;
            if (visited[vertex] == false && wt < key[vertex])
            {
                parent[vertex] = u;
                key[vertex] = wt;
            }
        }
    }

    // printing parent;
    for (int i = 0; i < n; i++)
    {
        cout << i << " ===>> " << parent[i] << " ";
    }

    cout << endl;
    cout << "minimum weight is:" << endl;
    int minwt = 0;
    for (int i = 0; i < n; i++)
    {
        minwt += key[i];
    }

    cout << minwt << endl;
}

int main()
{

    int n;
    cout << "enter the no of edges:" << endl;
    cin >> n;
    vector<pair<int, int>> adj[n];

    int u, v, w;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the u(start),v(end),w(weight) :" << endl;
        cin >> u >> v >> w;

        addEdge(adj, u, v, w);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " ->";
        for (auto x : adj[i])
        {
            cout << x.first << "-----" << x.second << " ";
        }
        cout << endl;
    }

    prims(adj, n);

    return 0;
}

// #include <iostream>
// using namespace std;

// class tree
// {
//     int a[20][20], l, u, w, i, j, v, e, visited[20];

// public:
//     void input();
//     void display();
//     void minimum();
// };

// void tree::input()
// {
//     cout << "Enter the no. of branches (vertices): ";
//     cin >> v;

//     for (i = 0; i < v; i++)
//     {
//         visited[i] = 0;
//         for (j = 0; j < v; j++)
//         {
//             a[i][j] = 999;
//         }
//     }

//     cout << "\nEnter the no. of connections (edges): ";
//     cin >> e;
//     for (i = 0; i < e; i++)
//     {
//         cout << "Enter the end branches of connections (star and end vertex):  " << endl;
//         cin >> l >> u;
//         cout << "Enter the phone company charges for this connection:  ";
//         cin >> w;
//         a[l][u] = a[u][l] = w;
//     }
// }

// void tree::display()
// {
//     cout << "\nAdjacency matrix:";
//     for (i = 0; i < v; i++)
//     {
//         cout << endl;
//         for (j = 0; j < v; j++)
//         {
//             cout << a[i][j] << "   ";
//         }
//         cout << endl;
//     }
// }

// void tree::minimum()
// {
//     int p = 0, q = 0, total = 0, min;
//     visited[0] = 1;
//     for (int count = 0; count < (v - 1); count++)
//     {
//         min = 999;
//         for (i = 0; i < v; i++)
//         {
//             if (visited[i] == 1)
//             {
//                 for (j = 0; j < v; j++)
//                 {
//                     if (visited[j] != 1)
//                     {
//                         if (a[i][j] < min)
//                         {
//                             min = a[i][j];
//                             p = i;
//                             q = j;
//                         }
//                     }
//                 }
//             }
//         }
//         visited[p] = 1;
//         visited[q] = 1;
//         total = total + min;
//         cout << "Minimum cost connection is" << (p + 1) << " -> " << (q + 1) << "  with charge : " << min << endl;
//     }
//     cout << "The minimum total cost of connections of all branches is: " << total << endl;
// }

// int main()
// {
//     int ch;
//     tree t;
//     do
//     {
//         cout << "==========PRIM'S ALGORITHM=================" << endl;
//         cout << "\n1.INPUT\n \n2.DISPLAY\n \n3.MINIMUM\n"
//              << endl;
//         cout << "Enter your choice :" << endl;
//         cin >> ch;

//         switch (ch)
//         {
//         case 1:
//             cout << "*******INPUT YOUR VALUES*******" << endl;
//             t.input();
//             break;

//         case 2:
//             cout << "*******DISPLAY THE CONTENTS********" << endl;
//             t.display();
//             break;

//         case 3:
//             cout << "*********MINIMUM************" << endl;
//             t.minimum();
//             break;
//         }

//     } while (ch != 4);
//     return 0;
// }