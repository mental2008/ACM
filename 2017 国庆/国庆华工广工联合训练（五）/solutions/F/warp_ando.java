import java.io.*;
import java.lang.*;
import java.util.*;


// 4 uur voor lezen+maken
// want ik werk traag en het programma is nodeloos ingewikkeld

// deze oplossing is vrij naief
// kan een orde of meer efficienter worden gemaakt door
// maar 1 keer een matrix op te stellen van alle jaren
// en dan kijken wat het kleinste jaar is dat je nodig hebt

class Trajectory implements Comparable<Trajectory> {
	public Tensor t;
	public int year;

	public Trajectory(Tensor t,int year) {
		this.t = t;
		this.year = year;
	}

	public Trajectory(Trajectory tj) {
		this.t = new Tensor(tj.t);
		this.year = tj.year;
	}

	public int compareTo(Trajectory other) {
		// not overflow safe, not needed
		return year-other.year;
	}

	public String toString() {
		return t.toString()+" "+year;
	}
}

class Tensor {
	public static final int DIM = 11;
	public int[] coord = new int[DIM];

	public Tensor() {
		// zero tensor
	}
	public Tensor(int[] a) {
		for(int i=0;i<DIM;++i) {
			coord[i]=a[i];
		}
	}

	public Tensor(Tensor t) {
		for(int i=0;i<DIM;++i) {
			coord[i]=t.coord[i];
		}
	}

	public Tensor(Tensor from, Tensor to) {
		for(int i=0;i<DIM;++i) {
			coord[i]=(to.coord[i]+DIM-from.coord[i])%DIM;
		}
	}

	public boolean isZero() {
		for(int i=0;i<DIM;++i) {
			if(coord[i]!=0) return false;
		}
		return true;
	}

	public void addMultiple(int times, Tensor t) {
		if(times==0) return;
		for(int i=0;i<DIM;++i) {
			coord[i]=(coord[i]+(times*t.coord[i]))%DIM;
		}
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if ((o == null) || (o.getClass() != this.getClass())) return false;
		Tensor other = (Tensor)o;
		for(int i=0;i<DIM;++i) {
			if(coord[i] != other.coord[i]) return false;
		}
		return true;
	}

	public int hashCode() {
		int hash = 7;
		for (int i=0;i<DIM;++i) {
			hash = 31 * hash + coord[i];
		}
		return hash;
	}

	public String toString() {
		String s = ""+coord[0];
		for(int i=1;i<DIM;++i) {
			s+=" "+coord[i];
		}
		return s;
	}
}

class Matrix {
	public Trajectory[] m;
	public int rows;

	public Matrix(ArrayList<Trajectory> ts, int atmost) {
		rows = atmost+1;
		m = new Trajectory[rows];
		for(int i=0;i<rows;++i) {
			m[i] = new Trajectory(ts.get(i));
		}
	}

	public int firstNonZeroRow(int column, int minrow) {
		// searches minrow and up
		// returns -1 if all empty
		for(int i=minrow;i<rows;++i) {
			if (m[i].t.coord[column] != 0) return i;
		}
		return -1;
	}

	public void swapRows(int ra, int rb) {
		Trajectory tj = m[ra];
		m[ra] = m[rb];
		m[rb] = tj;
	}

	public int get(int row, int column) {
		return m[row].t.coord[column];
	}

	public Tensor getRow(int row) {
		return m[row].t;
	}

	public String toString() {
		String s = "";
		for(int i=0;i<rows;++i) {
			s+=m[i].toString()+"\n";
		}
		return s;
	}
}


class Main extends warp_ando {} // for DOMJudge
class warp_ando {

	static Scanner sc = new Scanner(System.in);

	static int[][] shift = new int[Tensor.DIM][Tensor.DIM];

	private static long leesInt() throws IOException{
		return sc.nextLong();
	}

	private static String leesRegel() throws IOException {
		return sc.next(); // reads a word, not a line
	}

	public static void main(String argv[]) throws IOException {

		// build distances lookup table
		for(int i=0;i<Tensor.DIM;++i) {
			for(int j=0;j<Tensor.DIM;++j) {
				shift[i][(i*j)%Tensor.DIM] = j;
			}
		}

		long runCnt = leesInt();
		for(long i = 0;i < runCnt; i++) {
			run();
		}
	}

	private static void run() throws IOException {
		int n = (int)leesInt(); // number of warp trajectories

		Tensor start = readTensor();
		Tensor end = readTensor();

		ArrayList<Trajectory> ts = new ArrayList<Trajectory>();

		for(int i=0;i<n;++i) {
			ts.add(readTrajectory());
		}
		// done reading input

		// calculate displacement vector
		Tensor move = new Tensor(start,end);

		if (move.isZero()) { // is this the correct interpretation of the assignment?
			System.out.println("0");
			return;
		}

		Collections.sort(ts); // ts is now sorted trajectories by year

		for(int i=0;i<n;++i) {
			if (reachable(move,ts,i)) {
				System.out.println(ts.get(i).year);
				return;
			}
		}

		System.out.println("unreachable");
	}

	private static Tensor readTensor() throws IOException {
		int[] cs = new int[Tensor.DIM];
		for(int i=0;i<Tensor.DIM;++i) {
			cs[i] = (int)leesInt();
		}
		return new Tensor(cs);
	}

	private static Trajectory readTrajectory() throws IOException {
		Tensor t = readTensor();
		int year = (int)leesInt();
		return new Trajectory(t,year);
	}

	private static int howManyMultiples(int of, int from, int to) {
		return shift[of][(to+Tensor.DIM-from)%Tensor.DIM];
	}

	private static boolean reachable(Tensor move, ArrayList<Trajectory> ts, int atmost) {
		// returns if reachable using trajectories with index [0..atmost] from ts array
		Matrix m = new Matrix(ts,atmost);

		// tensor voor unieke combinatie van geveegde matrix
		Tensor comp = new Tensor();

		// matrix vegen en vinden van oplossing tegelijk
		int row = 0;
		for(int column=0;((column<Tensor.DIM) && (row<m.rows));++column) {

			// row only increases if we found something nonzero
			int rw = m.firstNonZeroRow(column,row);

			if (rw == -1) continue;

			if (rw != row) {
				// current row is zero, but there is a nonzero row: swap
				m.swapRows(row,rw);
			}

			int fac = m.get(row,column);
			// now make all lower rows zero using steps of fac
			for(int ri=row+1;ri<m.rows;++ri) {
				// how many multiples of fac from value to zero
				int times = howManyMultiples(fac,m.get(ri,column),0);
				m.getRow(ri).addMultiple(times,m.getRow(row));
			}

			int times = howManyMultiples(fac,comp.coord[column],move.coord[column]);
			comp.addMultiple(times,m.getRow(row));

			row++;

		}

		return comp.equals(move);
	}
}
