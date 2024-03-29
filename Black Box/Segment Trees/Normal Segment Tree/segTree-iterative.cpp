#include<bits/stdc++.h>
using namespace std;

/*
credits : 
https://codeforces.com/blog/entry/18051?#comment-229984
https://www.youtube.com/watch?v=8CuVOdIWLfA&ab_channel=QuarantineEngineers
*/

//*------------------------------------Segment Tree Starts------------------------------------

struct Node;
struct Update;

// {type of input array, Node logic, Update logic}
template <typename T, typename Node = Node, typename Update = Update>
class SegmentTree {
private: 
	vector<Node> tree;
	vector<T> arr;
	int n = 0;
	
	// root index is 1
    void build () {
    	// filling leaf nodes
    	for (int i = 0; i < n; ++i) tree[i+n] = arr[i];
    	
    	for (int index = n - 1; index > 0; --index) tree[index].merge(tree[index<<1], tree[index<<1 | 1]);
    }
	
	void update (int p, Update &u) {
		// set value at position p
		for (u.apply(tree[p += n]); p > 1; p >>= 1) tree[p>>1].merge(tree[p], tree[p^1]);
		
		// p += n;
		// u.apply(tree[p+n]);
		// for (; p > 1; p >>= 1) tree[p>>1].merge(tree[p], tree[p^1]);
	}
	
	Node query (int left, int right) {
		Node res = Node(); // initialize with default value
		
		for(left += n, right += n; left <= right; left >>= 1, right >>= 1){
			
			// if left is an odd node
			if(left & 1) res.merge(res, tree[left++]);
			
			// if right is an even node
			if(!(right & 1)) res.merge(res, tree[right--]);
		}
		return res;
		
		
		/*
		for(left += n, right += n+1; left < right; left >>= 1, right >>= 1){
			if(left & 1) res.merge(res, tree[left++]); // if left is an odd node
			if(right & 1) res.merge(res, tree[--right]); // if right is an odd node
		}
		return res;
		*/
	}
	
public:
	// default constructor
	SegmentTree () {
	}
    
    SegmentTree (vector<T> &a) {
    	arr = a;
    	n = arr.size();
    	tree.resize(2 * n + 1);
    	fill(begin(tree), end(tree), Node()); // fill with default values
    	build_tree();
    }
    
    SegmentTree (int size, vector<T> &a){
        arr = a;
        n = size;
        tree.resize(2 * n + 1);
        fill(begin(tree), end(tree), Node()); // fill with default values
        build_tree();
    }
    
    // to initialize seg tree
    void build_tree () {
    	build();
    }
    
    void make_update (int index, long long value) {
    	Update u = Update(value);
    	update(index, u);
    }
    
    Node make_query (int left, int right) {
    	return query(left, right);
    }
    
    void debug_sgt(){
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
	
	// // whenever there is an update
	// // update at index ind to x
	SGT.make_update(2, 1); // let ind = 1 x = 10
	
	cout << SGT.make_query(0, 3).val << endl;
}

int main(){
	solve();
}