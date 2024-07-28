// Function for cluster assignment
struct Dset* cluster(struct Edge* MST, int V, int k){
	// Delete the heaviest k-1 weight from the MST
	quickSort(MST,0,V-2);
	
	// Construct disjoint sets correspondig to this updated edgeset
	struct Dset* set = malloc(V * sizeof(struct Dset));
	makeSet(set, V);
	for(int  i=0;i<V-k;i++){
		int s=MST[i].src;
		int d=MST[i].dst;
		Union(set,s,d);
	}
	//Set rank zero
	for (int i=0;  i<V; i++)
		set[i].rank=0;
	
	//Assigning each vertex to its cluster group
	int flag=1;
	for(int i=0;  i<V; i++){
		int kcl=set[find(set, i)].rank;
		if(kcl != 0)
			set[i].rank = kcl;
		else set[find(set, i)].rank=set[i].rank = flag++;
	}
	return set;
}

// Function to print the vertices with the cluster group
void printKcluster(struct Dset* set, const char* outfile, float** vertices, int V, int dim){
	FILE *file  = fopen(outfile, "w");
	if (file != NULL) {
		for (int i = 0; i < V; ++i) {
        	for (int j = 0; j < dim; ++j) 
        	    fprintf(file, "%f  ", vertices[i][j]);
        	fprintf(file, "%d \n",  set[i].rank);
    	}
		fclose(file);
	}
  	else printf("Error opening file!\n");
}
