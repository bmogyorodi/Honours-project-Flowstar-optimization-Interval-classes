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
void AdditionTest(Interval* testdoubles,int size)
{
    auto duration= 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<size; i+=2)
    {
        
        testdoubles[i]+=testdoubles[i+1];
        
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    double average=duration/(double)(size/2);
    std::cout<<"Overall duration:"<<duration<<endl;
    std::cout <<"Additions: "<<average<<" msec/operation"<<endl;
}
void MultiplicationTest(Interval* testdoubles,int size)
{
    
    auto duration= 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<size; i+=2)
    {
        
        
        testdoubles[i]*=testdoubles[i+1];
        
        
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
   double average=duration/(double)(size/2);
    std::cout<<"Overall duration:"<<duration<<endl;
    std::cout <<"Multiplication: "<<average<<" msec/operation"<<endl;

    
}
void SubtracktionTest(Interval* testdoubles,int size)
{
    auto duration= 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<size; i+=2)
    {       
        testdoubles[i]-=testdoubles[i+1];       
    }
    auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout<<"Overall duration:"<<duration<<endl;
    double average=duration/(double)(size/2);

    std::cout <<"Subtraction: "<<average<<" msec/operation"<<endl;
}
void DivisionTest(Interval* testdoubles,int size)
{
    auto duration= 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<size; i+=2)
    {
        
        
        testdoubles[i]-=testdoubles[i+1];  
        
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout<<"Overall duration:"<<duration<<endl;
    double average=duration/(double)(size/2);

    std::cout <<"Divisions: "<<average<<" msec/operation"<<endl;
}
void SinTest(Interval* testdoubles,int size)
{
    auto duration= 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<size; i++)
    {
        
        
        
        testdoubles[i].sin_assign();
        
    }
    auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout<<"Overall duration:"<<duration<<endl;
    double average=duration/(double)(size);

    std::cout <<"Sines: "<<average<<" msec/operation"<<endl;
}
void CosTest(Interval* testdoubles,int size)
{
    auto duration= 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<size; i++)
    {
        
        
        
        testdoubles[i].cos_assign();
        
    }
    auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout<<"Overall duration:"<<duration<<endl;
    double average=duration/(double)(size);


    std::cout <<"Cosines: "<<average<<" msec/operation"<<endl;
}
double * CreateRandomnums(int size)
{
    double* testdata=new double[size];
    for(int i=0; i<size/2; i++)
    {
        testdata[i]=fRand(-100,100);
        testdata[i+size/2]=testdata[i]+fRand(0,100);
    }
    return testdata;

}
double* CreateDataforTrig(int size)
{
    double* testdata=new double[size];
    for(int i=0; i<size/2; i++)
    {
        testdata[i]=fRand(-100,100);
        testdata[i+size/2]=testdata[i]+fRand(0,stod(str_pi_up));
    }
    return testdata;
}
Interval * CreateIntArray(int size)
{
  Interval* intarray=new Interval[size];
  double temp;
  for(int i=0;i<size; i++)
  {
      temp=fRand(-100,100); 
      intarray[i]=Interval(temp,temp+fRand(0,100));
  }
  return intarray;
}
Interval* CreateIntforTrig(int size)
{
    Interval* intarray=new Interval[size];
  double temp;
  for(int i=0;i<size; i++)
  {
      temp=fRand(-100,100); 
      intarray[i]=Interval(temp,temp+fRand(0,stod(str_pi_up)));
  }
  return intarray;

}
void PrepareforDiv(Interval* integers, int size)
{
    for(int i=1; i<size;i+=2)
    {
        integers[i]+=100;
    }
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
    int size=numofRuns*2;
    Interval* intervals=CreateIntArray(size);
    AdditionTest(intervals,size);
    SubtracktionTest(intervals,size);
    MultiplicationTest(intervals,size);
    PrepareforDiv(intervals,size);   
    DivisionTest(intervals,size);
    intervals=CreateIntforTrig(numofRuns);
    SinTest(intervals,numofRuns);
    CosTest(intervals,numofRuns);
    
    

    
    return 0;
}