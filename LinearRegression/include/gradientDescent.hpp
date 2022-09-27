#ifndef _LINEAR_H
#define _LINEAR_H
#include <vector>
#include <cmath>
#include <iostream>
#include <utility>
#include "dataSet.hpp"

class gradientDescent{
private:
dataSet *ds;
std::pair <double, double> coeff;//first is slop, second is intersept
std::vector<double> x;
std::vector<double> y;
std::vector<double> ypred;

double learning_rate_small;
double learning_rate_big;
double cost;

double criteria;
public:
gradientDescent();
gradientDescent(double learning_rate_big, double learning_rate_small, int maxIterator, double criteria);
~gradientDescent();
void update_coeff();
double calculate_cost();
void initializeXY();
double performance();
double get_slope();
double get_intersept();
double get_cost();
double get_criteria();
int steps;
int maxIterator;
std::vector<double> predict_y();



};



#endif