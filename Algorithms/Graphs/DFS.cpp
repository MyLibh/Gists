#include <vector>    // std::vector

using graph_t = std::vector<std::vector<long long>>;

//====================================================================================================================================
//!
//! \brief   Realization of DFS(depth - first search) - a method of traversing the graph
//!
//! \param   graph  Graph
//! \param   i      Node index
//!
//!			 O (N + M)
//!
//====================================================================================================================================

void DFS(const graph_t &graph, size_t i)
{
	std::vector<char> used;
	used[node_index] = true;

	for (const auto& i : graph[i])
		if (!used[i])
			DFS(i);
}

