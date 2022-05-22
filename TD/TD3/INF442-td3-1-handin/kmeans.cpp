#include <iostream>
#include <cassert>
#include <cmath>   // for sqrt, fabs
#include <cfloat>  // for DBL_MAX
#include <cstdlib> // for rand, srand
#include <ctime>   // for rand seed
#include <fstream>
#include <cstdio> // for EOF
#include <string>
#include <algorithm> // for count
#include <vector>

using std::rand;
using std::srand;
using std::time;

class point
{
public:
	static int d;
	double *coords;
	int label;
	point()
	{
		coords = new double[d];
		for (int i = 0; i < d; i++)
		{
			this->coords[i] = 0;
		}
	}
	~point()
	{
		free(coords);
		coords = NULL;
	}
	void set_label()
	{
		this->label = 0;
	}
	void print() const
	{
		for (int i = 0; i < d - 1; i++)
		{
			std::cout << coords[i] << "\t";
		}
		std::cout << coords[d] << "\n";
	}
	double squared_dist(const point &q) const
	{
		double distance = 0.0;
		for (int i = 0; i < d; i++)
		{
			distance += (q.coords[i] - this->coords[i]) * (q.coords[i] - this->coords[i]);
		}
		return distance;
	}
	double squared_dist(const point &q) const
	{
		double distance = 0.0;
		for (int i = 0; i < d; i++)
		{
			distance += (q.coords[i] - this->coords[i]) * (q.coords[i] - this->coords[i]);
		}
		return distance;
	}
};

int point::d;

class cloud
{
private:
	int d;
	int n; // number of data points
	int k;

	// maximum possible number of points
	int nmax;

	point *points;
	point *centers;

public:
	cloud(int _d, int _nmax, int _k)
	{
		d = _d;
		point::d = _d;
		n = 0;
		k = _k;

		nmax = _nmax;

		points = new point[nmax];
		centers = new point[k];

		srand(time(0));
	}

	~cloud()
	{
		delete[] centers;
		delete[] points;
	}

	void add_point(const point &p, int label)
	{
		for (int m = 0; m < d; m++)
		{
			points[n].coords[m] = p.coords[m];
		}

		points[n].label = label;

		n++;
	}

	int get_d() const
	{
		return d;
	}

	int get_n() const
	{
		return n;
	}

	int get_k() const
	{
		return k;
	}

	point &get_point(int i)
	{
		return points[i];
	}

	point &get_center(int j)
	{
		return centers[j];
	}

	void set_center(const point &p, int j)
	{
		for (int m = 0; m < d; m++)
			centers[j].coords[m] = p.coords[m];
	}

	double intracluster_variance() const
	{
		double result = 0.0;
		for (int i = 0; i < n; i++)
		{
			result += centers[points[i].label].squared_dist(points[i]);
		}
		return (1.0 / n) * result;
	}

	int set_voronoi_labels()
	{
		int count = 0;
		bool check = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (j != points[i].label)
				{
					if (centers[points[i].label].squared_dist(points[i]) > centers[j].squared_dist(points[i]))
					{
						points[i].label = j;
						check = true;
					}
					else if (centers[points[i].label].squared_dist(points[i]) == centers[j].squared_dist(points[i]))
					{
						if (points[i].label > j)
						{
							points[i].label = j;
							check = true;
						}
					}
				}
			}
			if (check)
			{
				count++;
				check = false;
			}
		}
		return count;
	}

	void set_centroid_centers()
	{
		point pts[k];
		int count = 0;
		for (int i = 0; i < k; i++)
		{
			count = 0;
			for (int j = 0; j < n; j++)
			{
				if (points[j].label == i)
				{
					count++;
					for (int m = 0; m < d; m++)
					{
						pts[i].coords[m] += points[j].coords[m];
					}
				}
			}
			if (count != 0)
			{
				for (int m = 0; m < d; m++)
				{
					pts[i].coords[m] = pts[i].coords[m] / count;
				}
				set_center(pts[i], i);
			}
		}
	}

	void init_random_partition()
	{
		for (int i = 0; i < n; i++)
		{
			points[i].label = rand() % k;
		}
		set_centroid_centers();
	}

	void lloyd()
	{
		set_voronoi_labels();
		set_centroid_centers();
	}

	void init_forgy()
	{
		int randomlist[n];
		for (int j = 0; j < n; j++)
		{
			randomlist[j] = j;
		}
		std::random_shuffle(randomlist, randomlist + n);
		for (int i = 0; i < k; i++)
		{
			set_center(points[randomlist[i]], i);
		}
	}
	void init_plusplus()
	{
		int random = rand() % n;
		set_center(points[random], 0);
		for (int i = 1; i < k; i++)
		{
		}
	}
};
