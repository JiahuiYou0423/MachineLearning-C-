#include "dataSet.hpp"
#include <vector>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
dataSet::dataSet()
{
    dataSize=0;
}
dataSet::~dataSet()
{}
void dataSet::readFromCSV(std::string path, int colNumber)
{
    std::ifstream ofs(path);
        if(!ofs.is_open())
    {
        std::cout<<"fail to open the file "<<path<<std::endl;
        exit(1);
    }
    
    std::string line;
    getline(ofs, line);
    while(getline(ofs, line))
    {
        std::string number;
        std::istringstream readstr(line); 
        std::vector<double> feature_vector;    
        for(int i=0; i< colNumber;i++)
        {
            getline(readstr, number, ',');
            feature_vector.push_back(atof(number.c_str()));
           
        }
         readingData.push_back(feature_vector);
        dataSize++;

    }
}

void dataSet::split_data()
{
    std::unordered_set <int> used_index;
    int count=0;
    int trainingSize=readingData.size()*training_data_percent;
    int testSize=readingData.size()*test_data_percent;
    while(count < trainingSize)
    {
        int rand_index=rand() % readingData.size();
        if(used_index.find(rand_index)==used_index.end())
        {
            training_data.push_back(readingData.at(rand_index));
            used_index.insert(rand_index);
            count++;
        }
    }
    count=0;
    while(count < testSize)
    {
        int rand_index=rand() % readingData.size();
        if(used_index.find(rand_index)==used_index.end())
        {
            test_data.push_back(readingData.at(rand_index));
            used_index.insert(rand_index);
            count++;
        }
    }
    std::cout<<"successfully split training data with size "<<trainingSize<<std::endl;
    std::cout<<"successfully split testdata with size "<<testSize<<std::endl;

}

std::vector<std::vector<double>> dataSet::get_training_data()
{
    return training_data;
}
std::vector<std::vector<double>> dataSet::get_test_data()
{
    return test_data;
}
int dataSet::get_data_size()
{
    return dataSize;
}
/*
int main()
{
    dataSet *ds=new dataSet;
     std::cout<<1;
    ds->readFromCSV("Salary_Data.csv",2);
    int datasize=ds->get_data_size();
    //test reading data
    for(std::vector<double> vec: ds->readingData)
    {
        for(double num:vec)
        {
            std::cout<<num<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"data size is "<<ds->get_data_size()<<std::endl;
    ds->split_data();
    

    return 0;
}
*/