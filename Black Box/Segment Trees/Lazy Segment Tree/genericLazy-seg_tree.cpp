#include<bits/stdc++.h>
using namespace std;

//*------------------------------------Lazy Segment Tree Starts------------------------------------

struct Node;
struct Update;

// {type of input array, Node logic, Update logic}
template <typename T, typename Node = Node, typename Update = Update>
class LazySegmentTree {
private: 
	vector<Node> tree;
	vector<int> lazy;
	vector<Update> updates;
	vector<T> arr;
	int size = 0;
	
	// root index is 1
	// to change it to 0, leftInd = 2*index+1, rightInd = 2*index+2
    void build (int start, int end, int index) {
		if(start == end) {
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
    	int leftInd = 2 * index + 1, rightInd = 2 * index + 2;
		build(start, mid, leftInd);
		build(mid + 1, end, rightInd);
		tree[index].merge(tree[leftInd], tree[rightInd]);
    }
	
	void apply (int start, int end, int index, Update &u) {
		// if not the leaf node
		if(start != end) {
			lazy[index] = 1; // update applied either directly or from the parent node
			
			// combine the current update with the existing update on this node index
			updates[index].combine(u, start, end);
		}
		
		u.apply(tree[index], start, end);
	}
	void pushdown (int start, int end, int index) {
		// if ther is no pending updates on this node then return
		if(!lazy[index]) return;
		
		// there are pending updates
		int mid = (start + end) / 2;
		int leftInd = 2 * index + 1, rightInd = 2 * index + 2;
		
		// apply updates on the left and right child of the current node
		apply(start, mid, leftInd, updates[index]);
        apply(mid + 1, end, rightInd, updates[index]);
		
		// set to default update, as no updates are pending for current node now
		updates[index] = Update();
		lazy[index] = 0;
	}
	void update (int start, int end, int index, int left, int right, Update &u) {
		// disjoint case
		if(start > right || end < left)
			return;
		
		if(start >= left && end <= right) { // complete overlap
			// apply update on current node directly
			// and save updates at current node for further use in the future
			apply(start, end, index, u);
			return;
		}
		
		// pushdown pending updates from this node to child nodes if any as we are going down
		pushdown(start, end, index);
		
		// partial overlap
		int mid = (start + end) / 2;
		int leftInd = 2 * index + 1, rightInd = 2 * index + 2;
		
		update(start, mid, leftInd, left, right, u);
		update(mid + 1, end, rightInd, left, right, u);
		
		tree[index].merge(tree[leftInd], tree[rightInd]);
	}
	
	Node query (int start, int end, int index, int left, int right) {
		if(start > right || end < left) { // disjoint case
			return Node(); // default value
		}
		
		if(start >= left && end <= right) { // complete overlap
			pushdown(start, end, index);
			return tree[index];
		}
		
		// pushdown pending updates from this node to child nodes if any as we are going down
		pushdown(start, end, index);
		
		// partial overlap
		int mid = (start + end) / 2;
		int leftInd = 2 * index + 1, rightInd = 2 * index + 2;
		
		Node res;
		Node leftItem = query(start, mid, leftInd, left, right);
		Node rightItem = query(mid + 1, end, rightInd, left, right);
		res.merge(leftItem, rightItem);
		return res;
	}
	
	
public:
	LazySegmentTree () {
		
	}
	
	LazySegmentTree (int n) {
		arr.resize(n, 0);
        size = n;
        tree.resize(4 * size + 1);
        lazy.resize(4 * size + 1);
        updates.resize(4 * size + 1);
        
        fill(begin(tree), end(tree), Node());
        fill(begin(lazy), end(lazy), 0);
        fill(begin(updates), end(updates), Update());
        
        build_tree();
    }
    
    LazySegmentTree (vector<T> &a) {
		arr = a;
		size = arr.size();

		tree.resize(4 * size + 1);
		lazy.resize(4 * size + 1);
		updates.resize(4 * size + 1);

		fill(begin(tree), end(tree), Node());
		fill(begin(lazy), end(lazy), 0);
		fill(begin(updates), end(updates), Update());

		build_tree();
    }
    
    LazySegmentTree (int n, vector<T> &a){
        arr = a;
        // size = 1;
        // while(size < 2 * n){
        //     size = size << 1;
        // }
        // tree.resize(size);
        // lazy.resize(size);
    	// updates.resize(size);
        // size = n; // reset back to n
        
        size = n;
        tree.resize(4 * size + 1);
    	lazy.resize(4 * size + 1);
    	updates.resize(4 * size + 1);

		fill(begin(tree), end(tree), Node());
		fill(begin(lazy), end(lazy), 0);
		fill(begin(updates), end(updates), Update());
        
        build_tree();
    }
    
    void build_tree () {
		build(0, size - 1, 0);
    }
    
    void make_update (int left, int right, long long value) {
		Update u = Update(value);
		return update(0, size - 1, 0, left, right, u);
    }
    
    Node make_query (int left, int right) {
		return query(0, size - 1, 0, left, right);
    }
    
    void debug_sgt(){
    	// debugging
        // for(auto node : tree) cout << node.val << " ";
        // cout << endl;
    }
};

// Make Changes Here------------------------------------------------
struct Node {
    // long long sum;
    // int mx, mn;
    long long val; // type may change
    
    Node(){ // identity or default element
    	// sum = 0;
    	// mx = -1e9;
    	// mn = 1e9;
    	val = 0; // may change
    }
    
    Node(long long val1){ // Actual node
    	// sum = val1;
    	// mx = val1;
    	// mn = val1;
    	val = val1; // may change
    }
    
    void merge (Node &left, Node &right) { // merge two child nodes
    	// sum = left.sum + right.sum;
    	// mx = max(left.mx, right.mx);
    	// mn = min(left.mn, right.mn);
    	val = left.val + right.val; // operation may change
    }
};

struct Update {
	long long val; // type may change
	
	Update(){ // identity update
		val = 0; // default update
	}
	
	// Actual Update
	Update(long long val1){
		val = val1; // may change
	}
	
	void apply (Node &node, int start, int end) {
		// int len = end - start + 1;
		// node.sum = len * val;
		// node.mn = val;
		// node.mx = val;
		
		node.val = val;
	}
	
	// combinational logic
	void combine (Update &new_update, int start, int end) {
		val = new_update.val;
	}
};

//*------------------------------------Lazy Segment Tree Ends------------------------------------

void solve(){
	
	int n; cin >> n;
	
	vector<int> arr(n);
	for(auto &i : arr){
		cin >> i;
	}
	
	// LazySegmentTree<int> lazySGT(n, arr);
	// LazySegmentTree<int, Node, Update> lazySGT(n, arr);
}

int main(){
	solve();
}