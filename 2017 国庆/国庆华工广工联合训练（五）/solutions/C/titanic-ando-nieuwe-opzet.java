import java.io.*;
import java.lang.*;
import java.util.*;

class Main extends Titanic_ando {} // for DOMJudge


class Coord {
	long x; // can be negative
	long y;

	public Coord(long x, long y) {
		this.x = x;
		this.y = y;
	}

	public String toString() {
		return "("+x+","+y+")";
	}

	public long liesLeftOf(Coord p, Coord q) {
		// return >0 if this point lies left of line trhough p and q
		// 0 if on it, <0 if right from it
		return ((q.x*y - x*q.y) - (p.x*y - x*p.y) + (p.x*q.y - p.y*q.x));
	}

	public long liesInCircumCircle(Coord a, Coord b, Coord c) {
		// this is d
		//
		// returns >0 if it lies in circumcircle
		// 0 if on circumcircle
		// <0 if outside circumcircle
		Coord[] cs = {a,b,c};
		long[][] m = new long[3][3];
		for(int i = 0;i<3;++i) {
			m[i][0] = cs[i].x - x;
			m[i][1] = cs[i].y - y;
			m[i][2] = (cs[i].x*cs[i].x - x*x) + (cs[i].y*cs[i].y - y*y);
		}
		return determinant3(m);
	}

	private long determinant3(long[][] m) {
		long s = 0;
		s+= m[0][0]* determinant2(m[1][1],m[1][2],m[2][1],m[2][2]);
		s-= m[1][0]* determinant2(m[0][1],m[0][2],m[2][1],m[2][2]);
		s+= m[2][0]* determinant2(m[0][1],m[0][2],m[1][1],m[1][2]);
		return s;
	}

	private static long determinant2(long a, long b, long c, long d) {
		return (a*d) - (c*b);
	}
}

class Vertex {
	public static final int RIGHT = -1;
	public static final int TOP   = -2;
	public static final int DOWNBELOWBYTHEWATERFALL = -3;
	public static final int REGULAR = 0;

	Coord c;
	int type;

	public Vertex(Coord c, int type) {
		this.c = c;
		this.type = type;
	}

	public boolean isOuter() {
		return (type < 0);
	}
}

class Edge {
	Triangle[] triangles = new Triangle[2]; // arbitrary order

	public Edge() {
	}
}

class Triangle {
	Vertex[] vertices = new Vertex[3];  // for splitting hairs
	Edge[] edges = new Edge[3];  // counterclockwise

	public Triangle() {
	}

	// check this below
	public int containsPoint(Coord c) {
		// vertices array is in order with inside face to hte left
		// return value: 0 = if not contains, 1 = on edge, 2 = interior
		long s = 1;
		for(int i=0;i<3;++i) {
			// only one has to be one
			long d = c.liesLeftOf(vertices[i].coords,vertices[(i+1)%3].coords);
			//System.out.println(r+" lies left of "+p+" -> "+q+"\t\t\t"+d);
			if (d < 0) return 0;
			s = min(s,d);
		}
		return (s == 0)?1:2;
	}

	public static long min(long a, long b) {
		return ((b<a)?b:a);
	}

}

class Dag {
	Triangle triangle;
	Dag[] children = new Dag[3]; // because 3 is maxdepth
	int nrChildren = 0;

	public Dag(Triangle child, Triangle parent1, Triangle parent2) {
		// arguments are optional
		// The constructor of Triangle should set its
		// Dag value, we don't set it here explicitly
		this.triangle = child;
		if (parent1 != null) parent1.dag.addChild(this);
		if (parent2 != null) parent2.dag.addChild(this);
	}

	public void addChild(Dag d) {
		if (nrChildren == 3) throw new RuntimeException("dag already has three childs");
		children[nrChildren++] = d;
	}

	public Triangle findTriangleOf(Coord c) {
		// nonrecursive, we are the root, triangle always exists.
		Dag d = this;
		boolean goagain = true;
		while (goagain) {
			goagain = false;
			for(int i=0;i<d.nrChildren;++i) {
				if(d.children[i].triangle.containsPoint(c) != 0) {
					d = d.children[i];
					goagain = true;
					break;
				}
			}
			if((goagain == false) && (d.nrChildren > 0)) {
				throw new RuntimeException("point not found");
			}
		}
		return d.triangle;
	}
}


class Triangulation {
	public static final long MAX_COORD = 1000;

	public Triangulation() {
		Vertex v1 = new Vertex(new Coord(3*MAX_COORD,0),Vertex.RIGHT);
		Vertex v2 = new Vertex(new Coord(0,3*MAX_COORD),Vertex.TOP);
		Vertex v3 = new Vertex(new Coord(-3*MAX_COORD,-3*MAX_COORD),Vertex.DOWNBELOWBYTHEWATERFALL);
	}
}

class Titanic_ando {

	static Scanner sc = new Scanner(System.in);

	private static long leesInt() throws IOException {
		return sc.nextLong();
	}

	private static String leesRegel() throws IOException {
		return sc.next(); // reads a word, not a line
	}

	public static void main(String argv[]) throws IOException {
		long runCnt = leesInt();
		for (long i = 0;i < runCnt; i++) {
			run();
		}
	}

	private static void run() throws IOException {
		int n = (int)leesInt();


	}

}
