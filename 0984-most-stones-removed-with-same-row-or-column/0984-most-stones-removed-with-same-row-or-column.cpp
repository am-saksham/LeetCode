class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    void unionSet(int x, int y, vector<int>& parent, vector<int>& rank) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(20002, 0), rank(20002, 0);

        
        for (int i = 0; i < 20002; ++i) {
            parent[i] = i;
        }

         
        for (const auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001;  
            unionSet(row, col, parent, rank);
        }

        
        unordered_set<int> uniqueRoots;
        for (const auto& stone : stones) {
            uniqueRoots.insert(find(stone[0], parent));
        }

        
        return n - uniqueRoots.size();
    }
};