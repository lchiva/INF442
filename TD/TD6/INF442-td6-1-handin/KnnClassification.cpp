#include "KnnClassification.hpp"
#include <iostream>
#include <ANN/ANN.h>

KnnClassification::KnnClassification(int k, Dataset *dataset, int col_class)
    : Classification(dataset, col_class)
{
    // TODO Exercise 1
    m_k = k;
    int nbSample = dataset->getNbrSamples();
    int dimension = dataset->getDim();
    m_dataPts = annAllocPts(nbSample, dimension - 1);
    for (int i = 0; i < nbSample; i++)
    {
        std::vector<double> temps;
        for (int j = 0; j < dimension; j++)
        {
            if (j != col_class)
            {
                temps.push_back(dataset->getInstance(i)[j]);
            }
        }
        std::copy(temps.begin(), temps.end(), m_dataPts[i]);
    }
    m_kdTree = new ANNkd_tree(m_dataPts, nbSample, dimension - 1);
}

KnnClassification::~KnnClassification()
{
    // TODO Exercise 1
    delete m_kdTree;
    annDeallocPts(m_dataPts);
    annClose();
}

int KnnClassification::Estimate(const ANNpoint &x, double threshold) const
{
    // TODO Exercise 2
    double count = 0;

    ANNidxArray annIndx = new ANNidx[m_k];
    ANNdistArray dists = new ANNdist[m_k];
    m_kdTree->annkSearch(x, m_k, annIndx, dists, count);

    double *weight = new double[m_k];
    double estimatedValue = 0;
    double totalWeight = 0;
    int predicted_label = 0;

    for (int i = 0; i < m_k; i++)
    {
        weight[i] = 1.;
        totalWeight += weight[i];
    }

    for (int i = 0; i < m_k; i++)
    {
        estimatedValue += (weight[i] * m_dataset->getInstance(annIndx[i])[m_col_class]) / (totalWeight);
    }
    if (estimatedValue >= threshold)
    {
        predicted_label = 1;
    }
    else
    {
        predicted_label = 0;
    }
    return predicted_label;
}

int KnnClassification::getK() const
{
    return m_k;
}

ANNkd_tree *KnnClassification::getKdTree()
{
    return m_kdTree;
}
