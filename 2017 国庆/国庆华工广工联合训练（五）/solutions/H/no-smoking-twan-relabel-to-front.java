import java.util.*;

class Main extends no_smoking_Twan_relabel_to_front{}
class no_smoking_Twan_relabel_to_front {
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		int runs = sc.nextInt();
		while (runs --> 0) new no_smoking_Twan_relabel_to_front();
	}
	no_smoking_Twan_relabel_to_front() {
		read();
		solve();
		System.out.println(-sink.outflow());
	}
	
	// ---------------------------------------------------------------------------
	// Data structures
	// ---------------------------------------------------------------------------
	
	class Edge {
		Node from,to;
		int cap,flow;
		Edge dual;
		Edge(Node from, Node to, int cap) {
			this.from = from;
			this.to   = to;
			this.cap  = cap;
			this.flow = 0;
		}
		
		boolean push() {
			assert(from.excess > 0);
			assert(from.height > to.height);
			int amount = Math.min(from.excess, cap - flow);
			if (amount <= 0) return false;
			flow      += amount;
			dual.flow -= amount;
			from.excess -= amount;
			to.excess   += amount;
			return true;
		}
	}
	class Node {
		int y,x;
		Node(){}
		Node(int y,int x) {this.y=y;this.x=x;}
		
		ArrayList<Edge> edges = new ArrayList<Edge>();
		
		int outflow() {
			int total = 0;
			for (Edge e : edges) total += e.flow;
			return total;
		}
		
		//boolean seen = false;
		int excess = 0;
		int height = 0;
		
		void relabel() {
			assert(excess > 0);
			height = Integer.MAX_VALUE;
			for (Edge e : edges) {
				assert(height <= e.to.height);
				if (e.cap - e.flow > 0) {
					height = Math.min(height, e.to.height + 1);
				}
			}
		}
		
	}
	
	// ---------------------------------------------------------------------------
	// Input
	// ---------------------------------------------------------------------------
	
	int h,w;
	Node[][] nodes;
	Node source,sink;
	
	int cap(int a) {
		return a == 0 ? 0 : 1000 * (a + 1);
	}
	void read() {
		h = sc.nextInt();
		w = sc.nextInt();
		
		nodes = new Node[h][w];
		for (int y = 0 ; y < h ; ++y) {
			for (int x = 0 ; x < w ; ++x) {
				nodes[y][x] = new Node(y,x);
			}
		}
		
		int ey = sc.nextInt();
		int ex = sc.nextInt();
		source = nodes[ey][ex];
		if (source==null) throw new RuntimeException("no source");
		
		int ky = sc.nextInt();
		int kx = sc.nextInt();
		sink = nodes[ky][kx];
		if (sink==null) throw new RuntimeException("no sink");
		if (source==sink) throw new RuntimeException("source == sink");
		
		for (int y = 0 ; y < h ; ++y) {
			for (int x = 0 ; x < w-1 ; ++x) {
				int c = sc.nextInt();
				if (c > 0) {
					Edge e1 = new Edge(nodes[y][x  ], nodes[y][x+1], cap(c));
					Edge e2 = new Edge(nodes[y][x+1], nodes[y][x  ], cap(c));
					e1.dual = e2; e2.dual = e1;
					nodes[y][x  ].edges.add(e1);
					nodes[y][x+1].edges.add(e2);
				}
			}
		}
		for (int y = 0 ; y < h-1 ; ++y) {
			for (int x = 0 ; x < w ; ++x) {
				int c = sc.nextInt();
				if (c > 0) {
					Edge e1 = new Edge(nodes[y  ][x], nodes[y+1][x], cap(c));
					Edge e2 = new Edge(nodes[y+1][x], nodes[y  ][x], cap(c));
					e1.dual = e2; e2.dual = e1;
					nodes[y  ][x].edges.add(e1);
					nodes[y+1][x].edges.add(e2);
				}
			}
		}
	}
	
	// ---------------------------------------------------------------------------
	// Solution
	// ---------------------------------------------------------------------------
	
	class Path {
		Node node;
		int flow;
		Path(Node node, int flow) {
			this.node = node;
			this.flow = flow;
		}
	}
	
	void dump() {
		System.err.println();
		for (int y = 0 ; y < h ; ++y) {
			for (int x = 0 ; x < w ; ++x) {
				Node n = nodes[y][x];
				System.err.print(n.height+":");
				if (n == source) {
					System.err.print("s ");
				} else if (n == sink) {
					System.err.print("t ");
				} else {
					System.err.print(n.excess/1000+" ");
				}
			}
			System.err.println();
		}
	}
	void solve() {
		// init
		source.excess = Integer.MAX_VALUE;
		source.height = h*w;
		sink.excess   = Integer.MIN_VALUE;
		// nodes to process
		Node[] list = new Node[h*w-2];
		int i = 0;
		for (int y = 0 ; y < h ; ++y) {
			for (int x = 0 ; x < w ; ++x) {
				Node n = nodes[y][x];
				if (n != source && n != sink) list[i++] = n;
			}
		}
		// push source
		for (Edge e : source.edges) e.push();
		// push relabel
		i = 0;
		while (i < list.length) {
			if (solveNode(list[i])) {
				Node n = list[i];
				for (int j = i-1 ; j >= 0 ; --j) list[j+1] = list[j];
				list[0] = n;
				i = 0;
			} else {
				i++;
			}
		}
	}
	boolean solveNode(Node n) {
		boolean relabeled = false;
		while (n.excess > 0) {
			boolean any_cap = false;
			boolean change = false;
			for (Edge e : n.edges) {
				if (e.cap - e.flow > 0) {
					any_cap = true;
					if (n.height > e.to.height) {
						//System.err.println("push from " + n.y + " " + n.x + " to " + e.to.y + " " + e.to.x + ": min(" + n.excess + "," + (e.cap-e.flow) + ")");
						e.push();
						change = true;
					}
				}
			}
			if (!change && any_cap) {
				n.relabel();
				//System.err.println("relabel " + n.y + " " + n.x + " now " + n.height);
				relabeled = true;
			}
		}
		return relabeled;
	}
	
	/*
	
		// init list
		Node[] list = new Node[h*w-2];
		int i = 0;
		for (int y = 0 ; y < h ; ++y) {
			for (int x = 0 ; x < w ; ++x) {
				if (nodes[y][x] != source && nodes[y][x] != sink) {
					list[i++] = nodes[y][x];
				}
			}
		}
	*/
}
