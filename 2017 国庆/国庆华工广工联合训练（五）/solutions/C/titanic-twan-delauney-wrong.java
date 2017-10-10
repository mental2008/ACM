import java.util.*;
import java.io.*;

class Main extends titanic_Twan_delauney_wrong {}
class titanic_Twan_delauney_wrong {
	static Scanner sc = new Scanner(System.in);
	static int run;
	
	public static void main(String[] args) {
		int runs = sc.nextInt();
		for (run = 0 ; run < runs ; ++run) {
			new titanic_Twan_delauney_wrong();
		}
	}
	
	titanic_Twan_delauney_wrong() {
		readInput();
		double max_r_sqr = solve();
		double max_r = Math.max(0, Math.sqrt(max_r_sqr) - 2 + EPSILON);
		long n = (long)Math.floor(sqr(max_r) * Math.PI);
		System.out.println(n);
	}
	
	// ---------------------------------------------------------------------------
	// Config
	// ---------------------------------------------------------------------------
	
	static final double EPSILON = 1e-6;
	static final boolean RECURSE_LEGALIZE = false;
	static final boolean SHUFFLE_POINTS = true;
	static final boolean WRITE_ESCAPE_TRIANGULATION = false;
	static final boolean WRITE_TRIANGULATION = false;
	
	// ---------------------------------------------------------------------------
	// Input
	// ---------------------------------------------------------------------------
	
	static class Point {
		double x,y;
		boolean special;
		
		Point() {}
		Point(double x, double y, boolean special) {
			this.x = x;
			this.y = y;
			this.special = special;
		}
		
		public String toString() {
			if (special) {
				return String.format("[%+.1f,%+.1f]",x,y);
			} else {
				return String.format("(%+.1f,%+.1f)",x,y);
			}
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
	// Delauney triangulation
	// ---------------------------------------------------------------------------
	
	static final double sqr(double x) {
		return x*x;
	}
	static final double dist_sqr(Point a, Point b) {
		return sqr(a.x - b.x) + sqr(a.y - b.y);
	}
	static final double side(Point a, Point b, Point p) {
		return (p.x-a.x) * (b.y-a.y) - (p.y-a.y) * (b.x-a.x);
	}
	static final Point mean_point(Point a, Point b) {
		return new Point(0.5*(a.x+b.x),0.5*(a.y+b.y),false);
	}
	
	static class Triangle {
		Point a,b,c; // in counter-clockwise order
		Edge bc,ca,ab;
		Triangle children[];
		
		Triangle(Point a, Point b, Point c, Edge bc, Edge ca, Edge ab) {
			this.a  = a;  this.b  = b;  this.c  = c;
			this.bc = bc; this.ca = ca; this.ab = ab;
		}
		Triangle(Point a, Point b, Point c, Edge bc,Edge ca,Edge ab, Triangle bcr,Triangle car,Triangle abr) {
			this.a  = a;  this.b  = b;  this.c  = c;
			this.bc = bc; this.ca = ca; this.ab = ab;
			bc.replace(bcr, this, 0);
			ca.replace(car, this, 1);
			ab.replace(abr, this, 2);
		}
		
		public String toString() {
			return "<" + a + " " + b + " " + c + ">";
		}
		
		final boolean almostContains(Point p) {
			double sa = side(a,b,p);
			double sb = side(b,c,p);
			double sc = side(c,a,p);
			return (sa <=  EPSILON && sb <=  EPSILON && sc <=  EPSILON)
			    || (sa >= -EPSILON && sb >= -EPSILON && sc >= -EPSILON);
		}
		
		Triangle findContaining(Point p) {
			if (children == null) {
				if (almostContains(p)) {
					return this;
				} else {
					throw new RuntimeException("point outside triangle");
				}
			}
			for (Triangle x : children) {
				if (x.almostContains(p)) return x.findContaining(p);
			}
			throw new RuntimeException("no subtriangle contains this point");
		}
		
		boolean hasCorner(Point p) {
			return p == a || p == b || p == c;
		}
		
		Point getCorner(int i) {
			if (i%3 == 0) return a;
			if (i%3 == 1) return b;
			else          return c;
		}
		Edge getEdge(int i) {
			if (i%3 == 0) return bc;
			if (i%3 == 1) return ca;
			else          return ab;
		}
		
		void insertPoint(Point p) {
			Triangle t = findContaining(p);
			t.split(p);
		}
		private void split(Point p) {
			if (children != null) throw new RuntimeException();
			// new edges
			Edge ap = new Edge();
			Edge bp = new Edge();
			Edge cp = new Edge();
			// new triangles
			Triangle tab = new Triangle(a,b,p, bp,ap,ab, null,null,this);
			Triangle tbc = new Triangle(b,c,p, cp,bp,bc, null,null,this);
			Triangle tca = new Triangle(c,a,p, ap,cp,ca, null,null,this);
			// set children
			children = new Triangle[] {tab,tbc,tca};
			// legalize edges
			ab.flipIllegal();
			bc.flipIllegal();
			ca.flipIllegal();
		}
		
		/*
		void setDual(Triangle old, Triangle nw) {
			if (old == bc) bc = nw;
			if (old == ca) ca = nw;
			if (old == ab) ab = nw;
		}
		Point getOpposite(Triangle old) {
			if (old == bc) return a;
			if (old == ca) return b;
			if (old == ab) return c;
		}
		*/
		Point getCenter() {
			return new Point((a.x+b.x+c.x)/3,(a.y+b.y+c.y)/3,false);
		}
	}
	
	static class Edge {
		Triangle a,b;
		int ai,bi;
		
		Triangle dual(Triangle t) {
			if (t == a) return b;
			if (t == b) return a;
			else        throw new RuntimeException("edge doesn't contain triangle, so no dual");
		}
		
		void check() {
			if (a == null || b == null) return;
			if (a.getEdge(ai) != this) throw new RuntimeException("wrong edge");
			if (b.getEdge(bi) != this) throw new RuntimeException("wrong edge");
			if (a.getCorner(ai+1) != b.getCorner(bi+2)) {
				/*try {
					PrintStream out = new PrintStream("error.svg");
					writeSVG_begin(out);
					writeSVG(out,a,"flop");
					writeSVG(out,b,"flop");
					writeSVG_end(out);
				} catch (Exception e) {}*/
				throw new RuntimeException("point mismatch "+a.getCorner(ai+1)+" != "+b.getCorner(bi+2) + "\nbetween: "+a+" and " +b);
			}
			if (a.getCorner(ai+2) != b.getCorner(bi+1)) {
				throw new RuntimeException("point mismatch "+a.getCorner(ai+2)+" != "+b.getCorner(bi+1) + "\nbetween: "+a+" and " +b);
			}
		}
		
		void replace(Triangle x, Triangle by, int by_i) {
			if (a == x) {
				a = by; ai = by_i;
			}
			else if (b == x) {
				// make the new one into a
				//b = by; bi = by_i;
				b = a;  bi = ai;
				a = by; ai = by_i;
			}
			else throw new RuntimeException("edge doesn't contain triangle, so can't replace");
			check();
		}
		
		boolean flipIllegal() {
			if (a == null || b == null) return false; // outer edge
			// the 4 corner points
			Point p1 = a.getCorner(ai);   // only in a
			Point p2 = a.getCorner(ai+1); // in a and b (on this edge)
			Point p3 = b.getCorner(bi);   // only in b
			Point p4 = a.getCorner(ai+2); // in a and b (on this edge)
			if (p2 != b.getCorner(bi+2)) throw new RuntimeException("mismatching triangles at "+p2+" "+b.getCorner(bi+2));
			if (p4 != b.getCorner(bi+1)) throw new RuntimeException("mismatching triangles at "+p4+" "+b.getCorner(bi+1));
			// is this a legal edge?
			if (legalEdge(p1,p2,p3,p4)) return false;
			//System.err.println("flip "+a+"  "+b);
			// not legal, flip (p2,p4) to (p1,p3)
			// the 4 edges
			Edge e12 = a.getEdge(ai+2); // in a
			Edge e23 = b.getEdge(bi+1); // in b
			Edge e34 = b.getEdge(bi+2); // in b
			Edge e41 = a.getEdge(ai+1); // in a
			// make new triangles
			Edge e13 = new Edge();
			Triangle c = new Triangle(p1,p2,p3, e23,e13,e12,  b,null,a);
			Triangle d = new Triangle(p1,p3,p4, e34,e41,e13,  b,a,null);
			// set children in lookup structure
			if (a.children != null) throw new RuntimeException();
			if (b.children != null) throw new RuntimeException();
			a.children = b.children = new Triangle[] {c,d};
			if (RECURSE_LEGALIZE) {
				/*if (false) {
					n++;
					if (n > 200) throw new RuntimeException("asdF");
					try {
						PrintStream out = new PrintStream("postflip"+n+".svg");
						writeSVG_begin(out);
						writeSVG(out,b,"flip");
						writeSVG(out,c,"flop");
						writeSVG_end(out);
					} catch (Exception e) {}
					System.err.println("["+n);
				}*/
				e12.flipIllegal();
				e23.flipIllegal();
				e34.flipIllegal();
				e41.flipIllegal();
			}
			return true;
		}
		private boolean legalEdge(Point p1, Point p2, Point p3, Point p4) {
			if (p2.special && p4.special) return true; // keep outer edge
			//if () return false;
			//int num_special = (p1.special?1:0);
			// does p3 lie in <p1 p2 p4>?
			double u11 = p1.x - p3.x;
			double u21 = p2.x - p3.x;
			double u31 = p4.x - p3.x;
			double u12 = p1.y - p3.y;
			double u22 = p2.y - p3.y;
			double u32 = p4.y - p3.y;
			double u13 = sqr(p1.x) - sqr(p3.x) + sqr(p1.y) - sqr(p3.y);
			double u23 = sqr(p2.x) - sqr(p3.x) + sqr(p2.y) - sqr(p3.y);
			double u33 = sqr(p4.x) - sqr(p3.x) + sqr(p4.y) - sqr(p3.y);
			double det = -(u13*u22*u31) + u12*u23*u31 + u13*u21*u32 - u11*u23*u32 - u12*u21*u33 + u11*u22*u33;
			return det >= -EPSILON;
		}
		
		final double r_sqr() {
			if (a != null) {
				return 0.25 * dist_sqr(a.getCorner(ai+1),a.getCorner(ai+2));
			} else {
				return 0.25 * dist_sqr(b.getCorner(bi+1),b.getCorner(bi+2));
			}
		}
		Point getCenter() {
			if (a != null) {
				return mean_point(a.getCorner(ai+1),a.getCorner(ai+2));
			} else {
				return mean_point(b.getCorner(bi+1),b.getCorner(bi+2));
			}
		}
	}
	
	Triangle root;
	void buildTriangulation() {
		// initial triangle
		double lots = 1e6;
		Point p1 = new Point( lots,-lots,true);
		Point p2 = new Point(-lots,-lots,true);
		Point p3 = new Point(0,     lots,true);
		Edge e1 = new Edge();
		Edge e2 = new Edge();
		Edge e3 = new Edge();
		root = new Triangle(p1,p2,p3, e1,e2,e3, null,null,null);
		// shuffle points?
		if (SHUFFLE_POINTS) {
			final Random r = new Random(1234);
			Arrays.sort(points,new Comparator<Point>(){
				public int compare(Point a, Point b) {
					return r.nextBoolean() ? -1 : 1;
				}
			});
		}
		// add points
		for (Point p : points) root.insertPoint(p);
	}
	
	// ---------------------------------------------------------------------------
	// Dijkstra stuff
	// ---------------------------------------------------------------------------
	
	// distance from starting point to a mine
	double maxInitialRSqr() {
		double max_r_sqr = Double.MAX_VALUE;
		for (Point p : points) {
			max_r_sqr = Math.min(max_r_sqr, dist_sqr(origin,p));
		}
		return max_r_sqr;
	}
	
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
	
	double widestPath() {
		HashMap<Triangle,Double> best = new HashMap<Triangle,Double>();
		PriorityQueue<PathTo> pq = new PriorityQueue<PathTo>();
		// starting point
		double start_r_sqr = maxInitialRSqr();
		Triangle start_tri = root.findContaining(origin);
		best.put(start_tri,start_r_sqr);
		pq.add(new PathTo(start_tri,start_r_sqr));
		// do the Dijkstra, la la la
		PathTo here;
		while ((here = pq.poll()) != null) {
			// move to neighbors
			for (Edge e : new Edge[] { here.t.ab, here.t.bc, here.t.ca }) {
				Triangle t2 = e.dual(here.t);
				double new_r_sqr = Math.min(here.r_sqr, e.r_sqr());
				if (t2 == null) {
					// escaped
					if (WRITE_ESCAPE_TRIANGULATION) writeEscapeSVG(best);
					return new_r_sqr;
				} else {
					Double old_r_sqr = best.get(t2);
					if (old_r_sqr == null || old_r_sqr < new_r_sqr) {
						best.put(t2, new_r_sqr);
						pq.add(new PathTo(t2, new_r_sqr));
					}
				}
			}
		}
		// can't escape
		return 0;
	}
	
	double solve() {
		buildTriangulation();
		if (WRITE_TRIANGULATION) try {
			writeSVG(new PrintStream("run-"+run+".svg"));
		} catch (Exception e) {}
		return widestPath();
	}
	
	// ---------------------------------------------------------------------------
	// Debugging : svg output
	// ---------------------------------------------------------------------------
	
	void writeSVG(PrintStream out) {
		writeSVG_begin(out);
		writeSVG_end(out);
	}
	void writeSVG_begin(PrintStream out) {
		// bounds
		int y0=0,y1=0,x0=0,x1=0;
		for (Point p:points) {
			x0 = Math.min(x0,(int)p.x);
			y0 = Math.min(y0,(int)p.y);
			x1 = Math.max(x1,(int)p.x);
			y1 = Math.max(y1,(int)p.y);
		}
		x0 -= 4; y0 -= 4; x1 += 4; y1 += 4;
		// stylesheet
		out.println("<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 1.1//EN'  'http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd'>");
		out.print("<svg viewBox='"+x0+","+y0+","+(x1-x0)+","+(y1-y0)+"' width='100%' height='100%' version='1.1' xmlns='http://www.w3.org/2000/svg'>");
    	out.println(" <style>");
    	out.println("   * { ");
    	out.println("     stroke: black;");
    	out.println("     stroke-width: 0.05;");
    	out.println("   }");
    	out.println("   circle {");
    	out.println("     fill: red;");
    	out.println("     fill-opacity: 0.3;");
    	out.println("     stroke: red;");
    	out.println("   }");
    	out.println("   .center {");
    	out.println("     fill: red;");
    	out.println("     fill-opacity: 1;");
    	out.println("   }");
    	out.println("   .me {");
    	out.println("     fill: green;");
    	out.println("   }");
    	out.println("   .grid {");
    	out.println("     stroke: #ccc;");
    	out.println("   }");
    	out.println("   .hull {");
    	out.println("     stroke: #00d;");
    	out.println("   }");
    	out.println("   .escape {");
    	out.println("     stroke-width: 0;");
    	out.println("     fill:   green;");
    	out.println("   }");
    	out.println("   .triangle {");
    	out.println("     stroke: #00d;");
    	out.println("     fill: blue;");
    	out.println("     fill-opacity: 0.1;");
    	out.println("   }");
    	out.println("   .triangle:hover {");
    	out.println("     stroke: #c0d;");
    	out.println("     fill: #c0d;");
    	out.println("     fill-opacity: 0.3;");
    	out.println("   }");
    	out.println("   .flip {");
    	out.println("     stroke: #0d0;");
    	out.println("     fill: green;");
    	out.println("   }");
    	out.println("   .flop {");
    	out.println("     stroke: #d00;");
    	out.println("     fill: yellow;");
    	out.println("   }");
    	out.println(" </style>");
    	// write grid
    	int step = Math.max(1, Math.max((x1-x0)/50, (y1-y0)/50));
    	for (int x = x0 ; x <= x1 ; x+=step) {
    		out.println(" <line x1='"+x+"' x2='"+x+"' y1='"+y0+"' y2='"+y1+"' class='grid' />");
    	}
    	for (int y = y0 ; y <= y1 ; y+=step) {
    		out.println(" <line x1='"+x0+"' x2='"+x1+"' y1='"+y+"' y2='"+y+"' class='grid' />");
    	}
    	// write mines
    	for (Point p : points) {
    		out.println(" <circle cx='"+p.x+"' cy='"+p.y+"' r='2' />");
     		out.println(" <circle cx='"+p.x+"' cy='"+p.y+"' r='0.1' class='center'/>");
    	}
    	// write triangulation
    	writeSVG(out,root,"triangle");
    }
    
	void writeSVG_end(PrintStream out) {
    	// write me
		out.println(" <rect x='-0.5' y='-0.5' width='1' height='1' class='me'/>");
    	out.println("</svg>");
	}
	
	void collectTriangles(HashSet<Triangle> out, Triangle t) {
		if (out.contains(t)) return;
		out.add(t);
		if (t.children != null) {
			for (Triangle c : t.children) {
				collectTriangles(out,c);
			}
		}
	}
	void writeSVG(PrintStream out, Triangle root, String cls) {
		HashSet<Triangle> tris = new HashSet<Triangle>();
		collectTriangles(tris,root);
		for (Triangle t : tris) {
			if (t.children == null && !t.a.special && !t.b.special && !t.c.special) {
				out.println(" <polygon points='"+t.a.x+","+t.a.y+" "+t.b.x+","+t.b.y+" "+t.c.x+","+t.c.y+"' class='"+cls+"' />");
			}
		}
	}
	
	void writeEscapeSVG(HashMap<Triangle,Double> best) {
		// print widths
		try {
			PrintStream out = new PrintStream("escape.svg");
			writeSVG_begin(out);
			for(Map.Entry<Triangle,Double> entry : best.entrySet()) {
				Triangle t = entry.getKey();
				for (Edge ee : new Edge[] { t.ab, t.bc, t.ca }) {
					Point p = ee.getCenter();
					double r = Math.sqrt(Math.min(ee.r_sqr(),entry.getValue())) - 2;
					if (r > 0)
					out.println(" <circle cx='"+p.x+"' cy='"+p.y+"' r='"+r+"' class='escape' />");
				}
			}
			writeSVG_end(out);
		} catch (Exception exasdf) {}
	}
}
