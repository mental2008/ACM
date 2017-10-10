import java.util.*;

class Main extends no_smoking_Twan_Edmonds_Karp{}
class no_smoking_Twan_Edmonds_Karp {
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		int runs = sc.nextInt();
		while (runs --> 0) new no_smoking_Twan_Edmonds_Karp();
	}
	no_smoking_Twan_Edmonds_Karp() {
		read();
		System.out.println(solve());
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
	}
	class Node {
		ArrayList<Edge> edges = new ArrayList<Edge>();
		Edge parent;
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
				nodes[y][x] = new Node();
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
	
	int solve () {
		// find augmenting paths
		int total = 0;
		Path p;
		while ((p = findAugmentingPath()) != null) {
			augmentPath(p);
			total += p.flow;
		}
		return total;
	}
	
	Path findAugmentingPath() {
		// cleanup
		for (int y = 0 ; y < h ; ++y) {
			for (int x = 0 ; x < w ; ++x) {
				nodes[y][x].parent = null;
			}
		}
		// first node
		Queue<Path> q = new LinkedList<Path>();
		addEdges(q, source, Integer.MAX_VALUE);
		// find path
		Path path;
		while ((path = q.poll()) != null) {
			if (path.node == sink) return path;
			// try the neighbors
			addEdges(q, path.node, path.flow);
		}
		return null;
	}
	void addEdges(Queue<Path> q, Node node, int max_flow) {
		for (Edge e : node.edges) {
			int edge_flow = Math.min(e.cap-e.flow, max_flow);
			if (e.to.parent == null && e.to != source && edge_flow > 0) {
				e.to.parent = e;
				q.add(new Path(e.to, edge_flow));
			}
		}
	}
	
	void augmentPath(Path p) {
		for (Edge e = p.node.parent ; e != null ; e = e.from.parent) {
			e.flow      += p.flow;
			e.dual.flow -= p.flow;
		}
	}
	
}
