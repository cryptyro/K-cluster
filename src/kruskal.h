// Kruskal's Minimum Spanning Tree algorithm
struct Edge* Kruskal(struct Edge *edges, int V, int E) {
    // Allocate memory for creating V subsets
    struct Dset* subsets = (struct Dset*)malloc(V * sizeof(struct Dset));

    // Create V subsets with single elements
	makeSet(subsets, V);

    // Sort all the edges in increasing order of their weight
    quickSort(edges,0, E-1);

    // Allocate memory for the result
    struct Edge* result = (struct Edge*)malloc((V-1) * sizeof(struct Edge));

    int e = 0; // An index variable used for result
    int i = 0; // An index variable used for sorted edges
    while (e < V - 1 && i < E) {
        // Pick the smallest edge. Increment index for next iteration
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dst);

        // If including this edge does not cause cycle, include it in the result and increment the index
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    free(subsets);
    return result;
}

// Function to print the constructed MST
void printMST( struct Edge *result, int V){
    printf("Following are the edges in the constructed MST:\n");
    float minimumCost = 0;
    for (int i = 0; i < V-1; ++i) {
        printf("%d -- %d == %f\n", result[i].src, result[i].dst, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Cost of the Spanning Tree(Minimum): %f\n", minimumCost);
}
    
