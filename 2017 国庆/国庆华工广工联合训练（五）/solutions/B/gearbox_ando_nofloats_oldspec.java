import java.io.*;
import java.lang.*;
import java.util.*;

// doesn't use floats
// rod indices assumed to start at 0 and up, gear indices assumed to start at 0 and up
// negative speed = turn the other way around

class Gear {
	public int teeth; // is now a type, not the actual number of teeth 1 <= teeth <= 99
	public int rod;

	public Gear(int teeth, int rod) {
		this.teeth = teeth;
		this.rod = rod;
	}
}

class Intermeshing {
	public int geara;
	public int gearb;

	public Intermeshing(int geara, int gearb) {
		this.geara = geara;
		this.gearb = gearb;
	}
}

class Rod {
	public boolean ischecked;
	public long speed;

	public Rod() {
		ischecked = false;
		speed = 0;
	}
}

public class gearbox_ando_nofloats {
	static Scanner sc = new Scanner(System.in);

	private static long leesInt() throws IOException{
		return (long)sc.nextLong();
	}

	private static String leesRegel() throws IOException {
		return (sc.next());
	}

	public static void main(String argv[]) throws IOException {
		long runCnt = leesInt();
		for (long i = 0;i < runCnt; i++){
			run();
		}
	}

	private static void run() throws IOException {
		int ng = (int)leesInt(); // number of gears
		int nr = (int)leesInt(); // number of rods
		int ni = (int)leesInt(); // number of intermeshings
		Gear[] gears = new Gear[ng];
		for (int i = 0;i < ng;i++) {
			gears[i] = new Gear((int)leesInt(),(int)leesInt());
		}
		Intermeshing[] intermeshings = new Intermeshing[ni];
		for (int i = 0;i < ni;i++) {
			intermeshings[i] = new Intermeshing((int)leesInt(),(int)leesInt());
		}
		Rod[] rods = new Rod[nr];
		for (int i = 0;i < nr;i++) {
			rods[i] = new Rod();
		}
		boolean jammed = determineIfJammed(ng,nr,ni,gears,intermeshings,rods);
		System.out.println((jammed)?"jammed":"ok");
	}

	private static boolean determineIfJammed(int ng, int nr, int ni, Gear[] gears,
	                                         Intermeshing[] intermeshings, Rod[] rods) {
		int rodschecked = 0;
		int oldrodschecked = rodschecked;
		while (rodschecked < nr) {
			if (oldrodschecked == rodschecked) {
				int ri = firstUndefinedRod(rods);
				long sspeed = 1;
				for (int mi = 0;mi < ni;mi++) {
					int othergear = 0;
					if (gears[intermeshings[mi].geara].rod == ri) {
						othergear = intermeshings[mi].gearb;
					} else if (gears[intermeshings[mi].gearb].rod == ri) {
						othergear = intermeshings[mi].geara;
					} else {
						continue;
					}
					sspeed = findLCM(sspeed,gears[othergear].teeth);
				}
				rods[ri].speed = sspeed;
			}
			oldrodschecked = rodschecked;
			for (int ri = 0;ri < nr;ri++) {
				if (!rods[ri].ischecked && hasDefinedSpeed(rods[ri])) {
					long sspeed = rods[ri].speed;
					for (int mi = 0;mi < ni;mi++) {
						int othergear = 0;
						if (gears[intermeshings[mi].geara].rod == ri) {
							othergear = intermeshings[mi].gearb;
						} else if (gears[intermeshings[mi].gearb].rod == ri) {
							othergear = intermeshings[mi].geara;
						} else {
							continue;
						}
						sspeed = findLCM(sspeed,gears[othergear].teeth);
					}
					if (sspeed > rods[ri].speed) {
						long scale = sspeed/rods[ri].speed;
						if (sspeed%rods[ri].speed != 0) {
							System.err.println("ERROR: sspeed not multiple of prev speed");
						}
						for (int rii = 0;rii < nr; rii++) {
							rods[rii].speed *= scale;
						}
					}
					for (int mi = 0;mi < ni;mi++) {
						int mygear = 0;
						int othergear = 0;
						if (gears[intermeshings[mi].geara].rod == ri) {
							othergear = intermeshings[mi].gearb;
							mygear = intermeshings[mi].geara;
						} else if (gears[intermeshings[mi].gearb].rod == ri) {
							othergear = intermeshings[mi].geara;
							mygear = intermeshings[mi].gearb;
						} else {
							continue;
						}
						// calculate other rod speed
						if (rods[ri].speed%gears[othergear].teeth != 0) {
							System.err.println("ERROR: speed not divisible by other teeth");
						}
						long otherrodspeed = -1*(rods[ri].speed/gears[othergear].teeth)*
						                     gears[mygear].teeth;

						if (hasDefinedSpeed(rods[gears[othergear].rod])) {
							// if speed exists, check if it matches
							if (!areAboutEqual(rods[gears[othergear].rod].speed,otherrodspeed)) {
								return true;
							}

						} else {
							// if speed undefined, set it
							rods[gears[othergear].rod].speed = otherrodspeed;
						}
					}
					rods[ri].ischecked = true;
					rodschecked++;
				}
			}
		}
		return false;
	}

	private static int firstUndefinedRod(Rod[] rods) {
		// rod.ischecked implies rod.speed != 0
		for (int i = 0;i < rods.length;i++) {
			if (!hasDefinedSpeed(rods[i])) {
				return i;
			}
		}
		// should never reach this
		System.err.println("ERROR firstUndefinedRod: all rods are defined");
		return 0;
	}

	private static boolean areAboutEqual(long a, long b) {
		return (Math.abs(a-b) == 0);
	}

	private static boolean hasDefinedSpeed(Rod r) {
		return !areAboutEqual(r.speed,0);
	}

	private static long findLCM(long x, long y) {
		long[] z = {Math.abs(x), Math.abs(y)};
		return findLCM(z);
	}

	private static long findLCM(long[] x) {
		long[] y = new long[x.length];
		for (int i = 0;i < x.length;i++) {
			y[i] = x[i];
		}
		while (!allEqual(y)) {
			int r = indexOfSmallest(y);
			y[r] += x[r];
		}
		return y[0];
	}

	private static boolean allEqual(long[] x) {
		for (int i = 1;i < x.length;i++) {
			if (x[i] != x[0]) {
				return false;
			}
		}
		return true;
	}

	private static int indexOfSmallest(long[] x) {
		int si = 0;
		long sv = x[si];
		for (int i = 1;i < x.length;i++) {
			if (x[i] < sv) {
				sv = x[i];
				si = i;
			}
		}
		return si;
	}

}
