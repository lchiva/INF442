#include <cmath>	// for pow, atan, should you need them
#include <iostream> // for cerr

#include <point.hpp>
#include <cloud.hpp>
#include <gaussian.hpp>

// TODO 2.1.2: implement volume, profile and guess_bandwidth
// HINTS: pi = std::atan(1) * 4.0, e^x is std::exp(x)
double gaussian::volume() const
{
	double pi = std::atan(1) * 4.0;
	int dimension = point::get_dim();
	return (std::pow(2 * pi, (dimension * 1.0) / 2));
}

double gaussian::profile(double t) const
{
	return std::exp(-t / 2);
}

void gaussian::guess_bandwidth()
{
	bandwidth = 1.06 * (data->standard_deviation() / std::pow(data->get_n(), 0.2));
}
