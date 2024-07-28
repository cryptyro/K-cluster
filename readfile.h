#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read data from file
float **vertex_set(const char *infile, int *vsize, int *dim, int *k) {
    FILE *file = fopen(infile, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
    }
    fscanf(file, "%d", vsize);
    fscanf(file, "%d", dim);
    fscanf(file, "%d", k);
    float **vertices;
    vertices = malloc(*vsize * sizeof(float*));
    for (int i = 0; i < *vsize; ++i) {
    	vertices[i] = malloc(*k * sizeof(float));
        for (int j = 0; j < *dim; ++j) {
            fscanf(file, "%f", &vertices[i][j]);
        }
    }
    fclose(file);
	return vertices;
}

// Structure to represent an edge in the graph
struct Edge {
    int src, dst;
    float weight;
};

// Function to calculate Euclidean distance between two points
float dist(float *p1, float *p2, int dim) {
    float sum = 0.0;
    for (int i = 0; i < dim; ++i) {
        sum += pow(p1[i] - p2[i], 2);
    }
    return sqrt(sum);
}

// Calculate distances between each pair of points
struct Edge* weighing(float **v, int vsize, int dim){
	int Esize=(vsize*(vsize-1))/2;
	int e=0;
	struct Edge* Eset = malloc(sizeof(struct Edge)*Esize);
    for (int i = 0; i < vsize; ++i) {
        for (int j = i + 1; j < vsize; ++j) {
            Eset[e].src=i;
            Eset[e].dst=j;
            Eset[e++].weight = dist(v[i],v[j],dim);
        }
    }
    return Eset;
}
