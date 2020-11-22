#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, bool visited[], vector<int> edge[]){
	queue<int> q;
	q.push(start);
	while(q.size()){
		int cur = q.front();
		q.pop();
		if(!visited[cur]){
			cout << cur << ' ';
			for(auto i: edge[cur])
				q.push(i);
			visited[cur] = true;
		}
	}
}

#endif
