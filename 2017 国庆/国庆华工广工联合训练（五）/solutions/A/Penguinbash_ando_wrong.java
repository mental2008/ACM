import java.io.*;
import java.lang.*;
import java.util.*;

class Obstacle {
	public double pos;
	public String type;

	public Obstacle(double pos, String type) {
		this.pos = pos;
		this.type = type;
	}

	public String toString() {
		return pos + " " + type;
	}
}


class Main extends Penguinbash_ando {} // for DOMJudge
class Penguinbash_ando {

	static BufferedReader br = new BufferedReader(
							 new InputStreamReader(System.in));
	static StreamTokenizer tok = new StreamTokenizer(br);
	
	static boolean debug = false;

	private static long leesInt() throws IOException{
		tok.nextToken();
		return (long) tok.nval;
	}

	private static double leesDouble() throws IOException{
		tok.nextToken();
		return (double) tok.nval;
	}

	private static String leesRegel() throws IOException {
		return (br.readLine());
	}

	public static void main(String argv[]) throws IOException {
		long runCnt = leesInt();
		for (long i = 0;i < runCnt; i++) {
			run();
		}
	}

	private static void run() throws IOException {
		int n = (int)leesInt(); // number of obstacles
		Obstacle[] obs = new Obstacle[n];
		//System.out.println(n + " obstacles");
		for (int i = 0; i < n; i++) {
			obs[i] = new Obstacle(leesDouble(),leesRegel());
			//System.out.println("obstacle: " + obs[i]);
		}
		System.out.println(calcHighestScore(obs,n));
	}

	private static int calcHighestScore(Obstacle[] obs, int n) {
		int maxa = -90;
		double maxscore = 0.0;
		for (int a = -90; a < 91; a++) {
			double score = calcScore(obs,n,a);
			if (debug) {
				System.out.println("a: "+a+", score: "+score);
			}
			if ((a == -90) || (score > maxscore)) {
				maxscore = score;
				maxa = a;
			}
		}
		return maxa;
	}

	private static double calcScore(Obstacle[] obs, int n, int a) {
		int totalstartvelocity = 25;
		double g = 9.81;
		double ih = 1.0;
		double angle = a*Math.PI/180.0;
		double ypos = 3.0;
		double xpos = 0.0;
		double yspeed = totalstartvelocity*Math.sin(angle);
		double xspeed = totalstartvelocity*Math.cos(angle);

		// calc until ground is hit
		double t = (yspeed + Math.sqrt(yspeed*yspeed+2*g*ih))/g;
		//System.out.println("t: "+t);
		xpos += xspeed*t;
		int oi = findNextObstacle(obs,n,xpos);
		while (oi != -1) {
			if (obs[oi].pos < xpos) { continue; }
			double disttoobject = obs[oi].pos - xpos;
			if (xspeed-disttoobject*5 < 0) {
				xpos += xspeed/5;
				return xpos;
			}
			// we can reach object
			if (debug) {
				System.out.println(" hit "+obs[oi].type+" from x="+xpos+"  v="+xspeed);
			}
			if (obs[oi].type.equals("spike")) {
				xpos = -100.0;
				return xpos;
			}
			// we reached a mine
			// first calc xspeed at mine
			xspeed -= disttoobject*5;
			yspeed = 10.0;
			if (debug) {
				System.out.println(" slide to  x="+xpos+"  v="+xspeed);
			}
			// calc until ground is hit
			t = (2*yspeed)/g;
			xpos += xspeed*t;
			if (debug) {
				System.out.println(" new pos  x="+xpos+"  v="+xspeed);
			}
			oi = findNextObstacle(obs,n,xpos);
		}
		//System.out.println(" at "+a+"  x="+xpos+"  v="+xspeed);
		xpos += xspeed/5;
		return xpos;
	}

	private static int findNextObstacle(Obstacle [] obs, int n, double xpos) {
		double minpos = 0.0;
		int minposi = -1;
		for (int i = 0;i < n; i++) {
			if (obs[i].pos < xpos) { continue; }
			if ((minposi == -1) || (obs[i].pos < minpos)) {
				minpos = obs[i].pos;
				minposi = i;
			}
		}
		return minposi;
	}

}
