#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> readGraph(int v, int e) {
    vector<vector<int>> graph(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++) {
        cout<<"Enter the edge between vertices and their weight : ";
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    return graph;
}

int primsMST(vector<vector<int>> graph, int v) {
    int key[v], res = 0;
    fill(key, key + v, INT_MAX);
    key[0] = 0;
    bool mset[v] = {false};
    for (int i = 0; i < v; i++) {
        int u = -1;
        for (int j = 0; j < v; j++) {
            if (!mset[j] && (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }
        mset[u] = true;
        res += key[u];
        for (int k = 0; k < v; k++) {
            if (graph[u][k] != 0 && !mset[k] && graph[u][k] < key[k]) {
                key[k] = graph[u][k];
            }
        }
    }
    return res;
}
void printMST(vector<int> parent, vector<vector<int>> graph) {
    cout << "MST Edges:" << endl;
    for (int i = 1; i < parent.size(); i++) {
        cout << "Vertex " << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;v 
    }
}


int main() {
    int v, e;
    cout<<"Enter the number of vertec and edges : ";
    cin >> v >> e;
    vector<vector<int>> graph = readGraph(v, e);

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<" ";
            
        }
        cout<<endl;
    }
    int mstWeight = primsMST(graph, v);
    cout << "MST weight = " << mstWeight << endl;
    return 0;
}
