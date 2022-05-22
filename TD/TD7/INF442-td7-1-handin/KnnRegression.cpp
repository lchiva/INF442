
#include "KnnRegression.hpp"
#include <iostream>
#include <ANN/ANN.h>

KnnRegression::KnnRegression(int k, Dataset *dataset, int col_regr)
	: Regression(dataset, col_regr)
{
	m_k = k;
	// TODO Exercise 5
	int nbSample = dataset->GetNbrSamples();//number of sample
	int dimension = dataset->GetDim();//number of dimension
	m_dataPts = annAllocPts(nbSample, dimension - 1); //allocate points 
	for (int i = 0; i < nbSample; i++) //loop for allocate the ponts in m_dataPts[i]
	{
		std::vector<double> temps;
		for (int j = 0; j < dimension; j++)
		{
			if (j != m_col_regr)
			{
				temps.push_back(dataset->GetInstance(i)[j]);
			}
		}
		std::copy(temps.begin(), temps.end(), m_dataPts[i]);
	}
	m_kdTree = new ANNkd_tree(m_dataPts, nbSample, dimension - 1); // create a m_kdTree 
}

KnnRegression::~KnnRegression()
{
	// TODO Exercise 6 
	delete m_kdTree;
	annDeallocPts(m_dataPts);
	annClose();
}

double KnnRegression::Estimate(const Eigen::VectorXd &x) const
{
	assert(x.size() == m_dataset->GetDim() - 1);
	// TODO Exercise 5
	double regres_value = 0;
	double count = 0;
	ANNidxArray annIndx = new ANNidx[m_k];
	ANNdistArray dists = new ANNdist[m_k];
	double points[x.size()];
	for (int i = 0; i < x.size(); i++)
	{
		points[i] = x(i);
	}
	m_kdTree->annkSearch(points, m_k, annIndx, dists, count);
	for (int i = 0; i < m_k; i++)
	{
		regres_value = regres_value + m_dataset->GetInstance(annIndx[i])[m_col_regr];
	}
	return regres_value / m_k;
}

int KnnRegression::GetK() const
{
	return m_k;
}

ANNkd_tree *KnnRegression::GetKdTree() const
{
	return m_kdTree;
}
