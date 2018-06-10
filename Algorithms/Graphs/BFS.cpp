#include <queue>     // std::queue
#include <vector>    // std::vector
#include <algorithm> // std::reverse

using graph_t = std::vector<std::vector<long long>>;
using T       = graph_t::value_type::value_type;

//====================================================================================================================================
//!
//! \brief   Realization of BFS(breadth - first search) - a method of traversing the graph and finding the path in the graph
//!
//! \param   graph   Graph
//! \param   num     Number of vertices
//! \param   vertex  The vertex to which you need to restore the path
//! \praam   start   Starting vertex
//!        
//! \return  Shortest path to 'vertex' 
//!
//====================================================================================================================================

std::vector<T> BFS(const graph_t &graph, size_t num, T vertex, size_t start = 0ull)
{
	std::queue<T> q;
	q.push(start);

	std::vector<bool> used(num);
	used[start] = true;

	std::vector<T> d(n),
		           p(n);
	p[s] = -1;
	while (!q.empty()) 
	{
		auto f{ q.front() };
		q.pop();

		for (size_t i{}; i < graph[f].size(); ++i)
		{
			auto t{ graph[f][i] };
			if (!used[to]) 
			{
				used[t] = true;

				q.push(t);

				d[t] = d[f] + 1;
				p[t] = v;
			}
		}
	}

	if (!used[vertex])
		return {};
	else
	{
		std::vector<T> path;
		for (T i = to; i != -1; i = p[i])
			path.push_back(v + 1);

		std::reverse(path.begin(), path.end());

		return (path);
	}
}

