#include<bits/stdc++.h>
using namespace std;

struct dsu{
    private:
        vector<int> rank, parent;
    public:
        dsu(int n) : rank(n, 0), parent(n, 0){
            for(int i = 0; i < n; i++) parent[i] = i;
        }
        int find_parent(int v) {
            if(v == parent[v]) return v;
            return parent[v] = find_parent(parent[v]);
        }
        void merge(int u, int v) {
            int pu = find_parent(u);
            int pv = find_parent(v);
            if(pu == pv) return;
            if(rank[pu] < rank[pv])
                swap(pu, pv);
            parent[pv] = pu;
            if(rank[pu] == rank[pv])
                rank[pu]++;
        }

};