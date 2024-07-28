// Structure to represent a disjoint set element
struct Dset {
    int parent;
    int rank;
};

// Function to initialize a disjoint set
void makeSet(struct Dset *set, int n) {
    for (int i = 0; i < n; ++i) {
        set[i].parent = i;
        set[i].rank = 0;
    }
}

// Function to find the root of an element with path compression
int find(struct Dset *set, int i) {
    if (set[i].parent != i) {
        set[i].parent = find(set, set[i].parent); // Path compression
    }
    return set[i].parent;
}

// Function to perform union of two sets by rank
void Union(struct Dset *set, int x, int y) {
    int rootX = find(set, x);
    int rootY = find(set, y);

    if (rootX != rootY) {
        // Union by rank
        if (set[rootX].rank < set[rootY].rank) {
            set[rootX].parent = rootY;
        } else if (set[rootX].rank > set[rootY].rank) {
            set[rootY].parent = rootX;
        } else {
            set[rootY].parent = rootX;
            set[rootX].rank++;
        }
    }
}
