import java.io.*;
import java.lang.*;
import java.util.*;


class Coord implements Comparable<Coord> {
	int r;
	int c;

	public Coord(int row, int column) {
		r = row;
		c = column;
	}

	public int compareTo(Coord other) {
		return (r - other.r) + (c - other.c);
	}
/*
	public boolean equals(Object o) {
		if (this == o) return true;
		if ((o == null) || (o.getClass() != this.getClass())) return false;
		Coord other = (Coord)o;
		return ((r == other.r) && (c == other.c));
	}

	public int hashCode() {
		int hash = 7;
		hash = 31 * hash * r;
		hash = 31 * hash * c;
		return hash;
	}
	*/
}

class Passage implements Comparable<Passage> {
	int area;
	int iteration;
	int degree;
	Coord from;
	Coord to;

	public Passage(Coord from, Coord to, int iteration, Layout l) {
		this.iteration = iteration;
		this.from = from;
		this.to = to;

		// determine area
		Coord f;
		Coord t;
		if (from.compareTo(to) < 0) {
			f = from;
			t = to;
		} else {
			// assume from != to
			f = to;
			t = from;
		}
		if (f.r < t.r) {
			// downpassage
			area = l.downpassage[f.r][f.c];
		} else {
			// rightpassage
			area = l.rightpassage[f.r][f.c];
		}

		// determine degree
		degree = l.degree(from) + l.degree(to);
	}

	public int compareTo(Passage other) {
		// NOTE: reverse sort!
		if(area != other.area) return other.area-area;
		if(iteration != other.iteration) return other.iteration-iteration;
		return other.degree-degree;
	}

}

class Layout {
	public static final int HATCH_COST = 1000;
	public static final int LOCK_COST_PSM = 1000;

	int[][] section;
	Coord e;
	Coord k;
	int nr;
	int nc;
	int[][] rightpassage;
	int[][] downpassage;

	public Layout(int nr, int nc, Coord e, Coord k, int[][] rightpassage, int[][] downpassage) {
		this.nr = nr;
		this.nc = nc;
		this.e = e;
		this.k = k;
		this.rightpassage = rightpassage;
		this.downpassage = downpassage;
		/*
		this.rightpassage = new int[nr][nc-1];
		for(int i=0;i<nr;++i) {
			for(int j=0;j<nc-1;++j) {
				this.rightpassage[i][j] = rightpassage[i][j];
			}
		}
		this.downpassage = new int[nr-1][nc];
		for(int i=0;i<nr-1;++i) {
			for(int j=0;j<nc;++j) {
				this.downpassage[i][j] = downpassage[i][j];
			}
		}
		*/
		section = new int[nr][nc];
		for(int i=0;i<nr;++i) {
			for(int j=0;j<nc;++j) {
				section[i][j] = -1;
			}
		}
		section[e.r][e.c] = 0;
		section[k.r][k.c] = 1;
	}

	public int sectionOf(Coord c) {
		return section[c.r][c.c];
	}

	public boolean isMarked(Coord c) {
		return (sectionOf(c) != -1);
	}

	public void markAs(Coord old, Coord to) {
		section[old.r][old.c] = sectionOf(to);
	}

	public int degree(Coord c) {
		int d = 0;
		if(c.r != 0) ++d;
		if(c.c != 0) ++d;
		if(c.r != nr-1) ++d;
		if(c.c != nc-1) ++d;
		return d;
	}

	public void addEdges(Coord c, PriorityQueue<Passage> edges, int iteration) {
		if(c.r != 0) addEdge(c,new Coord(c.r-1,c.c),edges,iteration);
		if(c.c != 0) addEdge(c,new Coord(c.r,c.c-1),edges,iteration);
		if(c.r != nr-1) addEdge(c,new Coord(c.r+1,c.c),edges,iteration);
		if(c.c != nc-1) addEdge(c,new Coord(c.r,c.c+1),edges,iteration);
	}

	private void addEdge(Coord from, Coord to, PriorityQueue<Passage> edges, int iteration) {
		if (!isMarked(to)) {
			edges.add(new Passage(from,to,iteration,this));
		}
	}

	void markCells() {
		int iteration = 0;
		PriorityQueue<Passage> edges = new PriorityQueue<Passage>();
		addEdges(k,edges,iteration);
		addEdges(e,edges,iteration);
		while (!edges.isEmpty()) {
			Passage p = edges.poll();
			if (!isMarked(p.to)) {
				iteration++;
				markAs(p.to,p.from);
				addEdges(p.to,edges,iteration);
			}
		}
	}

	public long computeCosts() {
		long costs = 0;
		for(int i=0;i<nr;++i) {
			for(int j=0;j<nc-1;++j) {
				if(section[i][j] != section[i][j+1]) {
					if(rightpassage[i][j] != 0) {
						costs+=HATCH_COST + (LOCK_COST_PSM*rightpassage[i][j]);
					}
				}
			}
		}
		for(int i=0;i<nr-1;++i) {
			for(int j=0;j<nc;++j) {
				if(section[i][j] != section[i+1][j]) {
					if(downpassage[i][j] != 0) {
						costs+=HATCH_COST + (LOCK_COST_PSM*downpassage[i][j]);
					}
				}
			}
		}
		return costs;
	}

}

class Main extends no_smoking_ando {} // for DOMJudge
class no_smoking_ando {

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
		int nr = (int)leesInt();
		int nc = (int)leesInt();

		Coord e = new Coord((int)leesInt(),(int)leesInt());
		Coord k = new Coord((int)leesInt(),(int)leesInt());

		int[][] rightpassage = new int[nr][nc-1];
		for(int i=0;i<nr;++i) {
			for(int j=0;j<nc-1;++j) {
				rightpassage[i][j] = (int)leesInt();
			}
		}
		int[][] downpassage = new int[nr-1][nc];
		for(int i=0;i<nr-1;++i) {
			for(int j=0;j<nc;++j) {
				downpassage[i][j] = (int)leesInt();
			}
		}
		// DONE READING INPUT


		Layout m = new Layout(nr,nc,e,k,rightpassage,downpassage);

		m.markCells();

		System.out.println(m.computeCosts());

	}
}
