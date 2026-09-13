#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    private:
        vector<int> size , parent;
    public:
        DisjointSet(int n) {
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++) {
                parent[i] = i;
            }
        }

        int findParent (int node) {
            if(parent[node] == node) return node;
            return parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v) {
            int parentU = findParent(u);
            int parentV = findParent(v);

            if(parentU == parentV) return;

            if(size[parentU] >= size[parentV]) {
                parent[parentV] = parentU;
                size[parentU] += size[parentV];
            } else {
                parent[parentU] = parentV;
                size[parentV] += size[parentU];
            }
        }
};

int main () {
    // Too Lazy to write
}