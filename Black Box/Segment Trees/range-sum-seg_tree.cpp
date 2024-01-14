#include <bits/stdc++.h>
using namespace std;


/*
		 1
	2 		   3
 4    5     6     7
8 9 10 11 12 13 14 15
*/
vector<int> SGT;

int left(int index){
	return 2 * index;
}
int right(int index){
	return 2 * index + 1;
}
int merge(int leftAns, int rightAns){
	return leftAns + rightAns;
}
int default_value(){
	return 0;
}

// O(n)
void build(int start, int end, int index, vector<int>& arr){
	if(start == end){
		SGT[index] = arr[start];
		return;
	}
	
	// dividing current range into halfs
	int mid = (start + end)/2;
	
	build(start, mid, left(index), arr); // populating left subtree
	build(mid + 1, end, right(index), arr); // populating right subtree
	
	SGT[index] = merge(SGT[left(index)], SGT[right(index)]); // merged left and right
}

// O(logn)
void update(int start, int end, int index, int pos, int val){
	if(start == end){ // reached destination
		SGT[index] = val;
		return;
	}
	
	int mid = (start + end) / 2;
	
	if(pos <= mid){
		update(start, mid, left(index), pos, val); // update left
	}
	else{
		update(mid + 1, end, right(index), pos, val); // update right
	}
	
	SGT[index] = merge(SGT[left(index)], SGT[right(index)]); // update current node after childrens are updated
}

// O(logn)
int query(int start, int end, int index, int l, int r){
	// complete overlap
	// [l..... start.... end.... r]
	if(l <= start && r >= end){
		return SGT[index];
	}
	
	// disjoint
	// [start.... end... l... r] or [l... r... start... end]
	if(end < l || r < start){
		return default_value();
	}
	
	// partial overlap
	int mid = (start + end)/2;
	
	int leftAns = query(start, mid, left(index), l, r);
	int rightAns = query(mid + 1, end, right(index), l, r);
	
	// return leftAns + rightAns;
	return merge(leftAns, rightAns);
}

void solve(){
	int n; cin >> n;
	
	vector<int> arr(n);
	for(auto &i : arr) cin >> i;
	
	// Segment tree
	SGT.resize(4*n + 1); // 1-based indexing
	build(0, n-1, 1, arr); // (start, end, root of SGT, array)
	
	// cout << query(0, n-1, 1, 0, 1) << endl;
	// cout << query(0, n-1, 1, 3, 5) << endl;
	// cout << query(0, n-1, 1, 2, 6) << endl;
	
	// update(0, n-1, 1, 1, 10);
	
	// cout << query(0, n-1, 1, 0, 1) << endl;
}

int main(){
	solve();
}