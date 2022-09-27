#include "gradientDescent.hpp"
gradientDescent::gradientDescent()
{
    learning_rate_big=0.01;
    learning_rate_small=0.002;
    maxIterator=100;
    criteria=0.0001;
    steps=0;
    coeff.first=0;
    coeff.second=0;
    dataSet *ds=new dataSet;

}
gradientDescent::gradientDescent(double learning_rate_big, double learning_rate_small, int maxIterator, double criteria)
{
    this->learning_rate_small=learning_rate_small;
    this->learning_rate_big=learning_rate_big;
    this->maxIterator=maxIterator;
    this->criteria=criteria;
    steps=0;
    coeff.first=0;
    coeff.second=0;
    dataSet *ds=new dataSet;

}
gradientDescent::~gradientDescent()
{}
void gradientDescent::update_coeff()
{
    int dataSize=ds->get_data_size();  //first is slop, second is intersept
    double sum1=0;
    double sum2=0;
    if(abs(cost) >= 1)
    {
        for(int i=0; i<dataSize;i++)
        {
            sum1+=(ypred[i]-y[i])*x[i];
            sum2+=ypred[i]-y[i];
        }
        coeff.first=coeff.first-(learning_rate_big)/dataSize*sum1;
        coeff.second=coeff.second-(learning_rate_big)/dataSize*sum2;

    }
    else 
    {
         for(int i=0; i<dataSize;i++)
        {
            sum1+=(ypred[i]-y[i])*x[i];
            sum2+=ypred[i]-y[i];
        }
        coeff.first=coeff.first-(learning_rate_small)/dataSize*sum1;
        coeff.second=coeff.second-(learning_rate_small)/dataSize*sum2;

    }
    
}
double gradientDescent::get_slope()
{
    return coeff.first;
}
double gradientDescent::get_intersept()
{
    return coeff.second;
}
double gradientDescent::get_cost()
{
    return cost;
}
double gradientDescent::get_criteria()
{
    return criteria;
}
double gradientDescent::calculate_cost()
{
    int dataSize=ds->get_data_size();
    double sum=0;
    for(int i=0; i<dataSize;i++)
    {
        sum+=pow((ypred[i]-y[i]),2);
    }
    cost=1/(2*sum);
    return cost;
}
void gradientDescent::initializeXY()
{
    ds=new dataSet;
    ds->readFromCSV("Salary_Data.csv",2);
    //std::vector<std::vector<double>> dataset=ds->readingdata;
    int dataSize=ds->get_data_size();
    for(int i=0; i<dataSize; i++)
    {
        x.push_back(ds->readingData.at(i).at(0));
        y.push_back(ds->readingData.at(i).at(1));
    }
}
double gradientDescent::performance()
{
    int dataSize=ds->get_data_size();
    double Sres=0;
    double Stol=0;
    double sumOfy=0;
    for(int i=0; i<dataSize; i++)
    {
        sumOfy+=y[i];

    }
    double mean=sumOfy/dataSize;
    for(int i=0; i<dataSize; i++)
    {
        Sres+=pow((ypred[i]-y[i]),2);
        Stol+=pow((y[i]-mean),2);

    }
    return 1-Sres/Stol;

}
std::vector<double> gradientDescent::predict_y()
{
    int dataSize=ds->get_data_size();
    ypred.resize(dataSize,0);
    for(int i=0; i<dataSize; i++)
    {
        ypred[i]=x[i]*coeff.first+coeff.second;  //first is slop, second is intersept

    }
    return ypred;

}

int main()
{
    gradientDescent *gd=new gradientDescent();
    gd->initializeXY();
    std::cout<<"finish initalize x y"<<std::endl;
    while(gd->get_cost()<=gd->get_criteria())
    {
        gd->predict_y();
        gd->calculate_cost();
        gd->update_coeff();
        gd->steps++;
        if(gd->steps % gd->maxIterator ==0)
        {
            break;
        }
    }
    gd->predict_y();
    double perf=gd->performance();
    std::cout<<"slop is "<<gd->get_slope()<<std::endl;
    std::cout<<"intersect if "<<gd->get_intersept()<<std::endl;
    std::cout<<"peformance is "<<perf<<std::endl;

}