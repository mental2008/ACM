import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		int runs = sc.nextInt();
		while (runs --> 0) new Main();
	}
	Main() {
		read();
		System.out.println(is_free() ? "ok" : "jammed");
	}
	
	static final int FORWARD  = 0;
	static final int BACKWARD = 1;
	
	private class Gear {
		int teeth;
		Rod rod;
		
		Gear(Scanner sc) {
			teeth = sc.nextInt();
			rod   = rods[sc.nextInt()];
		}
	}
	private class Meshing {
		Gear from,to;
		
		Meshing(Gear from, Gear to) {
			this.from = from;
			this.to = to;
		}
		int[] speedAtTo() {
			int [] speed = new int[100];
			speed[0] = from.rod.speed[0] == FORWARD ? BACKWARD : FORWARD;
			for (int j = 1 ; j < 99 ; ++j) {
				speed[j] = from.rod.speed[j];
			}
			speed[from.teeth]--;
			speed[to.teeth]++;
			return speed;
		}
	}
	private class Rod {
		int[] speed;
		ArrayList<Meshing> edges = new ArrayList<Meshing>();
		
		boolean hasSpeed() {
			return speed != null;
		}
		void setSpeed1() {
			speed = new int[100];
			speed[0] = FORWARD;
			for (int j = 1 ; j < 99 ; ++j) {
				speed[j] = 0;
			}
		}
		void setSpeedFrom(Meshing m) {
			assert(m.to.rod == this);
			speed = m.speedAtTo();
		}
		boolean checkSpeedFrom(Meshing m) {
			int [] newSpeed = m.speedAtTo();
			// check
			for (int i = 0 ; i < 99 ; ++i) {
				if (speed[i] != newSpeed[i]) return false;
			}
			return true;
		}
	}
	
	int n_g, n_r, n_i;
	Gear[] gears;
	Rod[] rods;
	
	void read() {
		n_g = sc.nextInt();
		n_r = sc.nextInt();
		n_i = sc.nextInt();
		rods  = new Rod[n_r];
		gears = new Gear[n_g];
		for (int i = 0 ; i < n_r ; ++i) {
			rods[i] = new Rod();
		}
		for (int i = 0 ; i < n_g ; ++i) {
			gears[i] = new Gear(sc);
		}
		for (int i = 0 ; i < n_i ; ++i) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			gears[a].rod.edges.add(new Meshing(gears[a],gears[b]));
			gears[b].rod.edges.add(new Meshing(gears[b],gears[a]));
		}
	}
	
	boolean is_free() {
		Queue<Meshing> todo = new LinkedList<Meshing>();
		for (int i = 0 ; i < rods.length ; ++i) {
			if (!rods[i].hasSpeed()) {
				rods[i].setSpeed1();
				todo.addAll(rods[i].edges);
				while (!todo.isEmpty()) {
					Meshing m = todo.poll();
					if (m.to.rod.hasSpeed()) {
						if (!m.to.rod.checkSpeedFrom(m)) {
							return false;
						}
					} else {
						m.to.rod.setSpeedFrom(m);
						todo.addAll(m.to.rod.edges);
					}
				}
			}
		}
		return true;
	}
}