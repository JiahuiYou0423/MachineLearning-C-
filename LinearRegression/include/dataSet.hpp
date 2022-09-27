#ifndef _DATASET_H
#define _DATASET_H
#include <vector>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

class dataSet 
{
    private:
    int dataSize;
    
    std::vector<std::vector<double>> training_data;
    std::vector<std::vector<double>> test_data;
    double training_data_percent=0.8;
    double test_data_percent=0.2;
    public:
    dataSet();
    ~dataSet();
    std::vector<std::vector<double>> readingData;
    void readFromCSV(std::string path, int colNumber);
    void split_data();
    std::vector<std::vector<double>> get_training_data();
    std::vector<std::vector<double>> get_test_data();
    int get_data_size();
};





#endif