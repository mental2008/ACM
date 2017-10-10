import java.io.*;
import java.lang.*;
import java.util.*;

class Coord implements Comparable<Coord> {
	int r;
	int c;

	public Coord(int r, int c) {
		this.r = r;
		this.c = c;
	}

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

	public int compareTo(Coord other) {
		return (r - other.r) + (c - other.c);
	}
}

class Net {
	int er;
	int ec;
	int kr;
	int kc;
	int nr;
	int nc;
	int[][][] cap;
	int[][][] flow;
	int[][] marked;
	int[][] minr;
	LinkedList<Coord> p;

	public Net(int er,int ec,int kr,int kc,int nr,int nc,int[][][] cap,int[][][] flow) {
		this.er = er;
		this.ec = ec;
		this.kr = kr;
		this.kc = kc;
		this.nr = nr;
		this.nc = nc;
		this.cap = cap;
		this.flow = flow;
	}

	long calcMaxFlow() {
		long r = 0;
		long x = findAugPath();
		while (x > 0) {
			r+= x;
			adjustFlows();
			x = findAugPath();
		}
		return r;
	}

	void adjustFlows() {
		int minflow = minr[kr][kc];
		// set f(u,v) to f(u,v) + minflow
		Coord c = new Coord(kr,kc);
		while(marked[c.r][c.c] != -2) {
			Coord d = neighbor(c,marked[c.r][c.c]);
			// d cannot be null
			// from d to c
			addToFlow(d,c,minflow);
			c = d;
		}
	}

	int min(int a, int b) {
		// check if a or b is -1
		if (b == -1) return a;
		if (a == -1) return b;
		return ((b < a)?b:a);
	}

	long findAugPath() {
		// start at e
		marked = new int[nr][nc];
		minr = new int[nr][nc];
		for(int i=0;i<nr;++i) {
			for(int j=0;j<nc;++j) {
				marked[i][j] = -1;
				minr[i][j] = -1;
			}
		}
		marked[er][ec] = -2;
		p = new LinkedList<Coord>();
		p.add(new Coord(er, ec));
		// minr = minimum res flow from path
		while ((minr[kr][kc]==-1) && (!p.isEmpty())) {
			Coord c = p.poll();
			addNode(c);
		}
		return ((minr[kr][kc] == -1)?0:minr[kr][kc]);
	}

	void addNode(Coord c) {
		for (int i=0;i<4;++i) { // 0 = up, 1 = left, 2 = right, 3 = down
			Coord d = neighbor(c,i);
			if (d != null) {
				int rc = cf(c,d);
				if ((rc > 0) && (marked[d.r][d.c] == -1)) {
					marked[d.r][d.c] = 3-i;
					minr[d.r][d.c] = min(rc,minr[c.r][c.c]);
					if((d.r == kr) && (d.c == kc)) {
						return;
					}
					p.add(d);
				}
			}
		}
	}

	int cf(Coord a, Coord b) {
		Coord f;
		Coord t;
		int sign;
		if (a.compareTo(b) < 0) {
			f = a;
			t = b;
			sign = 1;
		} else {
			f = b;
			t = a;
			sign = -1;
		}
		int psg;
		if (f.r < t.r) {
			psg = 1;
		} else {
			psg = 0;
		}
		return cap[f.r][f.c][psg] - (sign*flow[f.r][f.c][psg]);
	}

	void addToFlow(Coord a, Coord b, int k) {
		Coord f;
		Coord t;
		int sign;
		if (a.compareTo(b) < 0) {
			f = a;
			t = b;
			sign = 1;
		} else {
			f = b;
			t = a;
			sign = -1;
		}
		int psg;
		if (f.r < t.r) {
			psg = 1;
		} else {
			psg = 0;
		}
		flow[f.r][f.c][psg] += (sign*k);
	}

	Coord neighbor(Coord c,int i) {
		switch (i) {
			case 0: return checkValid(c.r-1,c.c);
			case 1: return checkValid(c.r,c.c-1);
			case 2: return checkValid(c.r,c.c+1);
			case 3: return checkValid(c.r+1,c.c);
		}
		return null;
	}

	Coord checkValid(int r, int c) {
		if ((r >= 0) && (r < nr) && (c >= 0) && (c < nc)) {
			return new Coord(r,c);
		}
		return null;
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

		int er = (int)leesInt();
		int ec = (int)leesInt();

		int kr = (int)leesInt();
		int kc = (int)leesInt();

		int[][][] cap = new int[nr][nc][2]; // 0 is right, 1 is down
		int[][][] flow = new int[nr][nc][2];
		for(int i=0;i<nr;++i) {
			for(int j=0;j<nc-1;++j) {
				cap[i][j][0] = (int)leesInt();
				if (cap[i][j][0] > 0) cap[i][j][0]+= 1;
			}
		}
		for(int i=0;i<nr-1;++i) {
			for(int j=0;j<nc;++j) {
				cap[i][j][1] = (int)leesInt();
				if (cap[i][j][1] > 0) cap[i][j][1]+= 1;
			}
		}

		Net n = new Net(er,ec,kr,kc,nr,nc,cap,flow);

		System.out.println(1000*n.calcMaxFlow());

	}
}
