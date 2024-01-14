#include<bits/stdc++.h>
using namespace std;

//*------------------------------------Segment Tree Starts------------------------------------

struct Node;
struct Update;

// {type of input array, Node logic, Update logic}
template <typename T, typename Node = Node, typename Update = Update>
class SegmentTree {
private: 
	vector<Node> tree;
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
    	int leftInd = 2 * index, rightInd = 2 * index + 1;
    	build(start, mid, leftInd);
    	build(mid + 1, end, rightInd);
    	tree[index].merge(tree[leftInd], tree[rightInd]);
    }
	
	void update (int start, int end, int index, int query_index, Update &u) {
		if(start == end) {
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) / 2;
		int leftInd = 2 * index, rightInd = 2 * index + 1;
		if(query_index <= mid)
			update(start, mid, leftInd, query_index, u);
		else 
			update(mid + 1, end, rightInd, query_index, u);
		tree[index].merge(tree[leftInd], tree[rightInd]);
	}
	
	Node query (int start, int end, int index, int left, int right) {
		if(start > right || end < left) { // disjoint
			return Node(); // default value
		}
		if(start >= left && end <= right) { // complete overlap
			return tree[index];
		}
		
		// partial overlap
		int mid = (start + end) / 2;
		int leftInd = 2 * index, rightInd = 2 * index + 1;
		
		Node res;
		Node leftItem = query(start, mid, leftInd, left, right);
		Node rightItem = query(mid + 1, end, rightInd, left, right);
		res.merge(leftItem, rightItem);
		return res;
	}
	
public:
	// default constructor
	SegmentTree () {
	}
    
    // initialized seg tree
    SegmentTree (vector<T> &a) {
    	arr = a;
    	size = arr.size();
    	tree.resize(4 * size + 1);
    	build_tree();
    }
    
    // optimized seg tree constructor
    SegmentTree (int n, vector<T> &a){
        arr = a;
        // size = 1;
        // while(size < 2 * n){
        //     size = size << 1;
        // }
        // tree.resize(size);
        // size = n; // reset back to n
        
        size = n;
        tree.resize(4 * size + 1);
        
        fill(begin(tree), end(tree), Node()); // fill with default values
        build_tree();
    }
    
    // to initialize seg tree
    void build_tree () {
    	build(0, size - 1, 1);
    	
    	// debugging
        // for(auto node : tree) cout << node.val << " ";
        // cout << endl;
    }
    
    void make_update (int index, long long value) {
    	Update u = Update(value);
    	update(0, size - 1, 1, index, u);
    	
    	// debugging
        // for(auto node : tree) cout << node.val << " ";
        // cout << endl;
    }
    
    Node make_query (int left, int right) {
    	return query(0, size - 1, 1, left, right);
    	
    	// debugging
        // for(auto node : tree) cout << node.val << " ";
        // cout << endl;
    }
};

struct Node {
    long long val; // type may change
    
    Node(){ // identity or default element
    	val = 0; // may change
    }
    
    Node(long long val1){ // Actual node
    	val = val1; // may change
    }
    
    void merge (Node &left, Node &right) { // merge two child nodes
    	val = left.val + right.val; // operation may change
    }
};

struct Update {
	long long val; // type may change
	
	// Actual Update
	Update(long long val1){
		val = val1; // may change
	}
	
	void apply (Node &node) {
		node.val = val; // may change
	}
};

//*------------------------------------Segment Tree Ends------------------------------------

void solve(){
	
	int n; cin >> n;
	
	vector<int> arr(n);
	for(auto &i : arr){
		cin >> i;
	}
	
	SegmentTree<int, Node, Update> SGT(n, arr);
	
	cout << SGT.make_query(0, 3).val << endl;
	cout << SGT.make_query(3, 5).val << endl;
	cout << SGT.make_query(2, 6).val << endl;
	
	// whenever there is an update
	// update at index ind to x
	SGT.make_update(2, 1); // let ind = 1 x = 10
	
	cout << SGT.make_query(0, 3).val << endl;
}

int main(){
	solve();
}