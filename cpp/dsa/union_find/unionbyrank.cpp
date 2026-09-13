#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
        vector<int> parent, rank;
    public:
        DisjointSet(int n) {
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++) {
                parent[i] = i;
            }
        }

        int findParent(int node) {
            if(parent[node] == node) return node;
            return parent[node] = findParent(parent[node]);
        }

        void unionByRank(int u , int v) {
            int parentU = findParent(u);
            int parentV = findParent(v);

            if(parentU == parentV) return;

            if(rank[parentU] > rank[parentV]) {
                parent[parentV] = parentU;
            } else if (rank[parentU] < rank[parentV]) {
                parent[parentU] = parentV;
            } else {
                parent[parentV] = parentU;
                rank[parentU]++;
            }
        }
};

int main () {
    // Too lazy to Complete code
}