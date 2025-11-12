/*
 * CSC-301
 * prim.hpp
 * Fall 2025
 *
 * Partner 1: Khanh Do
 * Partner 2: Ngoc Ta
 * Date: Nov 14, 2025
 */

#ifndef PRIM_HPP_
#define PRIM_HPP_

#include "Vertex.hpp"
#include "Edge.hpp"

/*
 * getMin
 * Finds the unvisited vertex with the minimum cost.
 * INPUTS:
 * * cost: vector of costs to reach each vertex
 * * visited: vector of flags indicating which vertices are already in MST
 * OUTPUT:
 * * returns the label of the vertex with minimum cost (that hasn't been visited)
 */
int getMin(std::vector<double> &cost, std::vector<bool> &visited);

/*
 * isEmpty
 * Checks if there are any unvisited vertices remaining.
 * INPUT:
 * * visited: vector of flags indicating which vertices are in the MST
 * OUTPUT:
 * * returns true if all vertices have been visited, false otherwise
 */
bool isEmpty(std::vector<bool> &visited);

/*
 * prim
 * Implements Prim's algorithm to find the Minimum Spanning Tree.
 * INPUTS:
 * * adjList: adjacency list representation (vector of Vertices)
 * * adjMat: adjacency matrix as 1D vector (access [i][j] as adjMat[i*n + j])
 * OUTPUT:
 * * mst: vector of Edges in the MST. Each vertex's mstNeighbors is also updated
 */
std::vector<Edge> prim(std::vector<Vertex> &adjList, 
                       std::vector<double> &adjMat);

#endif  // PRIM_HPP_