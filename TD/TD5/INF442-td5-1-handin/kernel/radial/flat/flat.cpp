#include <cmath> // for pow, atan, should you need them

#include <point.hpp>
#include <flat.hpp>

// TODO 2.1.1: implement volume and profile
// HINT: pi = std::atan(1) * 4.0
double flat::volume() const
{
	double pi = std::atan(1) * 4.0;
	int dimension = point::get_dim();
	return (std::pow(pi, (dimension * 1.0) / 2)) / std::tgamma((dimension * 1.0) / 2 + 1);
}

double flat::profile(double t) const
{
	if (t <= 1)
	{
		return 1.0;
	}
	else
	{
		return 0.0;
	}
}
