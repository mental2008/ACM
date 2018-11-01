#include <bits/stdc++.h>
#define maxn 330000+20
using namespace std;
int n,q;
int cnt=0;
struct node
{
	node *f;
	node *ch[2];
	int size;
	int lazy;
	int id;
}S[maxn];
node *root;
void pushdown(node *u)
{
	if((!u->lazy)||(u==NULL))return ;
	if(u->ch[0]!=NULL)u->ch[0]->lazy^=1;
	if(u->ch[1]!=NULL)u->ch[1]->lazy^=1;
	node *y=u->ch[0];
	u->ch[0]=u->ch[1];
	u->ch[1]=y;
	u->lazy=0;
}
void pushup(node *u)
{
	u->size=1;
	if(u->ch[0]!=NULL)u->size+=u->ch[0]->size;
	if(u->ch[1]!=NULL)u->size+=u->ch[1]->size;
}
void rotate(node *u)
{
	node *f=u->f;
	if(f==NULL)return ;
	pushdown(u);
	pushdown(f);
	node *ff=f->f;
	int d=u==f->ch[1];
	int dd=0;
	if(ff!=NULL)dd=f==ff->ch[1];

	if(u->ch[d^1])u->ch[d^1]->f=f;
	f->ch[d]=u->ch[d^1];

	/*int size=u->size;
	u->size=f->size;
	f->size=f->size-size;
	if(u->ch[d^1]!=NULL)f->size+=u->ch[d^1]->size;
	*/
	f->f=u;
	u->ch[d^1]=f;

	if(ff!=NULL)ff->ch[dd]=u;
	u->f=ff;

	pushup(f);
	pushup(u);
}
void splay(node *u,node *p)
{
	pushdown(u);
	while(u->f!=p)
	{
		node *f=u->f;
		node *ff=f->f;
		if(ff==p)
		{
			rotate(u);
			break;
		}
		int d=u==f->ch[1];
		int dd=f==ff->ch[1];
		if(d==dd)rotate(f);
		else rotate(u);
		rotate(u);
	}
	pushup(u);
	if(p==NULL)root=u;
}
void insert(int id)
{
	if(root==NULL)
	{
		node *y=&S[++cnt];
		y->id=id;
		y->size=1;
		y->ch[0]=NULL;
		y->ch[1]=NULL;
		y->f=NULL;
		y->lazy=0;
		root=y;
		return ;
	}
	node *u=root;
	node *y;
	while(1)
	{
		u->size++;
		if(id<u->id)
		{
			//×ó±ß
			if(u->ch[0]!=NULL)u=u->ch[0];
			else
			{
				y=&S[++cnt];
	        	y->id=id;
		        y->size=1;
		        y->ch[0]=NULL;
				y->ch[1]=NULL;
		        y->f=u;
		        u->ch[0]=y;
		        y->lazy=0;
		        break;
			}
		}
		else
		{
			if(u->ch[1]!=NULL)u=u->ch[1];
			else
			{
				y=&S[++cnt];
	        	y->id=id;
		        y->size=1;
		        y->ch[0]=NULL;
				y->ch[1]=NULL;
		        y->f=u;
		        u->ch[1]=y;
		        y->lazy=0;
		        break;
			}
		}
	}
	splay(y,NULL);
}
char s[10];
node *find (int x)
{
	node *u=root;
	while(1)
	{
		int xx=1;
		if(u->ch[0]!=NULL)xx+=u->ch[0]->size;
		if(xx==x)return u;
		if(x<xx)u=u->ch[0];
		else
		{
			x-=xx;
			u=u->ch[1];
		}
	}
}
void cut(int l,int r,int c)
{
	node *x=find(l);
	node *y=find(r+2);
	splay(x,NULL);
	splay(y,root);
	node *u=root->ch[1]->ch[0];
	/*root->size-=u->size;
	root->ch[1]->size-=u->size;
	*/
	root->ch[1]->ch[0]=NULL;
	pushup(root->ch[1]);
	pushup(root);
	//u->f=NULL;
	node *yy=find(c+1);
	splay(yy,NULL);
	node *xx=find(c+2);
	splay(xx,root);
	//²åÈë
	root->ch[1]->ch[0]=u;
	u->f=root->ch[1];
	//root->ch[1]->size+=u->size;
	//root->size+=u->size;
	pushup(root->ch[1]);
	pushup(root);
}
void flip(int l,int r)
{
	node *x=find(l);
	node *y=find(r+2);
	splay(x,NULL);
	splay(y,root);
	node *u=root->ch[1]->ch[0];
	u->lazy^=1;
}
void dfs(node *u)
{
	//printf("debug :  %d  %d\n",u->size,u->id);
	pushdown(u);
	if(u->ch[0])dfs(u->ch[0]);
	if(u->id!=0&&u->id!=n+1)printf("%d ",u->id);
	if(u->ch[1])dfs(u->ch[1]);
}
int main()
{
	/*freopen("hoho.txt","r",stdin);
	while(scanf("%d%d",&n,&q)!=EOF&&!(n<0&&q<0))
	{
		cnt=0;
		root=NULL;
		for(int i=0;i<=n+1;i++)insert(i);
		for(int i=1;i<=q;i++)
		{
			scanf("%s",s);
			if(s[0]=='C')
			{
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				cut(a,b,c);
			}
			else
			{
				int a,b;
				scanf("%d%d",&a,&b);
				flip(a,b);
			}
		}
		dfs(root);
		printf("\n");
	}*/
	int n, m;
	cnt=0;
    root=NULL;
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n + 1; ++i) {
        insert(i);
	}
	for(int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        cut(a, a + b - 1, 0);
	}
	dfs(root);
	return 0;
}
