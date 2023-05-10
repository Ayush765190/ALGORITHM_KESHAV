#include <iostream>
#include <vector>
using namespace std;

class graph
{
    int vertex;

public:
    graph(vector<int> adj[], int vertex)
    {
        this->vertex = vertex;
    }

    void addedge(vector<int> adj[], int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS_recc(vector<int> adj[], int s, bool discovered[])
    {
        discovered[s] = true;
        cout << s << " ";
        for (int u : adj[s])
            if (discovered[u] == false)
                DFS_recc(adj, u, discovered);
    }

    void DFS(vector<int> adj[], int s)
    {
        bool discovered[vertex];
        for (int i = 0; i < vertex; i++)
            discovered[i] = false;

        DFS_recc(adj, s, discovered);
    }
    void print(vector<int> adj[])
    {
        for (int i = 0; i < vertex; i++)
        {
            cout << i << " : ";
            for (int x : adj[i])
                cout << x << " -> ";
            cout << "\n";
        }
    }
};

int main()
{

   int vertex = 6;
   vector<int> adj[vertex];
   graph g(adj,6);
   g.addedge(adj,0, 1);
   g.addedge(adj,1, 3);
   g.addedge(adj,2, 0);
   g.addedge(adj,1, 4);
   g.addedge(adj,3, 2);
   g.addedge(adj,4, 5);
//    g.addedge(adj,2, 4);
   // g.addedge(0,1);
   g.print(adj);
   cout<<endl;
   cout<<endl;
   g.DFS(adj,0);
}
