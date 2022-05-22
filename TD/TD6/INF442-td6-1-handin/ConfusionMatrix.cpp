#include "ConfusionMatrix.hpp"
#include <iostream>

using namespace std;

ConfusionMatrix::ConfusionMatrix()
{
    // TODO Exercise 3
    // Populate 2x2 matrix with 0s
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            m_confusion_matrix[i][j] = 0;
        }
    }
}

ConfusionMatrix::~ConfusionMatrix()
{
    // Attribute m_confusion_matrix is deleted automatically
}

void ConfusionMatrix::AddPrediction(int true_label, int predicted_label)
{
    // TODO Exercise 3
    if (true_label == 0 && predicted_label == 1)
    {
        m_confusion_matrix[0][1]++;
    }
    else if (true_label == 1 && predicted_label == 0)
    {
        m_confusion_matrix[1][0]++;
    }
    else if (true_label == 0 && predicted_label == 0)
    {
        m_confusion_matrix[0][0]++;
    }
    else
    {
        m_confusion_matrix[1][1]++;
    }
}

void ConfusionMatrix::PrintEvaluation() const
{
    // Prints the confusion matrix
    cout << "\t\tPredicted\n";
    cout << "\t\t0\t1\n";
    cout << "Actual\t0\t"
         << GetTN() << "\t"
         << GetFP() << endl;
    cout << "\t1\t"
         << GetFN() << "\t"
         << GetTP() << endl
         << endl;
    // Prints the estimators
    cout << "Error rate\t\t"
         << error_rate() << endl;
    cout << "False alarm rate\t"
         << false_alarm_rate() << endl;
    cout << "Detection rate\t\t"
         << detection_rate() << endl;
    cout << "F-score\t\t\t"
         << f_score() << endl;
    cout << "Precision\t\t"
         << precision() << endl;
}

int ConfusionMatrix::GetTP() const
{
    return m_confusion_matrix[1][1];
}

int ConfusionMatrix::GetTN() const
{
    return m_confusion_matrix[0][0];
}

int ConfusionMatrix::GetFP() const
{
    return m_confusion_matrix[0][1];
}

int ConfusionMatrix::GetFN() const
{
    return m_confusion_matrix[1][0];
}

double ConfusionMatrix::f_score() const
{
    // TODO Exercise 3
    double result;
    result = (2 * precision() * detection_rate()) * 1.0 / (precision() + detection_rate());
    return result;
}

double ConfusionMatrix::precision() const
{
    // TODO Exercise 3
    double result;
    result = GetTP() * 1.0 / (GetTP() + GetFP());
    return result;
}

double ConfusionMatrix::error_rate() const
{
    // TODO Exercise 3
    double result;
    result = (GetFP() + GetFN()) * 1.0 / (GetTP() + GetFN() + GetFP() + GetTN());
    return result;
}

double ConfusionMatrix::detection_rate() const
{
    // TODO Exercise 3
    double result;
    result = (GetTP() * 1.0) / (GetTP() + GetFN());
    return result;
}

double ConfusionMatrix::false_alarm_rate() const
{
    // TODO Exercise 3
    double result;
    result = (GetFP() * 1.0) / (GetFP() + GetTN());
    return result;
}
