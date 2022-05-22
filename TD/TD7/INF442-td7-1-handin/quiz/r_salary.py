#!/usr/bin/env python3

import pandas as pd
import numpy as np
import math
from sklearn.linear_model import LinearRegression
from sklearn import metrics


train_fname = "../csv/salary_full_train.csv"
test_fname = "../csv/salary_full_test.csv"

train_dataset = pd.read_csv(train_fname, header=0)
print(f'Shape of the train data {train_dataset.shape}')
# print the first 5 rows of the dataset
print(train_dataset.head(5))
print('\n\n')
test_dataset = pd.read_csv(test_fname, header=0)
print(f'Shape of the test data {test_dataset.shape}')

# The column indices for X. We use the columns x_col1, xcol1+1, ..., xcol2 -1
x_col1 = 3
x_col2 = 4

# the column index for y
y_col = 0

X = train_dataset.iloc[:,x_col1:x_col2]
y = train_dataset.iloc[:,y_col]


# print(X.head(5))
# print(y.head(5))

regressor = LinearRegression()
regressor.fit(X, y)

print(f'\tintercept = {regressor.intercept_}')
print(f'\tcoefficient = {regressor.coef_}')


# the 0-th column is the salary
# the 1-st column is the sex
tX = test_dataset.iloc[:,x_col1:x_col2]
ty = test_dataset.iloc[:,y_col]

y_pred = regressor.predict(tX)

print("\n")
y_test = np.array(ty);
X_test = np.array(tX)

for a, b in zip(y_test, y_pred):
    print(f'  true value: {a} \t predicted value: {b}')

print('\n\n')
print('Mean Absolute Error:', metrics.mean_absolute_error(y_test, y_pred))
print('Mean Squared Error:', metrics.mean_squared_error(y_test, y_pred))
print('Root Mean Squared Error:', np.sqrt(metrics.mean_squared_error(y_test, y_pred)))
print('\n')
