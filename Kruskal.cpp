#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100005;
int parent[MAX], ranks[MAX];

struct Edge {
    int src, dest, wt;
    Edge() {
        src = dest = wt = -1;
    }
    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        wt = w;
    }
};

bool mycmp(Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void union_sets(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        if (ranks[px] < ranks[py]) {
            swap(px, py);
        }
        parent[py] = px;
        if (ranks[px] == ranks[py]) {
            ranks[px]++;
        }
    }
}

void print_mst(Edge mst[], int n) {
    cout << "Edges in the minimum spanning tree:" << endl;
    for (int i = 0; i < n; i++) {
        cout << mst[i].src << " - " << mst[i].dest << " : " << mst[i].wt << endl;
    }
}

int kruskal(Edge arr[], int n, int m) {
    sort(arr, arr + m, mycmp);
    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
    int res = 0;
    int s = 0;
    Edge mst[MAX];
    for (int i = 0; s < n - 1 && i < m; i++) {
        Edge e = arr[i];
        int x = find(e.src);
        int y = find(e.dest);
        if (x != y) {
            res += e.wt;
            union_sets(x, y);
            mst[s] = e;
            s++;
        }
    }
    print_mst(mst, s);
    return res;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    Edge arr[m];
    cout << "Enter the source, destination, and weight of each edge:" << endl;
    cout<<"edges = "<<m;
    cout<<"vertices = "<<n;
	for (int i = 0; i < m; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        arr[i] = Edge(s, d, w);
    }
    int mst_wt = kruskal(arr, n, m);
    cout << "Weight of the minimum spanning tree: " << mst_wt << endl;
}
