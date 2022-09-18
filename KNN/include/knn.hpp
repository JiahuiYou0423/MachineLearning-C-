#ifndef _KNN_H
#define _KNN_H
#include <vector>
#include "../include/data.hpp"
class knn 
{
    int k;
    std::vector<data *> *neighbors;//save the nearest neighbor for a given quary point under 0-k
    std::vector<data *> *training_data;
    std::vector<data *> *test_data;
    std::vector<data *> *validation_data;
    public:
    knn(int k);
    ~knn();
    knn();
    void find_knearest(data * query_point);
    void set_training_data(std::vector<data *> *vect);
    void set_test_data(std::vector<data *> *vect);
    void set_validation_data(std::vector<data *> *vect);
    void set_k(int val);

    int predict();
    double calculate_distance(data * query_point, data * input);
    double validate_performance();
    double test_performance();

};

#endif