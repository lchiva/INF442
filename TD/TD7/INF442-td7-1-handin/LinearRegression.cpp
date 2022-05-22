#include "LinearRegression.hpp"
#include "Dataset.hpp"
#include "Regression.hpp"
#include <iostream>
#include <cassert>

LinearRegression::LinearRegression(Dataset *dataset, int col_regr)
	: Regression(dataset, col_regr)
{
	m_beta = NULL;
	SetCoefficients();
}

LinearRegression::~LinearRegression()
{
	if (m_beta != NULL)
	{
		m_beta->resize(0);
		delete m_beta;
	}
}

Eigen::MatrixXd LinearRegression::ConstructMatrix()
{
	// TODO Exercise 1
	// replace this command with what you compute as a matrix X
	int n = m_dataset->GetNbrSamples();
	int d = m_dataset->GetDim();
	Eigen::MatrixXd matrixX(n, d);
	for (int i = 0; i < n; i++)
	{
		matrixX(i, 0) = 1;
		std::vector<double> temps;
		for (int j = 0; j < d; j++)
		{
			if (j != m_col_regr)
			{
				temps.push_back(m_dataset->GetInstance(i)[j]);
			}
		}
		for (int k = 1; k < d; k++)
		{
			matrixX(i, k) = temps[k - 1];
		}
	}
	return matrixX;
}

Eigen::VectorXd LinearRegression::ConstructY()
{
	// TODO Exercise 1
	int n = m_dataset->GetNbrSamples();
	Eigen::VectorXd vectorY(n);
	vectorY.setZero();
	for (int i = 0; i < m_dataset->GetNbrSamples(); i++)
	{
		vectorY(i) = m_dataset->GetInstance(i)[m_col_regr];
	}
	// replace this command with what you compute as a vector y.
	return vectorY;
}

void LinearRegression::SetCoefficients()
{
	// TODO Exercise 2
	int d = m_dataset->GetDim();
	int n = m_dataset->GetNbrSamples();

	Eigen::MatrixXd X(n, d);
	X = ConstructMatrix();
	Eigen::VectorXd Y(n);
	Y = ConstructY();
	// X^TX beta = X^T y
	m_beta = new Eigen::VectorXd(d);
	*m_beta = (X.transpose() * X).fullPivHouseholderQr().solve(X.transpose() * Y); //fullPivHouseholderQr() is faster than llt() 
}
const Eigen::VectorXd *LinearRegression::GetCoefficients() const
{
	if (!m_beta)
	{
		std::cout << "Coefficients have not been allocated." << std::endl;
		return NULL;
	}
	return m_beta;
}

void LinearRegression::ShowCoefficients() const
{
	if (!m_beta)
	{
		std::cout << "Coefficients have not been allocated." << std::endl;
		return;
	}

	if (m_beta->size() != m_dataset->GetDim())
	{ // ( beta_0 beta_1 ... beta_{d} )
		std::cout << "Warning, unexpected size of coefficients vector: " << m_beta->size() << std::endl;
	}

	std::cout << "beta = (";
	for (int i = 0; i < m_beta->size(); i++)
	{
		std::cout << " " << (*m_beta)[i];
	}
	std::cout << " )" << std::endl;
}

void LinearRegression::PrintRawCoefficients() const
{
	std::cout << "{ ";
	for (int i = 0; i < m_beta->size() - 1; i++)
	{
		std::cout << (*m_beta)[i] << ", ";
	}
	std::cout << (*m_beta)[m_beta->size() - 1];
	std::cout << " }" << std::endl;
}

void LinearRegression::SumsOfSquares(Dataset *dataset, double &ess, double &rss, double &tss) const
{
	assert(dataset->GetDim() == m_dataset->GetDim());
	// TODO Exercise 4
	int d = dataset->GetDim();
	int m = dataset->GetNbrSamples();

	// vector coefficient
	Eigen::VectorXd coef_regression(m);
	for (int i = 0; i < m; i++)
	{
		coef_regression(i) = dataset->GetInstance(i)[m_col_regr];
	}
	// matrix X
	Eigen::MatrixXd matrix(m, d - 1);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < d - 1; j++)
		{
			matrix(i, j) = dataset->GetInstance(i)[j];
		}
	}
	// predictor
	Eigen::VectorXd predictor(m);
	// coefficient
	Eigen::VectorXd coef(d);
	coef = *m_beta;
	// coefficient without beta_0;
	Eigen::VectorXd coef_without_beta0(d - 1);
	for (int i = 0; i < d - 1; i++)
	{
		coef_without_beta0(i) = coef(i + 1);
	}
	// calculate predictor predictor = \beta_0*Id + X\beta
	for (int i = 0; i < m; i++)
	{
		predictor(i) = (matrix * coef_without_beta0)(i) + coef(0);
	}

	// ESS RSS TSS
	double ESS = 0;
	double RSS = 0;
	double TSS = 0;

	double sum_Y = 0;
	for (int i = 0; i < m; i++)
	{
		sum_Y = sum_Y + coef_regression(i);
	}
	double Y_bar = sum_Y / m;
	for (int i = 0; i < m; i++)
	{
		TSS = TSS + (coef_regression(i) - Y_bar) * (coef_regression(i) - Y_bar);
		Eigen::VectorXd x(d - 1);
		for (int j = 0; j < d - 1; j++)
		{
			x(j) = dataset->GetInstance(i)[j];
		}
		ESS = ESS + (Estimate(x) - Y_bar) * (Estimate(x) - Y_bar);
		RSS = RSS + (Estimate(x) - coef_regression(i)) * (Estimate(x) - coef_regression(i));
	}
	ess = ESS;
	rss = RSS;
	tss = TSS;
}

double LinearRegression::Estimate(const Eigen::VectorXd &x) const
{
	// TODO Exercise 3
	double Y = 0;
	int d = m_dataset->GetDim();
	Eigen::RowVectorXd row(d);
	row(0) = 1;
	for (int i = 1; i < d; i++)
	{
		row(i) = x(i - 1);
	}
	Y = row * *m_beta;
	return Y;
}
