#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dijkstra(int start, int n, int val[], vector<pair<int, int>> edge[]){
	priority_queue<pair<int, int>> q;
	bool visited[n + 1] = {};
	for(int idx = 0; idx < n; idx ++)
		val[idx] = INT_MAX;
	val[start] = 0, q.push({0, start});
	while(q.size()){
		int cur = q.top().second;
		q.pop();
		if(!visited[cur]){
			visited[cur] = true;
			for(auto i: edge[cur]){
				int next = i.first, nextVal = i.second;
				if(val[cur] + nextVal < val[next] && val[cur] != INT_MAX)
					val[next] = val[cur] + nextVal,
					q.push({-val[next], next});
			}
		}
	}
}

#endif
