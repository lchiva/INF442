#include <point.hpp>
#include <cloud.hpp>
#include <kernel.hpp>
#include <knn.hpp>

// TODO 2.2.1: implement density for knn kernel
knn::knn(cloud *data_, int k_, double V_) : kernel(data_), k(k_), V(V_) {}

double knn::density(point &p) const
{
    double density = 0.0;
    int nbOfPoint = data->get_n();
    density = k / (2 * nbOfPoint * V * data->k_dist_knn(p, k));
    return density;
}
double knn::volume() const
{
    return V;
}
