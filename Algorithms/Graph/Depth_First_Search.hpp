#ifndef DEPTH_FIRST_SEARCH_HPP
#define DEPTH_FIRST_SEARCH_HPP

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(int start, bool visited[], vector<int> edge[]){
	stack<int> s;
	s.push(start);
	while(s.size()){
		int cur = s.top();
		s.pop();
		if(!visited[cur]){
			cout << cur << ' ';
			for(auto i: edge[cur])
				s.push(i);
			visited[cur] = true;
		}
	}
}

#endif
