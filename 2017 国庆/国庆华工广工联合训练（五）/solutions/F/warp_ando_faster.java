import java.io.*;
import java.lang.*;
import java.util.*;


// 4.5 uur voor lezen+maken+efficienter maken
// want ik werk traag en het programma is nodeloos ingewikkeld

// deze oplossing is ongeveer een orde sneller dan mijn eerste uitwerking.

// op de testdata:
// warp_ando.java:         real    0m3.344s
// warp_ando_faster.java:  real    0m1.109s


class Trajectory implements Comparable<Trajectory> {
	public Tensor t;
	public int year;

	public Trajectory(Tensor t, int year) {
		this.t = t;
		this.year = year;
	}

	public Trajectory(Trajectory tj) {
		this.t = new Tensor(tj.t);
		this.year = tj.year;
	}

	public int compareTo(Trajectory other) {
		return year-other.year;
	}
}

class Tensor {
	public static final int DIM = 11;
	public int[] coord=new int[DIM];

	public Tensor() {
	}

	public Tensor(int[] a) {
		for(int i=0;i<DIM;++i) coord[i]=a[i];
	}

	public Tensor(Tensor t) {
		for(int i=0;i<DIM;++i) coord[i]=t.coord[i];
	}

	public Tensor(Tensor from, Tensor to) {
		for(int i=0;i<DIM;++i) coord[i]=(to.coord[i]+DIM-from.coord[i])%DIM;
	}

	public void addMultiple(int times, Tensor t) {
		for(int i=0;i<DIM;++i) coord[i]=(coord[i]+(times*t.coord[i]))%DIM;
	}

	public boolean equals(Object o) {
		if(this == o) return true;
		if((o==null) || (o.getClass()!=this.getClass())) return false;
		Tensor other=(Tensor)o;
		for(int i=0;i<DIM;++i) if(coord[i]!=other.coord[i]) return false;
		return true;
	}

	public int hashCode() {
		int hash=7;
		for(int i=0;i<DIM;++i) hash=31*hash+coord[i];
		return hash;
	}
}

class Matrix {
	public Trajectory[] m;
	public int rows;

	public Matrix(ArrayList<Trajectory> ts) {
		rows=ts.size();
		m=new Trajectory[rows];
		for(int i=0;i<rows;++i) m[i]=new Trajectory(ts.get(i));
	}

	public int firstNonZeroRow(int column, int minrow) {
		for(int i=minrow;i<rows;++i) if(m[i].t.coord[column]!=0) return i;
		return -1;
	}

	public void swapRows(int ra, int rb) {
		Trajectory tj=m[ra];
		m[ra]=m[rb];
		m[rb]=tj;
	}

	public int get(int row, int column) {
		return m[row].t.coord[column];
	}

	public Tensor getRow(int row) {
		return m[row].t;
	}

	public int getRowYear(int row) {
		return m[row].year;
	}
}


class Main extends warp_ando_faster {} // for DOMJudge
class warp_ando_faster {
	static Scanner sc=new Scanner(System.in);
	static int[][] shift=new int[Tensor.DIM][Tensor.DIM];

	private static long leesInt() throws IOException {
		return sc.nextLong();
	}

	public static void main(String argv[]) throws IOException {
		for(int i=0;i<Tensor.DIM;++i) for(int j=0;j<Tensor.DIM;++j) {
			shift[i][(i*j)%Tensor.DIM]=j;
		}
		long runCnt=leesInt();
		for(long i=0;i<runCnt;++i) run();
	}

	private static void run() throws IOException {
		int n=(int)leesInt();
		Tensor start = readTensor();
		Tensor end = readTensor();
		ArrayList<Trajectory> ts = new ArrayList<Trajectory>();
		for(int i=0;i<n;++i) ts.add(new Trajectory(readTensor(),(int)leesInt()));
		Collections.sort(ts);
		int r = reachable(new Tensor(start,end),ts);
		System.out.println(((r == -1)?"unreachable":r));
	}

	private static Tensor readTensor() throws IOException {
		int[] cs=new int[Tensor.DIM];
		for(int i=0;i<Tensor.DIM;++i) cs[i]=(int)leesInt();
		return new Tensor(cs);
	}

	private static int reachable(Tensor move, ArrayList<Trajectory> ts) {
		Matrix m = new Matrix(ts);
		Tensor comp = new Tensor();
		if(move.equals(comp)) return 0;
		int row = 0;
		for(int column=0;((column<Tensor.DIM) && (row<m.rows));++column) {
			int rw=m.firstNonZeroRow(column,row);
			if(rw == -1) continue;
			if(rw != row) m.swapRows(row,rw);
			int fac=m.get(row,column);
			for(int ri=row+1;ri<m.rows;++ri) {
				int times = howManyMultiples(fac,m.get(ri,column),0);
				if(times != 0) m.getRow(ri).addMultiple(times,m.getRow(row));
			}
			++row;
		}
		row = 0;
		int maxyear=0;
		for(int column=0;((column<Tensor.DIM) && (row<m.rows));++column) {
			if(m.get(row,column) == 0) continue;
			int times=howManyMultiples(m.get(row,column),comp.coord[column],move.coord[column]);
			if(times != 0) {
				comp.addMultiple(times,m.getRow(row));
				maxyear=max(maxyear,m.getRowYear(row));
				if(comp.equals(move)) return maxyear;
			}
			++row;
		}
		return -1;
	}

	private static int howManyMultiples(int of, int from, int to) {
		return shift[of][(to+Tensor.DIM-from)%Tensor.DIM];
	}

	private static int max(int a, int b) {
		return ((b > a)?b:a);
	}
}
