import java.io.*;
import java.lang.*;
import java.util.*;

// rod indices assumed to start at 0 and up, gear indices assumed to start at 0 and up
// negative speed = turn the other way around
// uses FLOATS (doubles), should be able to do without

class Gear {
	public int teeth;
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
	public double speed;

	public Rod() {
		ischecked = false;
		speed = 0.0;
	}
}

class Main extends gearbox_ando {} // for DOMJudge
class gearbox_ando {
	public static final double ERR = 0.001;
	public static final double START_SPEED = 1.0;

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
				rods[firstUndefinedRod(rods)].speed = START_SPEED;
			}
			oldrodschecked = rodschecked;
			for (int ri = 0;ri < nr;ri++) {
				if (!rods[ri].ischecked && hasDefinedSpeed(rods[ri])) {
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
						double otherrodspeed = -1.0*rods[ri].speed*
						                       gears[mygear].teeth/
						                       gears[othergear].teeth;

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

	private static boolean areAboutEqual(double a, double b) {
		return (Math.abs(a-b) < ERR);
	}

	private static boolean hasDefinedSpeed(Rod r) {
		return !areAboutEqual(r.speed,0.0);
	}

}
