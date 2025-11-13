/*
 * CSC-301
 * tsp.cpp
 * Fall 2025
 *
 * Partner 1: Khanh Do
 * Partner 2: Ngoc Ta
 * Date: Nov 14, 2025
 */

#include "tsp.hpp"

using namespace std;

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
vector<int> tsp(vector<Vertex> &adjList, Vertex &start) {
    // Create the empty tour.
    vector<int> tour;
    
    // Create the vector for tracking visited during the DFS.
    int n = adjList.size();
    vector<bool> visited(n, false);

    // Create the stack for DFS with the start vertex
    stack<int> s;
    visited[start.label] = true;
    s.push(start.label);

    // Start the tour
    tour.push_back(start.label);

    // DFS iteratively using the stack
    while (!s.empty()) {
        // Get the top of the stack
        int curr = s.top();
        s.pop();

        // If not visited, need to visit and mark visited
        if (!visited[curr]) {
            visited[curr] = true;
            tour.push_back(curr);
        }
    
        // Push unvisited mst neighbors
        for (int neighbor : adjList[curr].mstNeighbors) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }

    // Close the circle
    tour.push_back(start.label);

    return tour;
}