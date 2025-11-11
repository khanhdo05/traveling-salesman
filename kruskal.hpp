/*
 * CSC-301
 * kruskal.hpp
 * Fall 2025
 *
 * Partner 1: Khanh Do
 * Partner 2: Ngoc Ta
 * Date: Nov 14, 2025
 */

#ifndef KRUSKAL_HPP_
#define KRUSKAL_HPP_

#include "Vertex.hpp"
#include "Edge.hpp"

/*
 * find: Given a vector v, find the root of the disjointed set that has that vector.
 *      while also updating every pi to directly point to that root.
 * 
 * Args:
 *      int v: the label of the given vector
 *      vector<int> &pi: the reference to a vector that maps the vertex label as
 *          index to its pi value
 * 
 * Return:
 *      int: the label of the root of the disjointed set
 */
int find(int v, std::vector<int> &pi);

/*
 * union_by_rank: Given two vector u, v, join the sets that contain them together.
 *
 * Args:
 *      int u: the label of the fist given vector
 *      int v: the label of the second given vector
 *      vector<int> &rank: the reference to a vector that maps the label of the
 *          vector as index to its height in the tree
 *      vector<int> &pi: the reference to a vector that maps the vertex label as
 *          index to its pi value
 * 
 * Return:
 *      void
 */
void union_by_rank(int u, int v, std::vector<int> &rank, std::vector<int> &pi);

/*
 * kruskal: Build the Minimum Spanning Tree (MST) by picking the lightest edge
 *      that doesn't form a cycle. At the end, every vertex has been assigned 
 *      the proper mstNeighbors value that encode the same MST edges returned.
 * 
 * Args:
 *      vector<Vertex> &adjList: the reference to the given adjacency list that
 *          represents the graph
 *      vector<Edge> &edgeList: the reference to the sorted edge list
 * 
 * Return:
 *      vector<Edge> mst: the vector of Edges in the MST
 */
std::vector<Edge> kruskal(std::vector<Vertex> &adjList, 
                          std::vector<Edge> &edgeList);

#endif  // KRUSKAL_HPP_