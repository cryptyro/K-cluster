# Clustering Algorithm

## Overview

This project implements a clustering algorithm to divide `n` items into `k` groups such that the minimum distance between items in different groups is maximized. 
The distance, `d(u,v)`, between each pair of items may represent an actual distance or an abstract measure of dissimilarity.

## Goal

The goal is to maximize the minimum distance between items in different clusters by creating `k` groups.

## Algorithm

The algorithm used to achieve this clustering is equivalent to Kruskal's algorithm for finding the Minimum Spanning Tree (MST). 

### Steps

1. **Measure Distances**: Find the Euclidean distance between each pair of the given points.
2. **Construct the graph**: Construct a complete weighted graph where the vertices are the given points and the edge weights are the distances computed in step 1.
3. **Finding MST**: Use Kruskal’s algorithm to find the minimal spanning tree of the graph constructed in step 2.
   In the implementation of the Kruskal’s algorithm, randomized quicksort is used as the sorting procedure and
   for detecting cycles the disjoint set data structure with union by rank and path compression is used.
4. **Resulting Clusters**: The clusters are the connected components of the graph formed by deleting the heaviest k-1 weight from the MST.

### Proof of Correctness

The algorithm's correctness can be proven by considering the process of deleting the `k-1` most expensive edges from the MST.

#### Proof Outline

1. **Spacing `d` of Clustering `C`**:
   - The spacing `d` is defined as the length of the `(k-1)<sup>th</sup>` most expensive edge in the MST.
2. **Comparison with Any Other Clustering `C'`**:
   - Consider any other clustering `C'`.
   - There must be at least one pair `p_i`, `p_j` in the same cluster in `C` but in different clusters in `C'`.
   - In `C`, there is a path `P` between `p_i` and `p_j` with all edges ≤ `d`.
   - In `C'`, at least one edge of `P` must pass between different clusters.
   - Hence, the separation of `C'` must be ≤ `d`.

## Implementation

This repository contains the implementation of the described clustering algorithm. To run the algorithm, ensure you have the necessary dependencies installed.

### Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/cryptyro/K-cluster
   cd src
2. Run the algorithm with the sample input:
   ```bash
   bash run.sh
