#include "readfile.h"
#include "disjointset.h"
#include "quicksort.h"
#include "kruskal.h"
#include "cluster.h"

int main(){
	char infile[100]; // Maximum filename length assumed to be 100 characters
	char outfile[100]; // Maximum filename length assumed to be 100 characters
    printf("Please enter the filename where the data is stored : ");
    scanf("%s", infile);
    printf("Please enter the filename where the result is to be stored : ");
    scanf("%s", outfile);
    int vsize, dim, k;
    float **V = vertex_set(infile, &vsize, &dim, &k);
    int esize = (vsize*(vsize-1))/2;
    struct Edge* E = weighing(V, vsize, dim);
    struct Edge* MST = Kruskal(E,vsize, esize);
    printMST(MST,vsize);  
    struct Dset* kset= cluster(MST, vsize, k);
    printKcluster(kset, outfile, V, vsize, dim);
    for (int i=0;  i<vsize;  i++){
    	free(V[i]);
    }
    free(E);
    free(MST);
    free(V);
    free(kset);
    return 0;
}
