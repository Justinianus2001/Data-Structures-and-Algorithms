#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <iostream>
using namespace std;
#define N 100005

typedef struct SegmentTree{
	int data;
}STNode;

STNode ST[N << 2];
int arr[N];

void Build(int id, int l, int r){
	if(l == r)
		ST[id].data = arr[l];
	else{
		int mid = (l + r) >> 1;
		Build((id << 1), l, mid), Build((id << 1) + 1, mid + 1, r),
		ST[id].data = ST[(id << 1)].data + ST[(id << 1) + 1].data;
	}
}

void Update(int id, int l, int r, int i, int v){
	if(i >= l && i <= r){
		if(l == r)
			ST[id].data = v;
		else{
			int mid = (l + r) >> 1;
			Update((id << 1), l, mid, i, v), Update((id << 1) + 1, mid + 1, r, i , v),
			ST[id].data = ST[(id << 1)].data + ST[(id << 1) + 1].data;
		}
	}
}

int Query(int id, int l, int r, int u, int v){
	if(v < l || r < u)
		return 0;
	else{
		if(u <= l && r <= v)
			return ST[id].data;
		else{
			int mid = (l + r) >> 1;
			return Query((id << 1), l, mid, u, v) + Query((id << 1) + 1, mid + 1, r, u, v);
		}
	}
}

void Manage(){
	int n, q, type, x, y;
	cin >> n >> q;
	for(int i = 0; i < n; i ++)		cin >> arr[i];
	Build(1, 0, n - 1);
	while(q --){
		// Type of query:
		// 1 i v -> change value of arr[i] = v
		// 2 u v -> calculate sum in range [u, v]
		cin >> type >> x >> y;
		if(type == 1)	Update(1, 0, n - 1, x, y);
		if(type == 2)	cout << Query(1, 0, n - 1, x, y - 1) << '\n';
	}
}

#endif
