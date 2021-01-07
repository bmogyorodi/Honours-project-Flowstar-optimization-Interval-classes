#include "Interval.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
//using namespace flow;
using namespace flowstar;

void printInterval(flowstar::Interval inter)
{
    //printLineNumber();
    std::cout<<"Low limit: "<<inter.inf()<<"\n";
    //printLineNumber();
    std::cout<<"Hi limit: "<<inter.sup()<<"\n";

}

Interval CreateIntervalfromDouble(double* doubles)
{
        return Interval(doubles[0],doubles[1]);
}
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
void AdditionTest(double* testdoubles,int size)
{
    auto duration= 0;
    for(int i=0; i<size; i+=4)
    {
        
        Interval a=Interval(testdoubles[i],testdoubles[i+1]);
        Interval b=Interval(testdoubles[i+2],testdoubles[i+3]);
        auto t1 = std::chrono::high_resolution_clock::now();
        a+=b;
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    }
    double average=duration/(double)(size/4);
    std::cout<<"Overall duration:"<<duration<<endl;
    std::cout <<"Additions: "<<average<<" msec/operation"<<endl;
}
void MultiplicationTest(double* testdoubles,int size)
{
    
    auto duration= 0;
    for(int i=0; i<size; i+=4)
    {
        
        Interval a=Interval(testdoubles[i],testdoubles[i+1]);
        Interval b=Interval(testdoubles[i+2],testdoubles[i+3]);
        auto t1 = std::chrono::high_resolution_clock::now();
        a*=b;
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        
    }
   double average=duration/(double)(size/4);
    std::cout<<"Overall duration:"<<duration<<endl;
    std::cout <<"Multiplication: "<<average<<" msec/operation"<<endl;

    
}
void SubtracktionTest(double* testdoubles,int size)
{
    auto duration= 0;
    for(int i=0; i<size; i+=4)
    {
        
        Interval a=Interval(testdoubles[i],testdoubles[i+1]);
        Interval b=Interval(testdoubles[i+2],testdoubles[i+3]);
        auto t1 = std::chrono::high_resolution_clock::now();
        a-=b;
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    }
    std::cout<<"Overall duration:"<<duration<<endl;
    double average=duration/(double)(size/4);

    std::cout <<"Subtraction: "<<average<<" msec/operation"<<endl;
}
void DivisionTest(double* testdoubles,int size)
{
    auto duration= 0;
    for(int i=0; i<size; i+=4)
    {
        
        Interval a=Interval(testdoubles[i],testdoubles[i+1]);
        Interval b=Interval(testdoubles[i+2]+100,testdoubles[i+3]+100);
        auto t1 = std::chrono::high_resolution_clock::now();
        a/=b;
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    }
    std::cout<<"Overall duration:"<<duration<<endl;
    double average=duration/(double)(size/4);

    std::cout <<"Divisions: "<<average<<" msec/operation"<<endl;
}
void SinTest(double* testdoubles,int size)
{
    auto duration= 0;
    for(int i=0; i<size; i+=2)
    {
        
        Interval a=Interval(testdoubles[i],testdoubles[i+1]);
        auto t1 = std::chrono::high_resolution_clock::now();
        a.sin_assign();
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    }
    std::cout<<"Overall duration:"<<duration<<endl;
    double average=duration/(double)(size/4);

    std::cout <<"Sines: "<<average<<" msec/operation"<<endl;
}
void CosTest(double* testdoubles,int size)
{
    auto duration= 0;
    for(int i=0; i<size; i+=2)
    {
        
        Interval a=Interval(testdoubles[i],testdoubles[i+1]);
        auto t1 = std::chrono::high_resolution_clock::now();
        a.cos_assign();
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    }
    
   std::cout<<"Overall duration:"<<duration<<endl;
   double average=duration/(double)(size/4);

    std::cout <<"Cosines: "<<average<<" msec/operation"<<endl;
}
double * CreateRandomnums(int size)
{
    double* testdata=new double[size*2];
    for(int i=0; i<size*2; i+=2)
    {
        testdata[i]=fRand(-100,100);
        testdata[i+1]=testdata[i]+fRand(0,100);
    }
    return testdata;

}
double* CreateDataforTrig(int size)
{
    double* testdata=new double[size];
    for(int i=0; i<size; i+=2)
    {
        testdata[i]=fRand(-100,100);
        testdata[i+1]=testdata[i]+fRand(0,stod(str_pi_up));
    }
    return testdata;
}

int main(int argc, char * argv[])
{
    int numofRuns=0;
    if(argc==1)
    {
       numofRuns=10000000;
    }
    else
    {
        try
        {
            numofRuns=stoi(argv[1]);
        }
        catch(const std::invalid_argument& e)
        {
            cout<<"Incorrect input!"<< "input:"<<argv[1]<<endl;
            cout<<"Default number of runs set!"<<endl;
            numofRuns=10000000;
        }
    }
    numofRuns*=2;
    double * testdata=CreateRandomnums(numofRuns);
    int size=numofRuns*2;
    AdditionTest(testdata,size);
    SubtracktionTest(testdata,size);
    MultiplicationTest(testdata,size);   
    DivisionTest(testdata,size);
    testdata=CreateDataforTrig(numofRuns);
    SinTest(testdata,numofRuns);
    CosTest(testdata,numofRuns);
    
    

    
    return 0;
}