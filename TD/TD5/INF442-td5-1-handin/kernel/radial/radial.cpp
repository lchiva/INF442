#include <cmath> // for pow, should you need it

#include <point.hpp>
#include <cloud.hpp>
#include <radial.hpp>

// TODO 2.1: density and radial constructor
// Use profile and volume... although it will only be implemented in the "sisters" classes
// Use kernel's constructor

double radial::density(point &p) const
{
	double sum = 0.0;
	double constant = 0.0;
	int nbOfPoint = data->get_n();
	constant = 1.0 / (volume() * nbOfPoint * std::pow(bandwidth, p.get_dim()));
	for (int i = 0; i < nbOfPoint; i++)
	{
		sum = sum + profile(((p.dist(data->get_point(i))) * (p.dist(data->get_point(i)))) / std::pow(bandwidth, 2.0));
	}
	return constant * sum;
}

radial::radial(cloud *data_, double bandwidth_) : kernel(data_)
{
	bandwidth = bandwidth_;
}
