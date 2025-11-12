/*
 * CSC-301
 * prim.cpp
 * Fall 2025
 *
 * Partner 1: Khanh Do
 * Partner 2: Ngoc Ta
 * Date: Nov 14, 2025
 */

#include "prim.hpp"

using namespace std;

/*
 * getMin
 * Finds the unvisited vertex with the minimum cost.
 * INPUTS:
 * * cost: vector of costs to reach each vertex
 * * visited: vector of flags indicating which vertices are already in MST
 * OUTPUT:
 * * returns the label of the vertex with minimum cost (that hasn't been visited)
 */
int getMin(vector<double> &cost, vector<bool> &visited) {
    double minCost = numeric_limits<double>::infinity();
    int minVertex = -1;
    int n = cost.size();
    
    // Linear search through all vertices to find the minimum
    for (int i = 0; i < n; i++) {
        // only consider vertices that haven't been added to MST yet
        if (!visited[i] && cost[i] < minCost) {
            minCost = cost[i];
            minVertex = i;
        }
    }
    
    return minVertex;
}

/*
 * isEmpty
 * Checks if there are any unvisited vertices remaining.
 * INPUT:
 * * visited: vector of flags indicating which vertices are in the MST
 * OUTPUT:
 * * returns true if all vertices have been visited, false otherwise
 */
bool isEmpty(vector<bool> &visited) {
    // check if any vertex is still unvisited
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            return false; 
        }
    }
    return true; 
}

/*
 * prim
 * Implements Prim's algorithm to find the Minimum Spanning Tree.
 * INPUTS:
 * * adjList: adjacency list representation (vector of Vertices)
 * * adjMat: adjacency matrix as 1D vector (access [i][j] as adjMat[i*n + j])
 * OUTPUT:
 * * mst: vector of Edges in the MST. Each vertex's mstNeighbors is also updated
 */
vector<Edge> prim(vector<Vertex> &adjList, vector<double> &adjMat) {
    // Initialize the empty MST.
    vector<Edge> mst;
    
    // For each vertex, we need a visited flag, a 'cost' for Prim's, and the
    // prev values to track the MST. Store these in seperate vectors.
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<double> cost(n, numeric_limits<double>::infinity());
    vector<int> prev(n, -1);

    // start Prim's algorithm at vertex 0
    cost[0] = 0.0;
    
    // keep adding vertices until all are in the MST
    while (!isEmpty(visited)) {
        // find unvisited vertex with min cost to add to MST
        int u = getMin(cost, visited);
        
        // add this vertex to the MST
        visited[u] = true;
        
        // if vertex has a parent, create MST edge
        // first vertex (0) won't have a parent since it's the start
        if (prev[u] != -1) {
            // create edge between parent vertex and current vertex
            // access edge weight from 1D adjacency matrix: adjMat[row*n + col]
            Edge edge(adjList[prev[u]], adjList[u], adjMat[prev[u] * n + u]);
            mst.push_back(edge);
            
            // update both vertices' MST neighbor lists (undirected graph) 
            adjList[prev[u]].mstNeighbors.push_back(u);
            adjList[u].mstNeighbors.push_back(prev[u]);
        }
        
        // update costs for all neighbors of the newly added vertex
        // check if going through vertex u gives us a cheaper path to its neighbors
        for (int v : adjList[u].neighbors) {
            // get edge weight from u to v using 1D adjacency matrix
            double edgeWeight = adjMat[u * n + v];
            
            if (!visited[v] && edgeWeight < cost[v]) {
                cost[v] = edgeWeight;  // update to the cheaper cost
                prev[v] = u;           // u is now parent of v in MST
            }
        }
    }
    
    return mst;
}