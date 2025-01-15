struct SegmentTree {
#define lc (node << 1)
#define rc ((node << 1) | 1)
	vector<ll>tree;
	vector<ll>lazy;
	SegmentTree() {
		tree.resize(4 * N);
		lazy.resize(4 * N);
		fill(tree.begin(), tree.end(), 0);
		fill(lazy.begin(), lazy.end(), -1);
	}
	void push(int node, int b, int e) {
		if (lazy[node] == -1)
			return ;
		tree[node] = (e - b + 1) * lazy[node];
		// as sum so oi value add hobe
		//but max min query hoile shudhu tree[node] = lazy[node] hoito
		// abar range update hoile hoito tree[node]+=lazy[node]
		if (b != e) {
			lazy[lc] = lazy[node];
			lazy[rc] = lazy[node];
		}
		lazy[node] = -1;
	}
	void build(int node, int b, int e, char c) {
		if (b == e) {
			tree[node] = s[b] == c;
			return ;
		}
		int mid = (b + e) >> 1;
		build(lc, b, mid, c);
		build(rc, mid + 1, e, c);
		tree[node] = tree[lc] + tree[rc];
	}
	void update(int node, int b, int e, int l, int r, int x) {
		push(node, b, e);
		if (e < l || b > r)
			return ;
		if (b >= l && e <= r) {
			lazy[node] = x;
			push(node, b, e);
			return ;
		}
		int mid = (b + e) >> 1;
		update(lc, b, mid, l, r, x);
    update(rc, mid + 1, e, l, r, x);
		tree[node] = tree[lc] + tree[rc];
	}
	int query(int node, int b, int e, int l, int r) {
		push(node, b, e);
		if (e < l || b > r)
			return 0;
		if (b >= l && e <= r) {
			return tree[node];
		}
		int mid = (b + e) >> 1;
		return (query(lc, b, mid, l, r) + query(rc, mid + 1, e, l, r));
	}
};
