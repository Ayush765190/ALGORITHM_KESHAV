#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Graph
{
   int vertex;
   // vector<int> adj[];

public:
   Graph(vector<int> adj[],int vertex)
   {
      this->vertex = vertex;
      
      // adj[vertex];
   }

   void addedge(vector<int> adj[],int u, int v)
   {
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   void bfstraversal(vector<int> adj[],int s){
      bool discovered[vertex+1];
      for(int i=0;i<vertex;i++)
         discovered[i]=false;
      
      discovered[s]=true;
      queue<int> q;
      q.push(s);
      while(!q.empty()){
         int u=q.front();
         q.pop();
         cout<<u<<" ";

         for(int x:adj[u])
           {
            if(discovered[x]==false){
               discovered[x]=true;
               q.push(x);
            }
           }
      }
      
        
   }
   void print(vector<int> adj[])
   {
      for (int i = 0; i < vertex; i++)
      {
          cout << i << " : ";
         for (int x : adj[i])
            cout<< x << " -> ";
         cout << "\n";
      }
   }
   
};
int main()
{

   int vertex = 4;
   vector<int> adj[vertex];
   Graph g(adj,4);
   g.addedge(adj,0, 1);
   g.addedge(adj,0, 2);
   g.addedge(adj,0, 5);
   g.addedge(adj,1, 3);
   g.addedge(adj,3, 0);
   g.addedge(adj,2, 0);
   g.addedge(adj,2, 0);
   // g.addedge(0,1);
   g.print(adj);
   cout<<endl;
   cout<<endl;
   g.bfstraversal(adj,0);
}