import java.util.*;

class Main extends titanic_Twan_slow{}
class titanic_Twan_slow {
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		int runs = sc.nextInt();
		while (runs --> 0) new titanic_Twan_slow();
	}
	titanic_Twan_slow() {
		readInput();
		double max_r_sqr = solve();
		double max_r = Math.max(0, Math.sqrt(max_r_sqr) - 2 + EPSILON);
		long n = (long)Math.floor(sqr(max_r) * Math.PI);
		System.out.println(n);
	}
	
	// ---------------------------------------------------------------------------
	// Input
	// ---------------------------------------------------------------------------
	
	class Point {
		double x,y;
		
		public String toString() {
			return String.format("(%+.1f,%+.1f)",x,y);
		}
	};
	
	Point origin = new Point(); // default (0,0)
	Point[] points;
	
	// 19:47-19:50
	void readInput() {
		int n = sc.nextInt();
		if (n <= 0 || n >= 1000000) {
			throw new RuntimeException("Too many points");
		}
		points = new Point[n];
		for (int i = 0 ; i < points.length ; ++i) {
			points[i] = new Point();
			points[i].x = sc.nextInt();
			points[i].y = sc.nextInt();
			if (points[i].x <= -1000000 || points[i].x >= 1000000 || points[i].y <= -1000000 || points[i].y >= 1000000) {
				throw new RuntimeException("Point outside valid range");
			}
		}
	}
	
	// ---------------------------------------------------------------------------
	// Edges with empty circles
	// ---------------------------------------------------------------------------
	
	static final double EPSILON = 1e-6;
	
	static final double sqr(double x) {
		return x*x;
	}
	static final double dist_sqr(Point a, Point b) {
		return sqr(a.x - b.x) + sqr(a.y - b.y);
	}
	
	class Circle extends Point {
		double r_sqr;
		int ai,bi;
		
		Circle(Point a, Point b, int ai, int bi) {
			this.x = 0.5 * (a.x + b.x);
			this.y = 0.5 * (a.y + b.y);
			this.r_sqr = dist_sqr(a,b) * 0.25;
			this.ai = ai;
			this.bi = bi;
		}
		
		final boolean certainlyContains(Point p) {
			return dist_sqr(this,p) < r_sqr - EPSILON;
		}
		final boolean almostContains(Point p) {
			return dist_sqr(this,p) < r_sqr + EPSILON;
		}
		
		final boolean isEmpty() {
			for (Point p : points) {
				if (certainlyContains(p)) {
					return false;
				}
			}
			return true;
		}
		
		public String toString() {
			return super.toString() + "_" + Math.sqrt(r_sqr);
		}
	}
	
	/*
	class Edge {
		Point a,b;
		double r_sqr;
	}
	class Polygon {
		ArrayList<Point> corners;
		ArrayList<Edge>  edges;
	}
	*/
	ArrayList<Circle> circles = new ArrayList<Circle>();
	ArrayList<Triangle> triangles = new ArrayList<Triangle>();
	
	// vertices in our graph are halfway between two mines
	void findCircles() {
		for (int i = 0 ; i < points.length ; ++i) {
			for (int j = 0 ; j < i ; ++j) {
				Circle c = new Circle(points[i],points[j], i,j);
				// is this circle empty?
				if (c.isEmpty()) {
					circles.add(c);
					if (DEBUG) System.err.println("Found " + c);
				}
			}
		}
	}
	
	
	// ---------------------------------------------------------------------------
	// Solution
	// 19:50-20:40 21:45-23:15 00:17-
	// ---------------------------------------------------------------------------
	
	class PathTo implements Comparable<PathTo> {
		Triangle t;
		double r_sqr;
		PathTo(Triangle t, double r_sqr) {
			this.t = t;
			this.r_sqr = r_sqr;
		}
		public int compareTo(PathTo p) {
			return -new Double(r_sqr).compareTo(p.r_sqr); // highest first
		}
	}
	
	static final boolean DEBUG = true;
	
	double solve() {
		// find valid halfway points
		findCircles();
		findTriangles();
		return trace();
	}
	double trace() {
		// initial point needs to be safe also
		double max_r_sqr = maxInitialRSqr();
		// initially the origin is reachable
		HashMap<Point,Double> best = new HashMap<Point,Double>();
		PriorityQueue<PathTo> pq = new PriorityQueue<PathTo>();
		best.put(origin, max_r_sqr);
		pq.add(new PathTo(origin, max_r_sqr));
		// do the Dijkstra, la la la
		double escape_r_sqr = 0;
		PathTo here;
		while ((here = pq.poll()) != null) {
			// we can reach p1 with r^2
			Point p1 = here.p;
			if (DEBUG) System.err.println("Reached " + here.p + " with r^2=" + here.r_sqr);
			// can we escape?
			boolean can_escape = canEscape.contains(here.p);
			if (can_escape) {
				if (DEBUG) System.err.println("Escaped from " + here.p + " with r^2=" + here.r_sqr);
				escape_r_sqr = Math.max(escape_r_sqr, here.r_sqr);
			}
			// move to neighbors
			for (int i = 0 ; i < here.p.edges.size() ; ++i) {
				double room = line_segment_room(p1,p2);
				double new_r_sqr = Math.min(here.r_sqr, room);
				Double old_r_sqr = best.get(p2);
				if (old_r_sqr == null || old_r_sqr < new_r_sqr - EPSILON) {
					best.put(p2, new_r_sqr);
					pq.add(new PathTo(p2, new_r_sqr));
				}
			}
		}
		return escape_r_sqr;
	}
}
