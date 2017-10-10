import java.io.*;
import java.lang.*;
import java.util.*;


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

	public static long determinant2(long a, long b, long c, long d) {
		return (a*d) - (c*b);
	}
}

class Vertex {
	public static Vertex last = null;
	public static long ids = 0;
	long id;
	Coord coords = null;
	Edge iedge = null; // incidentEdge, arbitrary halfedge with v as origin
	int type;

	public Vertex(Coord coords, int type, Edge iedge) {
		this.coords = coords;
		this.type = type;
		this.iedge = iedge;
		last = this;
		this.id = ids++;
	}

	public Vertex(Coord coords, Edge iedge) {
		this(coords,1,iedge);
	}

	public Vertex(Coord coords) {
		// used in split triangle
		this(coords,null);
	}

	public void setIncidentEdge(Edge e) {
		if (e.origin != this) {
			throw new RuntimeException("edge does not have this vertex as origin");
		}
		iedge = e;
	}

	public String toString() {
		return "vertex "+id+": coords:"+coords.toString()+", type:"+type+", iedgeid: "+iedge.id;
	}

}

class Edge implements Comparable<Edge> {
	public static final int BLAST_RADIUS = 2;
	public static long ids = 0;
	public static long flipped = 0;
	public static long edgeinsertions = 0;
	int markked = 0;
	long legal = 0;
	long id;
	int seen = 0;
	Face iface = null; // incidentFace, face that it bounds (left)
	Edge prev = null;  // previous and next edges on boundary of iface
	Edge next = null;
	Edge twin = null;  // if twin is null then outer boundary
	Vertex origin = null;
	Vertex destination = null;  // destination == twin.origin, if there is a twin
								// storing destination specifically, since some edges
								// dont have twins.
	//int legal = 0;
	//int flipped = 0;
/*
	public Edge(Coord orig, int type) {
		// first border vertex
		this.origin = new Vertex(orig,type,this);
		this.iface = new Face(this);
	}

	public Edge(Coord orig, int type, Edge prev) {
		// second and third border vertex
		this.iface = prev.iface;
		this.prev = prev;
		prev.next = this;
		this.origin = new Vertex(orig,type,this);
		prev.destination = this.origin;
	}
*/
	public Edge(Vertex origin, Vertex destination) {
		// used in split triangle
		if (origin == destination) throw new RuntimeException("destination is not origin");
		this.origin = origin;
		this.destination = destination;
		this.id = ids++;
	}

	public void setNext(Edge e) {
		// overrides face of edge
		// checks for endings
		if (destination != e.origin) throw new RuntimeException("destination is not origin");
		next = e;
		next.prev = this;
		next.iface = iface;
	}

	public void setPrev(Edge e) {
		if (origin != e.destination) throw new RuntimeException("origin is not destination");
		prev = e;
		prev.next = this;
		prev.iface = iface;
	}

	public Edge getTwin() {
		if (twin == null) throw new RuntimeException("twin is null");
		//return this;
		return twin;
	}

	public void setTwin(Edge e) {

		if ((origin != e.destination) || (destination != e.origin)) {
			throw new RuntimeException("twins not mirrors");
		}
		if ((origin.type < 0) && (destination.type < 0)) {
			throw new RuntimeException("no twin can be set of bla");
		}
		if ((e.origin.type < 0) && (e.destination.type < 0)) {
			throw new RuntimeException("no twin can be set of blaf");
		}
		if (iface == e.iface) throw new RuntimeException("twins on same face");

		if((next != null) && (next.destination == e.next.destination)) {
			throw new RuntimeException("one of them has field on right");
		}

		twin = e;
		e.twin = this;

	}

/*
	public Vertex fourthVertex() {
		Vertex pi = origin;
		Vertex pj = destination;
		Vertex pk = Vertex.last;
		Vertex pl = getTwin().next.destination;
		if ((pl != pi) && (pl != pk) && (pl != pj)) {
			System.out.println("sucess! getTwin().next.destination;");
		} else {
			pl = getTwin().prev.destination;
			if ((pl != pi) && (pl != pk) && (pl != pj)) {
				System.out.println("sucess! getTwin().prev.destination");
			} else {
				pl = getTwin().prev.origin;
				if ((pl != pi) && (pl != pk) && (pl != pj)) {
					System.out.println("sucess! getTwin().prev.origin");
				} else {
					pl = getTwin().next.origin;
					if ((pl != pi) && (pl != pk) && (pl != pj)) {
						System.out.println("sucess! getTwin().next.origin");
					} else {
						return null;
					}
				}
			}
		}
		return pl;
	}
*/
	public boolean isIllegal() {
		//System.out.println("issilegal: "+this.toString());
		Vertex pi = origin;
		Vertex pj = destination;

		if ((pi.type < 0) && (pj.type < 0)) {
			// in this case we decide that pipj is legal, becaues we must
			// keep the edges of the large triangle p-1p-2p-3
			return false;
		}

		// also if it lies on some internal border
		//if (
		/*
		if (isOuter()) {
			return false;
		}
		*/
		// For the other cases, let pk and pl be the two other vertices of
		// the triangles incident to pipj
		Vertex pk = next.destination;
		//if (pk != Vertex.last) throw new RuntimeException("not last");
		//System.out.println("this.iface: "+this.iface+", twin iface: "+getTwin().iface);
		//System.out.println(this);
		if (!exists()) throw new RuntimeException("we don't exist");
		/*
		Edge bla = getTwin().iface.outer;
		if(bla.iface != getTwin().iface) throw new RuntimeException("blanottwin");
		if(iface == bla.iface) throw new RuntimeException("blaisthisface");
		while((bla.origin == pi) || (bla.origin == pj) || (bla.origin == pk)) {
			bla = bla.next;
			if(bla.iface != getTwin().iface) throw new RuntimeException("blanottwin");
			if(iface == bla.iface) throw new RuntimeException("blaisthisface");
		}
		*/

		//Vertex pl = fourthVertex();
		Vertex pl = getTwin().next.destination;
		if ((pl == pi) || (pl == pj) || (pl == pk)) { markked = 1; return false; }
		//if (pl == pk) {
			//System.out.println("we found no pl, not flipping");
		//	return false;
		//}
		/*
		if(pk == pl) {
			pl = getTwin().prev.destination;
			System.out.println("trying to fix it...");
		}
		*/
		//if(pk == pl) throw new RuntimeException("pk is pl");
		//System.out.println("worked!");
		Vertex[] vs = {pi,pj,pk,pl};
		int numbernegs = numberNegs(vs);
		switch(numbernegs) {
			case 0: {
				// pipj is illegal if and only if pl lies inside the circle defined
				// by pi, pj and pk.

				// points in counterclockwise order
				// > 0 means inside, not on.
				//if ((pl == pi) || (pl == pj) || (pl == pk)) { return false; }
				return (pl.coords.liesInCircumCircle(pi.coords,pj.coords,pk.coords) > 0);
			}
			case 1: {
				// if i or j is negative then pipj is illegal so that it will be
				// replaced by pkpl. otherwise pipj is legal
				return ((pi.type < 0) || (pj.type < 0));
			}
			case 2: {
				// one of i,j and one of k,l must be negative.
				// if negative index of i,j is smaller than the negative index of
				// k,l, then pipj is legal otherwise it is illegal
				return (Dag.min(pi.type,pj.type) > Dag.min(pk.type,pl.type));
			}
			// other cases cannot occur
		}
		throw new RuntimeException("should not get here");
		//return false;
	}

	private int numberNegs(Vertex[] vs) {
		int n = 0;
		for(int i=0;i<vs.length;++i) {
			if (vs[i].type < 0) ++n;
		}
		return n;
	}

	public static long sqr(long a) {
		return a*a;
	}

	public void flip() {
		// Replace pipj with prpk

		//System.out.println("flip: "+this);
		flipped++;

		Vertex pi = origin;
		Vertex pj = destination;
		Vertex pr = next.destination;

		if (!exists()) {
			throw new RuntimeException("we dont exist");
		}
		if (pr != Vertex.last) {
			throw new RuntimeException("pr is not last");
		}
		Vertex pk = getTwin().next.destination;
		//Vertex pk = fourthVertex();
		if (pk == pr) {
			System.out.println("shoulddddnt be");
			System.out.println("origin: "+pi);
			System.out.println("destination: "+pj);
			System.out.println("next.destination: "+pr);
			System.out.println("twin.next.destination: "+pk);
			System.out.println("this: "+this);
			System.out.println("twin: "+getTwin());
			System.out.println("next: "+next);
			System.out.println("twin.next: "+getTwin().next);
			throw new RuntimeException("pk is pr in flip");
		}

		Edge pipj = this;
		Edge pjpi = getTwin();

		Edge pjpr = next;
		Edge prpi = prev;
		Edge pipk = getTwin().next;
		Edge pkpj = getTwin().prev;

	if ((pjpr.destination != prpi.origin) ||
		(prpi.destination != pipk.origin) ||
		(pkpj.destination != pjpr.origin)) throw new RuntimeException("ho maar") ;


//		Edge pipk = getTwin().prev;
//		Edge pkpj = getTwin().next;

		/*
		System.out.println("pjpr: "+pjpr);
		System.out.println("prpi: "+prpi);
		System.out.println("pipk: "+pipk);
		System.out.println("pkpj: "+pkpj);
		if (pipk.twin != null) {
			System.out.println("nonzero twin analysis pre");
			System.out.println("pipk.getTwin().next.destination: "+pipk.getTwin().next.destination);
			System.out.println("pr: "+pr);
		}
		*/

		Dag pipjdag = pipj.iface.d;
		Dag pjpidag = pjpi.iface.d;
		/*
		System.out.println("pipj.iface.d: "+pipjdag);
		System.out.println("pjpi.iface.d: "+pjpidag);
		*/

		// end declarations

		Edge prpk = new Edge(pr,pk);
		prpk.iface = new Face(prpk);
		Edge pkpr = new Edge(pk,pr);
		pkpr.iface = new Face(pkpr);
		prpk.setTwin(pkpr);

		prpk.setNext(pkpj);
		prpk.setPrev(pjpr);
		//pkpj.setNext(pjpr);
		prpk.next.setNext(prpk.prev);

		pkpr.setNext(prpi);
		pkpr.setPrev(pipk); // workonthis
		//prpi.setNext(pipk);
		pkpr.next.setNext(pkpr.prev);

		if (pi.iedge == pipj) {
			//pi.setIncidentEdge(pipk);
		}
		if (pj.iedge == pjpi) {
			//pj.setIncidentEdge(pjpr);
		}

		// add new faces as children to both old faces.
		// create them only once
		Dag prpkdag = new Dag(prpk.iface);
		Dag pkprdag = new Dag(pkpr.iface);

		pipjdag.addChild(prpkdag); // dit gaat fout want verkeerde richting
		pipjdag.addChild(pkprdag); // of toch niet

		pjpidag.addChild(prpkdag); // dit gaat fout want hij vind ze zo dubbel
		pjpidag.addChild(pkprdag); // blijkbaar niet
/*
		System.out.println("prpk.iface: "+prpk.iface);
		System.out.println("pkpr.iface: "+pkpr.iface);

		System.out.println("prpk.next.destination: "+prpk.next.destination);
		System.out.println("pkpr.next.destination: "+pkpr.next.destination);

		if (pkpr.prev.twin != null) {
			System.out.println("nonzero twin analysis post");
			System.out.println("pkpr.prev.getTwin().next.destination: "+pkpr.prev.getTwin().next.destination);
			System.out.println("pkpr.destination: "+pkpr.destination);
		}

		System.out.println("...");
		*/
	}

	public Edge[] splitUp(Coord c) {
		edgeinsertions++;
		Vertex pr = new Vertex(c);
		          // pjpk, pkpi, pipl, plpj <-- no
		          // pipl, plpj, pjpk, pkpi
		Edge[] es = {getTwin().next,getTwin().prev,next,prev};
		//Edge[] es = {next,prev,getTwin().next,

		// pkpr will be mirroredge

		// replace possible incidentedge beforehand
		if (origin.iedge == this) {
			origin.setIncidentEdge(getTwin().next);
		}
		if (destination.iedge == getTwin()) {
			destination.setIncidentEdge(next);
		}

		Edge mirroredge = null;
		Edge firstedge = es[0];

		for(int i=0;i<4;++i) {
			Edge pjpk = es[i];
			Face oldface = pjpk.iface;
			pjpk.iface = new Face(pjpk);
			pjpk.setPrev(new Edge(pr,pjpk.origin));
			pjpk.setNext(new Edge(pjpk.destination,pr));
			pjpk.next.setNext(pjpk.prev);

			if (mirroredge == null) {
				pr.setIncidentEdge(pjpk.prev);
			} else {
				pjpk.prev.setTwin(mirroredge);
			}
			mirroredge = pjpk.next;

			oldface.d.addChild(pjpk.iface);
		}
		firstedge.prev.setTwin(mirroredge);

		return es;
	}

	public boolean exists() {
		return ((prev.next == this) && (next.prev == this));
	}

	public boolean isBorder() {
		return ((origin.type < 0) && (destination.type < 0));
	}

	public double dist() {
		return Math.sqrt(sqr(destination.coords.x-origin.coords.x) +
			             sqr(destination.coords.y-origin.coords.y)) - 2*BLAST_RADIUS;
	}

	public long disdist() {
		return (sqr(destination.coords.x-origin.coords.x) +
			    sqr(destination.coords.y-origin.coords.y));
	}

	public int compareTo(Edge other) {
		//return other.dist()-dist();
		long od = other.disdist();
		long dd = disdist();
		if(dd == od) return 0;
		if(dd < od) return 1;
		return -1;
	}

	public String toString() {
		//return "{"+origin.coords+" -> "+destination.coords+"} :: "+exists()+" (legal called: "+legal+")";
		//return "{"+origin.coords+" -> "+destination.coords+"} :: "+exists()+" (illegal: "+isIllegal()+")"+" flipped: "+flipped;
		//return "{"+origin.coords+" -> "+destination.coords+"} :: "+exists()+" flipped: "+flipped+" hash: "+outer: "+isOuter();
		//return "{"+origin.coords+" -> "+destination.coords+"} :: "+exists()+" hash: "+" outer: "+isOuter();
		return "edge "+id+": Vorigin:"+origin.id+", Vdestination:"+destination.id+
			", Fiface:"+iface.id+", Eprev:"+prev.id+", Enext:"+next.id+
			", Ilegal:"+legal+((twin != null)?", Etwin:"+twin.id:"");
	}
}

class Face {
	public static long interiorinsertions = 0;
	public static long ids = 0;
	long id;
	Dag d = null; // crosslink to dag
	Edge outer = null; // some halfedge on outer boundary. nil for unbounded face
	int seen = 0;
	// list of edge pointers to each hole (not needed)

	public Face(Edge outer) {
		this.outer = outer;
		this.id = ids++;
	}

	public void addInteriorPoint(Coord pr) {
		interiorinsertions++;
		// add edges from pr to the three vertices of pipjpk, thereby
		// splitting pipjpk into three triangles
		Vertex z = new Vertex(pr);
		Edge e = outer;
		Edge mirroredge = null;
		Edge firstedge = e;

		for(int i=0;i<3;++i) {
			Edge tempnext = e.next;
			e.iface = new Face(e);
			e.setPrev(new Edge(z,e.origin));
			e.setNext(new Edge(e.destination,z));
			e.next.setNext(e.prev);

			if (mirroredge != null) {
				e.prev.setTwin(mirroredge);
			}
			mirroredge = e.next;

			d.addChild(e.iface);
			e = tempnext;
		}

		firstedge.prev.setTwin(mirroredge);
		z.setIncidentEdge(firstedge.prev);
	}

	public String toString() {
		return "face "+id+": Eouter:"+outer.id+", Dd:"+d.id;
	}
}

class Dag {
	public static long ids = 0;
	long id;
	ArrayList<Dag> children = null;
	Vertex[] vertices = null; // vertices have to be in order that face is left
	Face face = null;
	// hash combinatie van dingen
	public Dag(Face face) {
		this.face = face;
		this.face.d = this; // set dag
		vertices = new Vertex[3];
		Edge e = face.outer;
		for(int i=0;i<3;++i) {
			vertices[i] = e.origin;
			e = e.next;
		}
		children = new ArrayList<Dag>();
		id = ids++;
	}

	public boolean hasChildren() {
		return (!children.isEmpty());
	}

	public void addChild(Face f) {
		if (f.d != null) throw new RuntimeException("face has shit going on");
		//System.out.println("addchildface::this: "+this+", face: "+face+", size: "+children.size()+", param: "+f);
		if (children.size() == 3) throw new RuntimeException("already 3 children");
		children.add(new Dag(f));
	}

	public void addChild(Dag d) {
		//System.out.println("addchilddag::this: "+this+", face: "+face+", size: "+children.size()+", param: "+d);
		if (children.size() == 3) throw new RuntimeException("already 3 childrendag");
		children.add(d);
	}

	public long containsPoint(Coord r) {
		// vertices array is in order with inside face to hte left
		// return value: 0 = if not contains, 1 = on edge, 2 = interior
		long s = 1;
		for(int i=0;i<3;++i) {
			Coord p = vertices[i].coords;
			Coord q = vertices[(i+1)%3].coords;
			long d = r.liesLeftOf(p,q);  // only one has to be one
			//System.out.println(r+" lies left of "+p+" -> "+q+"\t\t\t"+d);
			if (d < 0) return 0;
			s = min(s,d);
		}
		return (s == 0)?1:2;
	}

	public static long min(long a, long b) {
		return ((b<a)?b:a);
	}

	public static double minl(double a, double b) {
		return ((b<a)?b:a);
	}

	public String toString() {
		return "dag "+id+": Fface:"+face.id+", Fface.dag:"+face.d.id+
		", Ichildren:"+children.size()+", verts: {"+
		vertices[0].coords+","+vertices[1].coords+","+vertices[2].coords+
		"}, Ffaceouter:"+face.outer.iface.id;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if ((o == null) || (o.getClass() != this.getClass())) return false;
		Dag other = (Dag)o;
		return (hashCode() == other.hashCode());
	}
/*
	public int hashCode() {
		//int hash = 7;
		//hash = hash * (int)vertices[2].coords.liesLeftOf(vertices[0].coords,vertices[1].coords);
		return Coords.determinant2(vertices[0].coords.determinant(vertices
		hash =  31* hash * (int)vertices[0].coords.x;
		hash =  31* hash * (int)vertices[0].coords.y;
		hash =  31* hash * (int)vertices[1].coords.x;
		hash =  31* hash * (int)vertices[1].coords.y;
		hash =  31* hash * (int)vertices[2].coords.x;
		hash =  31* hash * (int)vertices[2].coords.y;

		return hash;
	}
	*/
}

class Triangulation {
	public static final long MAX_COORD = 10;
	public static long legalized = 0;

	Edge t = null; // this is the entire triangulation
	Dag d = null; // point location structure d which is a directed acyclic graph
	Edge ps[] = null;

	public Triangulation() {
		//Edge p1 = new Edge(new Coord(3*MAX_COORD,0), -1);
		//Edge p2 = new Edge(new Coord(0,3*MAX_COORD), -2, p1);
		//Edge p3 = new Edge(new Coord(-3*MAX_COORD,-3*MAX_COORD), -3, p2);

		Vertex v1 = new Vertex(new Coord(3*MAX_COORD,0));
		v1.type = -1;
		Vertex v2 = new Vertex(new Coord(0,3*MAX_COORD));
		v2.type = -2;
		Vertex v3 = new Vertex(new Coord(-3*MAX_COORD,-3*MAX_COORD));
		v3.type = -3;

		Edge p1 = new Edge(v1,v2);
		p1.iface = new Face(p1);
		v1.setIncidentEdge(p1);

		p1.setNext(new Edge(v2,v3));
		v2.setIncidentEdge(p1.next);

		p1.setPrev(new Edge(v3,v1));
		v3.setIncidentEdge(p1.prev);

		p1.next.setNext(p1.prev);


		// initialize t as the triangulation of p1 p2 p3
		t = p1;
		// initialize DAG with face
		d = new Dag(t.iface);
		Edge[] pss = {p1,p1.next,p1.prev};
		ps = pss;
	}

	public void triangulatePoints(Coord[] points) {

		for(int i=0;i<points.length;++i) {

			// find a triangle pipjpk in T containing  points[i];
			Dag c = findTriangleContaining(points[i]);
			Face f = c.face;

			// if points[i] lies in the interior of the triangle pipjpk then
			if (c.containsPoint(points[i]) == 2) {

				Edge[] ess = new Edge[3];
				Edge e = c.face.outer;

				for(int j=0;j<3;++j) {
					ess[j] = e;
					e = e.next;
				}

			//	if ((ess[2].next != ess[0]) || (ess[0].prev != ess[2])) {
			//		System.out.println("something wrong");
			//	}
/*
				for(int j=0;j<3;++j) {
					if(!ess[j].exists()) {
						System.out.println("does not exiist: "+ess[j]);
					}
				}

				*/
				// add edges from pr to the three vertices of pipjpk, thereby
				// splitting pipjpk into three triangles
				f.addInteriorPoint(points[i]);
/*
				if (ess[0].origin != ess[2].destination) {
					System.out.println("something wrong");
				}
*/
/*
				for(int j=0;j<3;++j) {
					if(!ess[j].exists()) {
						System.out.println("does not exiiist: "+ess[j]);
					}
				}

*/
				//System.out.println(ess[0]

				// this is legal because the dag never changes (only created)
				//for (Dag sub : c.children) {
				for(int j=0;j<3;++j) {
					//System.out.println("before");
					//legalizeEdge(sub.face.outer);
					/*
					if (!ess[j].exists()) {
						System.out.println(j+"does not exxxxt: "+ess[j]);
					}
					*/
					legalizeEdge(ess[j]);

					//System.out.println("after");
				}

			} else { // (* points[i] lies on an edge of pipjpk, say the edge pipj *)

				// find edge that it is on.
				Edge e = c.face.outer;
				while (points[i].liesLeftOf(e.origin.coords,e.destination.coords) != 0) {
					e = e.next;
				}
				// e is edge that point is on, e is pipj

				// add edges from points[i] to pk and to the third vertex pl
				// of the other triangle that is incident to pipj, thereby
				// splitting the two triangles incident to pipj into four
				// triangles
				//System.out.println("foursplit");
				Edge[] es = e.splitUp(points[i]);

				for(int j=0;j<4;++j) {
					legalizeEdge(es[j]);
				}
			}
		}

		// discard p1 p2 p3 with all incident edges from t
		// if we do this, dag is no longer correct. <-- actuallym, the subtree still is
		/*
		for (Coord p : d.vertices) {
			System.out.println(p);
		}
		*/
		//for (Edge e : ps) {

		//}

	}

	public long maxSoldiers() {

		// find thing where it is
		Coord bush = new Coord(0,0);
		Dag c = findTriangleContaining(bush);
		// if points[i] lies in the interior of the triangle pipjpk then
		PriorityQueue<Edge> q = new PriorityQueue<Edge>();
		double ms = 10e6;
		System.out.println("starting containspoint");
		long conp = c.containsPoint(bush);
		System.out.println("containspoiont: "+conp);
		if (conp != 2) {
			System.out.println("starting on edge");
			// start on edge so this is min length
			// find edge that it is on.
			Edge e = c.face.outer;
			while (bush.liesLeftOf(e.origin.coords,e.destination.coords) != 0) {
				e = e.next;
			}
			ms = e.dist();
			if (ms < 0) {
				System.out.println("nostartingzone");
				return 0;
			}
		}
		addFace(q,c.face);
		while (!q.isEmpty()) {
			Edge e = q.poll();
			ms = Dag.minl(ms,e.dist());
			if ((e.origin.type < 0) || (e.destination.type < 0)) {
				return (long)(0.5+(0.25*Math.PI*ms*ms));
			}
			if(ms < 0) {
				throw new RuntimeException("negative dist from queue");
			}
			addFace(q,e.getTwin().iface);
		}
		//System.out.println("did not find boundary");
		return 0;

	}

	private void addFace(PriorityQueue<Edge> q, Face f) {
		if (f.d.hasChildren()) {
			throw new RuntimeException("f has children"+f);
		}
		if (f.seen == 0) {
			f.seen = 1;
			Edge e = f.outer;
			for(int i=0;i<3;++i) {
				if(e.seen == 1) {
					throw new RuntimeException("e was seen: "+e);
				}
				e.seen = 1;
				if(e.dist() > 0) {
					q.add(e);
				}
				e = e.next;
			}
		}
	}

	private void legalizeEdge(Edge e) {
		e.legal++;
		legalized++;
		// (* pipj is the edge
		//    of t that may need to be flipped *)
		//e.legal++;
		//System.out.println("going: "+e);
		if (!e.exists())  {
			e.markked = 1;
			return;
			//System.out.println("legalizeEdge: "+e);
			//throw new RuntimeException("why is this here");
			//return;
		}

		// if pipj is illegal
		if (e.isIllegal()) {
			Edge pipk = e.getTwin().next;
			if (!pipk.exists()) {
				System.out.println("before pipk: "+pipk);
				throw new RuntimeException("pipk no exist");
			}
			Edge pkpj = e.getTwin().prev;
			if (!pkpj.exists()) {
				System.out.println("before pkpj: "+pkpj);
				throw new RuntimeException("pkpj no exist");
			}
			// (* flip pipj: *) Replace pipj with prpk
			//System.out.println("before illegal: "+e);
			e.flip();
			//System.out.println("after illegal: "+e);

			if (pipk.next.destination != Vertex.last) {
				throw new RuntimeException("pipk.next.destination not lastvertex");
			}
			if (pipk.prev.origin != Vertex.last) {
				throw new RuntimeException("pipk.prev.origin not lastvertex");
			}
			if (pkpj.prev.origin != Vertex.last) {
				throw new RuntimeException("pkpj.prev.origin not lastvertex");
			}
			if (pkpj.next.destination != Vertex.last) {
				throw new RuntimeException("pkpj.next.destination not lastvertex");
			}
			if (!pipk.exists()) {
				System.out.println("after pipk: "+pipk);
				throw new RuntimeException("after pipk no exist");
			}
			if (!pkpj.exists()) {
				System.out.println("after pkpj: "+pkpj);
				throw new RuntimeException("after pkpj no exist");
			}
			legalizeEdge(pipk);

			if (!pkpj.exists()) {
				System.out.println("after2 pkpj: "+pkpj);
				throw new RuntimeException("after2 pkpj no exist");
			}
			if (pkpj.prev.origin != Vertex.last) {
				throw new RuntimeException("after2 pkpj.prev.origin not lastvertex");
			}
			if (pkpj.next.destination != Vertex.last) {
				throw new RuntimeException("after2 pkpj.next.destination not lastvertex");
			}

			legalizeEdge(pkpj);
		}
	}

	private Dag findTriangleContaining(Coord pr) {
		// start at root of D;
		Dag c = d;
		// invariant: pr lies in c
		while (c.hasChildren()) {
			for(int i=0;i<c.children.size();++i) {
				if(c.children.get(i).containsPoint(pr) != 0) {
					c = c.children.get(i);
					break;
				}
			}
		}
		// finding one triangle is enough, we can later find the edge it lies on
		if (c.hasChildren()) throw new RuntimeException("child has children");
		return c;
	}

}


class CleanTriang {

	HashSet<Edge> edges = null;
	HashSet<Face> faces = null;
	HashSet<Vertex> vertices = null;
	HashSet<Dag> bagen = null;

	public CleanTriang() {
		edges = new HashSet<Edge>();
		faces = new HashSet<Face>();
		vertices = new HashSet<Vertex>();
		bagen = new HashSet<Dag>();
	}

	void work(Triangulation t) {
		System.out.println("CleanTriang checking...\n\n\n");
		checkAdd(t.d);
		// check if everyone's mirrors is in there
		checkTwins();
		// check if all vertices have valid outgoign edges
		checkVerticeIncidents();
		display();
	}
	void checkAdd(Dag d) {
		LinkedList<Dag> dagen = new LinkedList<Dag>();
		System.out.println("dagen: "+Dag.ids);
		dagen.add(d);
		while(!dagen.isEmpty()) {
			Dag bb = dagen.poll();
			if (!bb.hasChildren()) {
				//System.out.println(bb);
				if ((!bagen.contains(bb)) && ((bb.vertices[0].type >0) &&
				(bb.vertices[1].type > 0) && (bb.vertices[2].type >0))) {
					blaadd(bb);
				}
				//System.out.println(bb);
			} else {
				for (Dag child: bb.children) {
					if (!dagen.contains(child)) {
						dagen.add(child);
					}
				}
			}
		}
	}
	void blaadd(Dag d) {
		bagen.add(d);
		Face f = d.face;
		if (f.d != d) {
			throw new RuntimeException("face d crosslink");
		}
		if ((d.vertices[0].type < 0) || (d.vertices[1].type < 0) || (d.vertices[2].type < 0)) {
			return;
		}
		if (!faces.contains(f)) {
			if (f.outer.iface != f) throw new RuntimeException("the cake is a lie");
			faces.add(f);
			if (!faces.contains(f)) throw new RuntimeException("sdfadsf");
			checkAddEdge(f.outer,f);
		}
	}

	void checkAddEdge(Edge e, Face f) {
		// add triangle
		if (edges.contains(e.twin)) { return; }
		Edge[] es= {e,e.next,e.prev};
		if (es[0] != e) throw new RuntimeException("wrong compar");
		for(int i=0;i<3;++i) {
			if ((es[i] == es[(i+1)%3]) || (es[i] == es[(i+3-1)%3]) ||
				(es[i].next != es[(i+1)%3]) || (es[i] != es[(i+1)%3].prev) ||
			    (es[(i+3-1)%3].next != es[i]) || (es[(i+3-1)%3] != es[i].prev) ||
			    (es[i].iface != f) || (es[i].origin != es[i].prev.destination) ||
			    (es[i].next.prev != es[i]) || (es[i].prev.next != es[i]) ||
			    (es[i].destination != es[i].next.origin) ||
			    (es[i].destination == es[i].origin)) {
					throw new RuntimeException("chaining error");
			}
		}
		if ((edges.contains(e)) || (edges.contains(e.next)) || (edges.contains(e.prev))) {
			throw new RuntimeException("edges contains esomething");
		}
		//if ((e.markked != 0) || (e.next.markked != 0) || (e.prev.markked != 0)) return;
		if (e.markked != 0) return;
		edges.add(e);
		edges.add(e.next);
		edges.add(e.prev);
		checkAddVertices(e.origin,e.destination,e.next.destination);
	}

	void checkAddVertices(Vertex a, Vertex b, Vertex c) {
		Vertex[] vs = {a,b,c};
		for(int i=0;i<3;++i) {
			if ((vs[i] == vs[(i+1)%3]) || (vs[i] == vs[(i+3-1)%3])) {
				throw new RuntimeException("vertex doubles");
			}
			//if((vs[0].type <0) || (vs[1].type < 0) || (vs[2].type <0)) {
			//	throw new RuntimeException("vstype");
			//}
			if (!vertices.contains(vs[i])) {
				vertices.add(vs[i]);
			}
		}
	}

	void checkTwins() {
		for (Edge e : edges) {
			checkTwin(e,e.twin);
		}
	}

	void checkTwin(Edge e,Edge twin) {

		if (e.isBorder()) {
			if (twin != null) throw new RuntimeException("twin not null");
		} else {
			if (twin == null) throw new RuntimeException("twin null");
			//if (!edges.contains(twin)) throw new RuntimeException("twin not in edges");
			if ((twin.origin != e.destination) || (e.origin != twin.destination)) {
				throw new RuntimeException("twin origin destination");
			}
			if (twin.iface == e.iface) throw new RuntimeException("twin face error");
			if (twin.twin != e) throw new RuntimeException("twin callback error");
			if (twin.next.destination == e.next.destination) {
				//throw new RuntimeException("twin.next.destination = e.next.destination\n"+e+"\n"+twin);
			}
			if (twin.prev.origin == e.prev.origin) {
				//throw new RuntimeException("twins.prev.origin = e.prev.origin\n"+e+"\n"+twin);
			}
		}

	}

	void checkVerticeIncidents() {
		for (Vertex v : vertices) {
			checkVertex(v);
		}
	}

	void checkVertex(Vertex v) {
		//if (!edges.contains(v.iedge)) throw new RuntimeException("no valid incidentedge"+v);
		if (v.iedge.origin != v) throw new RuntimeException("iedge origin is not v");
		if ((v.type != -3) && (v.type != -2) && (v.type != -1) && (v.type != 1)) {
			throw new RuntimeException("wrong vertex type");
		}
	}

	void display() {
		System.out.println("triangulation OK");
		System.out.println("vertices: "+vertices.size()+" out of "+Vertex.ids+" created.");
		System.out.println("edges: "+edges.size()+" out of "+Edge.ids+" created.");
		System.out.println("triangles: "+faces.size()+ " out of "+Face.ids+" created.");
		System.out.println();
		System.out.println("flips: "+Edge.flipped+", edgeinsertions: "+Edge.edgeinsertions+", "+
						   "interiorinsertions: "+Face.interiorinsertions+", legalized: "+
						   Triangulation.legalized);
		System.out.println();
		System.out.println("vertices:");
		for (Vertex v : vertices) {
			System.out.println(v);
		}
		System.out.println();
		System.out.println("edges:");
		for (Edge e : edges) {
			System.out.println(e);
		}
		System.out.println();
		System.out.println("triangles:");
		for (Face f : faces) {
			System.out.println(f);
		}
		System.out.println();
	}
}

class Main extends Titanic_ando {} // for DOMJudge
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
			cleanup();
			run(i);
		}
	}

	private static void cleanup() {
		Vertex.last = null;
		Vertex.ids = 0;
		Edge.ids = 0;
		Edge.flipped = 0;
		Edge.edgeinsertions = 0;
		Face.interiorinsertions = 0;
		Face.ids = 0;
		Triangulation.legalized = 0;
		Dag.ids = 0;
	}

	private static void run(long rrun) throws IOException {
		int n = (int)leesInt(); // number of mines
		Coord[] mines = new Coord[n];
		for(int i=0;i<n;++i) {
			mines[i] = new Coord((int)leesInt(),(int)leesInt());
		}
		// DONE READING INPUT


		Triangulation delaunay = new Triangulation();
		delaunay.triangulatePoints(mines);

		CleanTriang d = new CleanTriang();
		d.work(delaunay);


		//for(int i=0;i<delaunay.ps.length;++i) {
		//	System.out.println(delaunay.ps[i]);
		//}
		System.out.println(delaunay.maxSoldiers());
		//System.out.println("okk");

		SVGWriter r = new SVGWriter("run-"+rrun+".svg",d);
		r.writeSVG();
	}

}


class SVGWriter {
	CleanTriang d = null;
	PrintStream out = null;
	public SVGWriter(String s, CleanTriang d) {
		this.d = d;
		try {
			this.out = new PrintStream(s);
		} catch (java.io.FileNotFoundException e) {}
	}

	void writeSVG() {
		writeSVG_begin();
		writeSVG_end();
	}

	void writeSVG_begin() {
		// bounds
		int y0=0,y1=0,x0=0,x1=0;
		for (Vertex v:d.vertices) {
			//if (v.type < 0) continue;
			x0 = Math.min(x0,(int)v.coords.x);
			y0 = Math.min(y0,(int)v.coords.y);
			x1 = Math.max(x1,(int)v.coords.x);
			y1 = Math.max(y1,(int)v.coords.y);
		}
		x0 -= 4; y0 -= 4; x1 += 4; y1 += 4;
		// stylesheet
		out.println("<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 1.1//EN'  'http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd'>");
		out.print("<svg viewBox='"+x0+","+y0+","+(x1-x0)+","+(y1-y0)+"' width='100%' height='100%' version='1.1' xmlns='http://www.w3.org/2000/svg'>");
		out.println(" <style>");
		out.println("   * { ");
		out.println("     stroke: black;");
		out.println("     stroke-width: 0.05;");
		out.println("   }");
		out.println("   circle {");
		out.println("     fill: red;");
		out.println("     fill-opacity: 0.3;");
		out.println("     stroke: red;");
		out.println("   }");
		out.println("   .center {");
		out.println("     fill: red;");
		out.println("     fill-opacity: 1;");
		out.println("   }");
		out.println("   .me {");
		out.println("     fill: green;");
		out.println("   }");
		out.println("   .grid {");
		out.println("     stroke: #ccc;");
		out.println("   }");
		out.println("   .hull {");
		out.println("     stroke: #00d;");
		out.println("   }");
		out.println("   .escape {");
		out.println("     stroke-width: 0;");
		out.println("     fill:   green;");
		out.println("   }");
		out.println("   .triangle {");
		out.println("     stroke: #00d;");
		out.println("     fill: blue;");
		out.println("     fill-opacity: 0.1;");
		out.println("   }");
		out.println("   .triangle:hover {");
		out.println("     stroke: #c0d;");
		out.println("     fill: #c0d;");
		out.println("     fill-opacity: 0.3;");
		out.println("   }");
		out.println("   .flip {");
		out.println("     stroke: #0d0;");
		out.println("     fill: green;");
		out.println("   }");
		out.println("   .flop {");
		out.println("     stroke: #d00;");
		out.println("     fill: yellow;");
		out.println("   }");
		out.println(" </style>");
		// write grid
		int step = Math.max(1, Math.max((x1-x0)/50, (y1-y0)/50));
		for (int x = x0 ; x <= x1 ; x+=step) {
			out.println(" <line x1='"+x+"' x2='"+x+"' y1='"+y0+"' y2='"+y1+"' class='grid' />");
		}
		for (int y = y0 ; y <= y1 ; y+=step) {
			out.println(" <line x1='"+x0+"' x2='"+x1+"' y1='"+y+"' y2='"+y+"' class='grid' />");
		}
		// write mines
		for (Vertex v : d.vertices) {
			//if (v.type < 0) continue;
			out.println(" <circle cx='"+v.coords.x+"' cy='"+v.coords.y+"' r='2' />");
			out.println(" <circle cx='"+v.coords.x+"' cy='"+v.coords.y+"' r='0.1' class='center'/>");
		}
		// write triangulation
		//writeSVG(root,"triangle");
		writeSVGTriangles();
	}

	void writeSVG_end() {
		// write me
		out.println(" <rect x='-0.5' y='-0.5' width='1' height='1' class='me'/>");
		out.println("</svg>");
	}
/*
	void collectTriangles(HashSet<Triangle> out, Triangle t) {
		if (out.contains(t)) return;
		out.add(t);
		if (t.children != null) {
			for (Triangle c : t.children) {
				collectTriangles(out,c);
			}
		}
	}
	/*
	void writeSVG(Triangle root, String cls) {
		HashSet<Triangle> tris = new HashSet<Triangle>();
		collectTriangles(tris,root);
		for (Triangle t : tris) {
			if (t.children == null && !t.a.special && !t.b.special && !t.c.special) {
				out.println(" <polygon points='"+t.a.x+","+t.a.y+" "+t.b.x+","+t.b.y+" "+t.c.x+","+t.c.y+"' class='"+cls+"' />");
			}
		}
	}
	*/
	void writeSVGTriangles() {
		for (Face f:d.faces) {
			Edge e = f.outer;
			//if ((e.origin.type < 0) || (e.destination.type < 0) || (e.next.destination.type < 0)) {
			//	continue;
			//}
			String s = " <polygon points='"+e.origin.coords.x+","+e.origin.coords.y;
			for (int i=0;i<2;++i) {
				e=e.next;
				s+=" "+e.origin.coords.x+","+e.origin.coords.y;
			}
			s+="' class='triangle' />";
			out.println(s);
		}
	}

	void writeEscapeSVG() {
		/*
		// print widths
		try {
			PrintStream out = new PrintStream("escape.svg");
			writeSVG_begin(out);
			for(Map.Entry<Triangle,Double> entry : best.entrySet()) {
				Triangle t = entry.getKey();
				for (Edge ee : new Edge[] { t.ab, t.bc, t.ca }) {
					Point p = ee.getCenter();
					double r = Math.sqrt(Math.min(ee.r_sqr(),entry.getValue())) - 2;
					if (r > 0)
					out.println(" <circle cx='"+p.x+"' cy='"+p.y+"' r='"+r+"' class='escape' />");
				}
			}
			writeSVG_end(out);
		} catch (Exception exasdf) {}
		*/
	}
}
