#include <bits/stdc++.h>
#define EPS 1e-9
#define INF 1234567899999

using namespace std;

typedef pair <int, double> ii;

struct point
{
	double x, y;
	point () {}
	point (double _x, double _y) : x (_x), y (_y) {}
	bool operator < (point other) const
	{
		return y < other.y;
	}
};

struct line
{
	double a, b, c;
};

struct st
{
	double L, R;
	vector <point> l, r;
	st () {}
};

st tile[22]; 

line PointsToLine (point p1, point p2)
{
	line l;
	if (fabs (p1.x - p2.x) < EPS)
	{
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	}
	else
	{
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
	
	return l;
}

point Intersection (line l1, line l2)
{
	point p;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
	
	return p;
}

int n, m;
vector <ii> AdjList[55];
double dp[14][1 << 14];

double f (int item, int mask)
{
	if ((1 << n) - 1 == mask) return 0;
	
	double &p = dp[item][mask];
	
	if (p != -1) return p;
	
	p = INF;
	
	for (int i = 0; i < (int)AdjList[item].size (); i++)
	{
		ii v = AdjList[item][i];
		if (((1 << v.first) & mask) == 0)
		{
			p = min (p, v.second + f (v.first, mask | (1 << v.first)));
		}
	}
	
	return p;
}

int main ()
{
	double x[10101], y[10101];
	scanf ("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &m);
		double bigger = 0;
		double L = 0, R = 0;
		
		for (int j = 0; j < m; j++)
		{
			scanf ("%lf%lf", &x[j], &y[j]);
			L = min (L, x[j]);
			R = max (R, x[j]);
			bigger = max (bigger, y[j]);
		}
		
		tile[i].L = L;
		tile[i].R = R;
		
		tile[i].l.push_back (point (x[0], y[0]));
		
		for (int j = 1; j < m; j++)
		{
			if (y[j] == bigger)
			{
				tile[i].r.push_back (point (x[j], y[j]));
				for (j++; j < m; j++)
				{
					tile[i].l.push_back (point (x[j], y[j]));
				}
				break;
			}
			tile[i].r.push_back (point (x[j], y[j]));
		}
		
		sort (tile[i].r.begin (), tile[i].r.end ());
		sort (tile[i].l.begin (), tile[i].l.end ());
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			
			double dist = tile[i].r[0].x;
			
			for (int k = 1; k < (int)tile[i].r.size (); k++)
			{
				int pos = upper_bound (tile[j].l.begin (), tile[j].l.end (), tile[i].r[k]) - tile[j].l.begin ();
				line a = PointsToLine (point (tile[j].l[pos].x + dist, tile[j].l[pos].y), point (tile[j].l[pos - 1].x + dist, tile[j].l[pos - 1].y));
				line b = PointsToLine (tile[i].r[k], point (tile[i].r[k].x + 12345678, tile[i].r[k].y));
				point p = Intersection (a, b);
				
				dist += max (0.0, (tile[i].r[k].x - p.x));
			}
			
			for (int k = 0; k < (int)tile[j].l.size (); k++)
			{
				int pos = upper_bound (tile[i].r.begin (), tile[i].r.end (), tile[j].l[k]) - tile[i].r.begin ();
				line a = PointsToLine (tile[i].r[pos], tile[i].r[pos - 1]);
				line b = PointsToLine (tile[j].l[k], point (tile[j].l[k].x - 12345678, tile[j].l[k].y));
				point p = Intersection (a, b);
				
				if (tile[j].l[k].x + dist < p.x) dist += p.x - (tile[j].l[k].x + dist);
			}
			
			AdjList[i].push_back (ii (j, (tile[j].R + dist) - (tile[i].R)));
		}
	}
	
	double res = INF;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 14; j++)
			for (int k = 0; k < (1 << 14); k++)
				dp[j][k] = -1;
		double aux = (tile[i].R - tile[i].L);
		res = min (res, aux + f (i, (1 << i)));
	}
	
	printf ("%.3lf\n", res);
}
