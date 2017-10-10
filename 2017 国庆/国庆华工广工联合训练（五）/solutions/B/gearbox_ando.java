import java.io.*;
import java.lang.*;
import java.util.*;

// rod indices assumed to start at 0 and up, gear indices assumed to start at 0 and up

// dit is een uitwerking van de nieuwe specificatie van de opdracht, dus met types
// ipv aantallen tanden.

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
	public boolean definedspeed;
	public Speed speed;

	public Rod() {
		ischecked = false;
		definedspeed = false;
		speed = new Speed();
	}
}

class Speed {
	public int[] speed = new int[100];
	public boolean forward;

	public Speed() {
		forward = true;
		// dit is geloof ik niet nodig in java:
		//for (int i=0;i<100;++i) speed[i]=0;
	}

	public Speed(Speed s) {
		forward = s.forward;
		for (int i=0;i<100;++i) speed[i]=s.speed[i];
	}
}



class Main extends gearbox_ando {} // for DOMJudge
class gearbox_ando {


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
				rods[ri].definedspeed = true;
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

						Speed otherrodspeed = new Speed(rods[ri].speed);
						otherrodspeed.forward = !(otherrodspeed.forward);
						otherrodspeed.speed[gears[othergear].teeth]++;
						otherrodspeed.speed[gears[mygear].teeth]--;

						if (hasDefinedSpeed(rods[gears[othergear].rod])) {
							// if speed exists, check if it matches
							if (!areAboutEqual(rods[gears[othergear].rod].speed,otherrodspeed)) {
								return true;
							}
						} else {
							// if speed undefined, set it
							rods[gears[othergear].rod].speed = otherrodspeed;
							rods[gears[othergear].rod].definedspeed = true;
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

	private static boolean areAboutEqual(Speed a, Speed b) {
		if (a.forward != b.forward) return false;
		for (int i=0;i<100;i++) {
			if (a.speed[i] != b.speed[i]) return false;
		}
		return true;
	}

	private static boolean hasDefinedSpeed(Rod r) {
		return r.definedspeed;
	}

}
