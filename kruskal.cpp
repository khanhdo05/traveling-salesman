/*
 * CSC-301
 * kruskal.cpp
 * Fall 2025
 *
 * Partner 1: Khanh Do
 * Partner 2: Ngoc Ta
 * Date: Nov 14, 2025
 */

#include "kruskal.hpp"

using namespace std;

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
int find(int v, vector<int> &pi) {
    if (v == pi[v]) {
        // found the root
        return v;
    }

    pi[v] = find(pi[v], pi);
    return pi[v];
}

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
void union_by_rank(int u, int v, vector<int> &rank, vector<int> &pi) {
    // Find the root of tree that has vector u and v
    int root_u = find(u, pi);
    int root_v = find(v, pi);

    // u and v comes from the same tree, do nothing
    if (root_u == root_v) return;

    // Find the rank of each root
    int rank_u = rank[root_u];
    int rank_v = rank[root_v];

    // Compare rank of roots, higher rank should remains the root
    // while lower rank should join the other one as a branch
    if (rank_u > rank_v) {
        pi[root_v] = root_u;
    } else if (rank_v > rank_u) {
        pi[root_u] = root_v;
    } else {
        // Same rank so pick one root to be the higher rank
        pi[root_u] = root_v;
        rank[root_v] += 1;
    }
}

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
vector<Edge> kruskal(vector<Vertex> &adjList, vector<Edge> &edgeList) {
    // Initialize the empty MST.
    vector<Edge> mst;
    
    // For each vertex, we need rank values and pi pointers (ints) for the
    // Disjoint Sets. Initialize the rank to 0 and pi to be the vertex labels.
    int n = adjList.size();
    vector<int> rank(n, 0);
    vector<int> pi(n);
    for (int i = 0; i < pi.size(); i++) {
        pi[i] = i;
    }

    // Iterates through the sorted edges, from the lightest to the heaviest
    for (Edge e : edgeList) {
        Vertex &u = adjList[e.first.label];
        Vertex &v = adjList[e.second.label];
        int u_label = u.label;
        int v_label = v.label;

        if (find(u_label, pi) != find(v_label, pi)) {
            // Add e to the mst
            mst.push_back(e);

            // union set u and v
            union_by_rank(u_label, v_label, rank, pi);

            // Add to mst neighbors 
            u.mstNeighbors.push_back(v_label);
            v.mstNeighbors.push_back(u_label);
        }
    }

    return mst;
}