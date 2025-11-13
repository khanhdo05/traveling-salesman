/*
 * CSC-301
 * tsp.hpp
 * Fall 2025
 *
 * Partner 1: Khanh Do
 * Partner 2: Ngoc Ta
 * Date: Nov 14, 2025
 */

#ifndef TSP_HPP_
#define TSP_HPP_

#include <stack>

#include "Vertex.hpp"

/*
 * tsp: Use DFS to traverse through the MST to find the path that minimize the time
 *      the travelling salemans spend between different cities.
 * 
 * Args:
 *      vector<Vertex> &adjList: the adjacency list that represents the graph of cities
 *      Vertex &start: the starting city
 * 
 * Return:
 *      vector<int> tour: the optimized path for the TSP
 */
std::vector<int> tsp(std::vector<Vertex> &adjList, Vertex &start);

#endif  // TSP_HPP_