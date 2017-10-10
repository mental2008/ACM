/*
 * Minefield/titanic
 * Solution by Twan
 * 13:23-13:30 14:49-15:50 14:25-16:04
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define SQR(x) ((x)*(x))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

/*******************************************************************************************
 * Input
 *******************************************************************************************/

#define EPSILON 1e-6
#define MAX_N 1000000
#define MAX_TRIS 2000000
#define EXTRA_TRIS 4
int num_points;
double x_[MAX_N+EXTRA_TRIS], y_[MAX_N+EXTRA_TRIS];
double *x,*y;

void read_input() {
	int i;
	x = x_+EXTRA_TRIS;
	y = y_+EXTRA_TRIS;
	scanf("%d",&num_points);
	for (i = 0 ; i < num_points ; ++i) {
		scanf("%lf %lf",&x[i],&y[i]);
	}
}

/*******************************************************************************************
 * Triangulation: Triangle construction
 *******************************************************************************************/

struct Triangle_;
typedef int PointRef;
typedef struct Triangle_* TriangleRef;
typedef int SideRef;
typedef int bool;
#define true 1
#define false 0

typedef struct {
	TriangleRef tri;
	SideRef     side;
} Edge;

typedef struct Triangle_ {
	int i; /* index in array */
	PointRef p[3];
	Edge     edge[3];
	TriangleRef children[3];
} Triangle;

int num_tris;
Triangle triangles[MAX_TRIS];

TriangleRef new_triangle(PointRef p0, PointRef p1, PointRef p2) {
	TriangleRef tri = &triangles[num_tris++];
	tri->i = num_tris-1;
	tri->children[0] = 0;
	tri->p[0] = p0;
	tri->p[1] = p1;
	tri->p[2] = p2;
	return tri;
}
void set_edge(Edge a, Edge b) {
	if (a.tri) a.tri->edge[a.side] = b;
	if (b.tri) b.tri->edge[b.side] = a;
	if (a.tri && b.tri) {
		assert(a.tri->p[(a.side+1)%3] == b.tri->p[(b.side+2)%3]);
		assert(a.tri->p[(a.side+2)%3] == b.tri->p[(b.side+1)%3]);
	}
}

/*******************************************************************************************
 * Triangulation: Triangulation usage and construction
 *******************************************************************************************/

double side(PointRef a, PointRef b, PointRef p) {
	return (x[b]-x[a])*(y[p]-y[a]) - (y[b]-y[a])*(x[p]-x[a]);
}
bool contains(TriangleRef t, PointRef p) {
	double a = side(t->p[0],t->p[1],p);
	double b = side(t->p[1],t->p[2],p);
	double c = side(t->p[2],t->p[0],p);
	/*return a <= 0 && b <= 0 && c <= 0;*/
	return a >= -EPSILON && b >= -EPSILON && c >= -EPSILON;
	/*return (a <= 0 && b <= 0 && c <= 0)
	    || (a >= 0 && b >= 0 && c >= 0);*/
}

TriangleRef find(TriangleRef root, PointRef p) {
	int i;
  again:
	assert(contains(root,p));
	for (i = 0 ; i < 3 && root->children[i] ; ++i) {
		if (contains(root->children[i],p)) {
			root = root->children[i];
			goto again;
		}
	}
	return root;
}

void flip(TriangleRef tri, SideRef edge);

TriangleRef add_point(TriangleRef root, PointRef p) {
	TriangleRef tab,tbc,tca;
	root = find(root,p);
	
	/* split it into three triangles */
	tab = new_triangle(root->p[0], root->p[1], p);
	tbc = new_triangle(root->p[1], root->p[2], p);
	tca = new_triangle(root->p[2], root->p[0], p);
	
	set_edge((Edge){tab,0}, (Edge){tbc,1});
	set_edge((Edge){tbc,0}, (Edge){tca,1});
	set_edge((Edge){tca,0}, (Edge){tab,1});
	set_edge((Edge){tab,2}, root->edge[2]);
	set_edge((Edge){tbc,2}, root->edge[0]);
	set_edge((Edge){tca,2}, root->edge[1]);
	
	root->children[0] = tab;
	root->children[1] = tbc;
	root->children[2] = tca;
	
	flip(tab,2);
	flip(tbc,2);
	flip(tca,2);
	
	return root;
}

/* is p4 in the circumcircle of <p1,p2,p3>?*/
bool in_circumcircle_manual(PointRef p1,PointRef p2,PointRef p3,PointRef p4) {
	double x2 = x[p2] - x[p1], y2 = y[p2] - y[p1];
	double x3 = x[p3] - x[p1], y3 = y[p3] - y[p1];
	double x4 = x[p4] - x[p1], y4 = y[p4] - y[p1];
	/* circumcenter = intersection of  {x2,y2}/2+t*{y2,-x2} == {x3,y3}/2+s*{y3,-x3}
	   t = ((x2-x3)*x3 + (y2-y3)*y3) / (2*(x2*y3 - y2*x3))
	 */
	double denom = (2*(x2*y3 - y2*x3));
	double cx =  x2*x2*y3 - x3*x3*y2 + y2*y2*y3 - y3*y3*y2;
	double cy = -x2*x2*x3 + x3*x3*x2 - y2*y2*x3 + y3*y3*x2;
	/*x4 * denom*/
	/*fprintf(stderr, "circumcircle of (%d,%d) (%d,%d) (%d,%d) is (%f,%f)\n", x[p1],y[p1],x[p2],y[p2],x[p3],y[p3],cx/denom+x[p1],cy/denom+y[p1]);
	fprintf(stderr, "or              (%.f,%.f) (%.f,%.f) (%.f,%.f) is (%.1f,%.1f)\n", 0.,0.,x2,y2,x3,y3,cx/denom,cy/denom);
	*/
	return false;
}
bool in_circumcircle(PointRef p1,PointRef p2,PointRef p3,PointRef p4) {
	double u11 = x[p1] - x[p4];
	double u21 = x[p2] - x[p4];
	double u31 = x[p3] - x[p4];
	double u12 = y[p1] - y[p4];
	double u22 = y[p2] - y[p4];
	double u32 = y[p3] - y[p4];
	double u13 = SQR(x[p1]) - SQR(x[p4]) + SQR(y[p1]) - SQR(y[p4]);
	double u23 = SQR(x[p2]) - SQR(x[p4]) + SQR(y[p2]) - SQR(y[p4]);
	double u33 = SQR(x[p3]) - SQR(x[p4]) + SQR(y[p3]) - SQR(y[p4]);
	double det = -u13*u22*u31 + u12*u23*u31 + u13*u21*u32 - u11*u23*u32 - u12*u21*u33 + u11*u22*u33;
	return det > EPSILON;
}
bool illegal_edge(TriangleRef tri, SideRef pi) {
	PointRef p1 = tri->p[(pi+0)%3];
	PointRef p2 = tri->p[(pi+1)%3];
	PointRef p3 = tri->p[(pi+2)%3];
	PointRef p4 = tri->edge[pi].tri->p[tri->edge[pi].side];
	//return in_circumcircle(p1,p2,p3,p4);
	//return in_circumcircle(p1,p2,p3,p4);
	return in_circumcircle(p2,p4,p3,p1);
}

void write_triangulation_svg(FILE* f);
void flip(TriangleRef tri, SideRef pi) {
	TriangleRef trj,trk,trl;
	int pj;
	
	trj = tri->edge[pi].tri;
	pj = tri->edge[pi].side;
	
	if (!trj) return;
	if (!illegal_edge(tri,pi)) return;
	assert(tri->p[(pi+2)%3] == trj->p[(pj+1)%3]);
	assert(tri->p[(pi+1)%3] == trj->p[(pj+2)%3]);
	
	if (false) {
		static int j=0;
		j++;
		char name[1230];
		sprintf(name,"flip%d.svg",j);
		FILE *f = fopen(name,"wt");
		tri->i = -tri->i;
		trj->i = -trj->i;
		write_triangulation_svg(f);
		tri->i = -tri->i;
		trj->i = -trj->i;
		fclose(f);
	}
	
	/* flip edge between tri,trj */
	trk = new_triangle(tri->p[(pi+1)%3], trj->p[pj], tri->p[pi]);
	trl = new_triangle(trj->p[(pj+1)%3], tri->p[pi], trj->p[pj]);
	
	/*
	fprintf(stderr, "flipped <%d,%d,%d> <%d,%d,%d>\n", tri->p[(pi+0)%3], tri->p[(pi+1)%3], tri->p[(pi+2)%3], trj->p[(pj+0)%3], trj->p[(pj+1)%3], trj->p[(pj+2)%3]);
	fprintf(stderr, "to      <%d,%d,%d> <%d,%d,%d>\n", trk->p[0], trk->p[1], trk->p[2], trl->p[0], trl->p[1], trl->p[2]);
	*/
	
	set_edge((Edge){trk,0}, (Edge){trl,0});
	set_edge((Edge){trk,1}, tri->edge[(pi+2)%3]);
	set_edge((Edge){trk,2}, trj->edge[(pj+1)%3]);
	set_edge((Edge){trl,1}, trj->edge[(pj+2)%3]);
	set_edge((Edge){trl,2}, tri->edge[(pi+1)%3]);
	
	tri->children[0] = trk; tri->children[1] = trl; tri->children[2] = 0;
	trj->children[0] = trk; trj->children[1] = trl; trj->children[2] = 0;
	
	flip(trk,1);
	flip(trk,2);
	flip(trl,1);
	flip(trl,2);
	
	if (false) {
		static int j=0;
		j++;
		char name[1230];
		sprintf(name,"flop%d.svg",j);
		FILE *f = fopen(name,"wt");
		trk->i = -trk->i;
		trl->i = -trl->i;
		write_triangulation_svg(f);
		trk->i = -trk->i;
		trl->i = -trl->i;
		fclose(f);
	}
}


TriangleRef root;

void clear_triangulation(void) {
	num_tris = 0;
	
	#define LOTS 1e6
	x[-3] = -LOTS; y[-3] = -LOTS;
	x[-2] = +LOTS; y[-2] = -LOTS;
	x[-1] = 0;     y[-1] = +LOTS;
	root = new_triangle(-3,-2,-1);
	root->edge[0].tri = root->edge[1].tri = root->edge[2].tri;
}
void make_triangulation(void) {
	int i;
	clear_triangulation();
	/* TODO: shuffle */
	for (i = 0 ; i < num_points ; ++i) {
		add_point(root,i);
	}
}

/*******************************************************************************************
 * Debug
 *******************************************************************************************/

void write_triangulation_svg(FILE* f) {
	int i;
	int x0=0,y0=0,x1=0,y1=0;
	for (i = 0 ; i < num_points ; ++i) {
		x0 = MIN(x0,x[i]); x1 = MAX(x1,x[i]);
		y0 = MIN(y0,x[i]); y1 = MAX(y1,y[i]);
	}
	x0 -= 4; y0 -= 4; x1 += 4; y1 += 4;
	
	fprintf(f,"<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 1.1//EN'  'http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd'>\n");
	fprintf(f,"<svg viewBox='%d,%d,%d,%d' width='100%%' height='100%%' version='1.1' xmlns='http://www.w3.org/2000/svg'>\n",
		x0,y0,x1-x0,y1-y0
	);
	fprintf(f,"<style>");
	fprintf(f,"	  * { stroke-width: 0.05; }");
	fprintf(f,"   .mine { fill: red; stroke: red; fill-opacity: 0.2; }");
	fprintf(f,"   .tri  { fill: blue; stroke: blue; fill-opacity: 0.2; }");
	fprintf(f,"   .flip { fill: green; stroke: green; fill-opacity: 0.2; }");
	fprintf(f,"   .me   { fill: green; }");
	fprintf(f,"</style>");
	for (i = 0 ; i < num_points ; ++i) {
		fprintf(f,"<circle cx='%f' cy='%f' r='2' class='mine' />\n", x[i], y[i]);
	}
	for (i = 0 ; i < num_tris ; ++i) {
		TriangleRef t = &triangles[i];
		if (t->children[0]) continue;
		if (t->p[0] < 0 || t->p[1] < 0 || t->p[2] < 0) continue;
		fprintf(f,"<polygon points='%f,%f %f,%f %f,%f' class='%s' />\n",
			x[t->p[0]], y[t->p[0]],
			x[t->p[1]], y[t->p[1]],
			x[t->p[2]], y[t->p[2]],
			(t->i >= 0) ? "tri" : "flip"
		);
	}
	fprintf(f," <rect x='-0.5' y='-0.5' width='1' height='1' class='me'/>\n");
	fprintf(f,"</svg>");
}

/*******************************************************************************************
 * Heap
 *******************************************************************************************/

int tri_heap_size;
int tri_heap[MAX_TRIS+1]; /* first index is 1 */
double r_sqr[MAX_TRIS];

void tri_heap_clear(void) {
	int i;
	tri_heap_size = 0;
	for (i = 0 ; i < num_tris ; ++i) {
		r_sqr[i] = -1;
	}
}
void tri_heap_bubble_down(void) {
	/* bubble down */
	int i = tri_heap_size;
	while (i > 1 && r_sqr[tri_heap[i]] > r_sqr[tri_heap[i/2]]) {
		int old_v = tri_heap[i];
		tri_heap[i] = tri_heap[i/2];
		tri_heap[i/2] = old_v;
		i /= 2;
	}
}
void tri_heap_push(int x, double v) {
	if (r_sqr[x] < v) {
		r_sqr[x] = v;
		tri_heap[++tri_heap_size] = x;
		tri_heap_bubble_down();
	}
}
bool tri_heap_empty(void) {
	return tri_heap_size == 0;
}
int tri_heap_pop(void) {
	/* int result = tri_heap[1];
	bubble up
	int i = 1;
	while (i < tri_heap_size) {
	}
	tri_heap_size--;
	return result; */
	int i,best = 1;
	for (i = 2 ; i <= tri_heap_size ; ++i) {
		if (r_sqr[tri_heap[i]] > r_sqr[tri_heap[best]]) best=i;
	}
	int result = tri_heap[best];
	tri_heap[best] = tri_heap[tri_heap_size];
	tri_heap_size--;
	return result;
}

/*******************************************************************************************
 * Dijkstra
 *******************************************************************************************/


double dist_sqr(PointRef a, PointRef b) {
	return SQR(x[a]-x[b]) + SQR(y[a]-y[b]);
}
double edge_width(TriangleRef tri, SideRef side) {
	PointRef a = tri->p[(side+1)%3];
	PointRef b = tri->p[(side+2)%3];
	return 0.25 * dist_sqr(a,b);
}
double edge_width2(Edge e) {
	PointRef a = e.tri->p[(e.side+1)%3];
	PointRef b = e.tri->p[(e.side+2)%3];
	return 0.25 * dist_sqr(a,b);
}

double dist_to_any(PointRef p) {
	double d = 1e100;
	int i;
	for (i = 0 ; i < num_points ; ++i) {
		double dp = dist_sqr(p,i);
		d = MIN(d,dp);
	}
	return d;
}

double solve(void) {
	int i,e;
	x[-4] = y[-4] = 0;
	TriangleRef start = find(root,-4);
	double start_dist = dist_to_any(-4);
	/* build a heap */
	tri_heap_clear();
	tri_heap_push(start->i, start_dist);
	/* Dijkstra */
	double escape = 0;
	while (!tri_heap_empty()) {
		i = tri_heap_pop();
		TriangleRef tri = &triangles[i];
		if (false) fprintf(stderr,"reached %d with %f\n",i,r_sqr[i]);
		for (e = 0 ; e < 3 ; ++e) {
			if (!tri->edge[e].tri) {
				escape = MAX(escape, r_sqr[i]);
			} else {
				double ew = edge_width(tri,e);
				double w = MIN(r_sqr[i], ew);
				tri_heap_push(tri->edge[e].tri->i, w);
			}
		}
	}
	return escape;
}

/*******************************************************************************************
 * Checking the triangulation
 *******************************************************************************************/

void check_triangulation(void) {
	int i,j;
	for (i = 0 ; i < num_tris ; ++i) {
		TriangleRef tri = &triangles[i];
		for (j = 0 ; j < num_points ; ++j) {
			if (in_circumcircle(tri->p[0],tri->p[1],tri->p[2], j)) {
				fprintf(stderr,"Empty circumcircle property is violated\n");
				exit(1);
			}
		}
	}
}

/*******************************************************************************************
 * Main
 *******************************************************************************************/

void run(void) {
	double r_sqr,r;
	read_input();
	make_triangulation();
	if (false) check_triangulation();
	if (false) write_triangulation_svg(stderr);
	r_sqr = solve();
	r = sqrt(r_sqr) - 2;
	if (r <= 0) {
		/* don't forget this special case */
		printf("%.f\n", 0.);
	} else {
		printf("%.f\n", floor(r*r*M_PI));
	}
}

int main(void) {
	int runs, i;
	scanf("%d",&runs);
	for (i = 0 ; i < runs ; ++i) {
		run();
	}
	return EXIT_SUCCESS;
}
