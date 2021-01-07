#include "Interval.h"
#include <iostream>
#include <chrono>
using namespace std;
#include<emmintrin.h>
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
void AdditionTest(int numofRuns)
{
    double* first=new double[2];
    double* second=new double[2];
    auto duration= 0;
    for(int i=0; i<numofRuns; i++)
    {
        
        first[0]=fRand(-100,100);
        first[1]=first[0]+fRand(0,100);
        second[0]=fRand(-100,100);
        second[1]=second[0]+fRand(0,100);
        Interval a=CreateIntervalfromDouble(first);
        Interval b=CreateIntervalfromDouble(second);
        auto t1 = std::chrono::high_resolution_clock::now();
        a+=b;
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    }
    double average=duration/(double)numofRuns;

    std::cout <<"Additions: "<<average<<" operation/msec"<<endl;
}
void MultiplicationTest(int numofRuns)
{
    double* first=new double[2];
    double* second=new double[2];
    auto duration= 0;
    for(int i=0; i<numofRuns; i++)
    {
        
        first[0]=fRand(-100,100);
        first[1]=first[0]+fRand(0,100);
        second[0]=fRand(-100,100);
        second[1]=second[0]+fRand(0,100);
        Interval a=CreateIntervalfromDouble(first);
        Interval b=CreateIntervalfromDouble(second);
        auto t1 = std::chrono::high_resolution_clock::now();
        a*=b;
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        
    }
   double average=duration/(double)numofRuns;

    std::cout <<"Multiplication: "<<average<<" operation/msec"<<endl;

    
}
void SubtracktionTest(int numofRuns)
{
    double* first=new double[2];
    double* second=new double[2];
    auto duration= 0;
    for(int i=0; i<numofRuns; i++)
    {
        
        first[0]=fRand(-100,100);
        first[1]=first[0]+fRand(0,100);
        second[0]=fRand(-100,100);
        second[1]=second[0]+fRand(0,100);
        Interval a=CreateIntervalfromDouble(first);
        Interval b=CreateIntervalfromDouble(second);
        auto t1 = std::chrono::high_resolution_clock::now();
        a-=b;
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    }

    double average=duration/(double)numofRuns;

    std::cout <<"Subtraction: "<<average<<" operation/msec"<<endl;
}
void DivisionTest(int numofRuns)
{
    double* first=new double[2];
    double* second=new double[2];
    auto duration= 0;
    for(int i=0; i<numofRuns; i++)
    {
        
        first[0]=fRand(-100,100);
        first[1]=first[0]+fRand(0,100);
        second[0]=fRand(0,100);
        second[1]=second[0]+fRand(0,100);
        Interval a=CreateIntervalfromDouble(first);
        Interval b=CreateIntervalfromDouble(second);
        auto t1 = std::chrono::high_resolution_clock::now();
        a/=b;
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    }

    double average=duration/(double)numofRuns;

    std::cout <<"Divisions: "<<average<<" operation/msec"<<endl;
}
void SinTest(int numofRuns)
{
    double* first=new double[2];
    double* second=new double[2];
    auto duration= 0;
    for(int i=0; i<numofRuns; i++)
    {
        
        first[0]=fRand(-100,100);
        first[1]=first[0]+fRand(0,stod(str_pi_up));
        Interval a=CreateIntervalfromDouble(first);
        auto t1 = std::chrono::high_resolution_clock::now();
        a.sin_assign();
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    }

    double average=duration/(double)numofRuns;

    std::cout <<"Sines: "<<average<<" operation/msec"<<endl;
}
void CosTest(int numofRuns)
{
    double* first=new double[2];
    double* second=new double[2];
    auto duration= 0;
    for(int i=0; i<numofRuns; i++)
    {
        
        first[0]=fRand(-100,100);
        first[1]=first[0]+fRand(0,stod(str_pi_up));
        Interval a=CreateIntervalfromDouble(first);
        auto t1 = std::chrono::high_resolution_clock::now();
        a.cos_assign();
        auto t2 = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    }
    

   double average=duration/(double)numofRuns;

    std::cout <<"Cosines: "<<average<<" operation/msec"<<endl;
}
void RoundingModeSwitchTest(int numofRuns)
{
    auto duration=0;
    auto t1=std::chrono::high_resolution_clock::now();
    flowstar::SwitchTest(numofRuns);
    auto t2=std::chrono::high_resolution_clock::now();
    duration=std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    double average=duration/(double)numofRuns;
    std::cout<<"Average Switch time: "<<duration<<std::endl;
}
void NoSwitchComparisonTest(int numofRuns)
{
    auto duration=0;
    auto t1=std::chrono::high_resolution_clock::now();
    flowstar::NoSwitchTest(numofRuns);
    auto t2=std::chrono::high_resolution_clock::now();
    duration=std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    double average=duration/(double)numofRuns;
    std::cout<<"Average Switch time: "<<duration<<std::endl;
}
void TakingOppositeTest(int numofRuns,double* testdata)
{
    auto duration=0;
    auto t1=std::chrono::high_resolution_clock::now();
    double holder;
    for(int i=0; i<numofRuns; i++)
    {
         holder=-testdata[i];
    }
    auto t2=std::chrono::high_resolution_clock::now();
    duration=std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    double average=duration/(double)numofRuns;
    std::cout<<"Average taking opposite time: "<<duration<<std::endl;
}
void SSETesting(int numofRuns,double*testdata)
{
    auto duration=0;
    auto t1=std::chrono::high_resolution_clock::now();
    __m128d holder;
    for(int i=0; i<numofRuns*2; i+=2)
    {
         holder=_mm_set_pd(testdata[i],testdata[i+1]);
    }
    auto t2=std::chrono::high_resolution_clock::now();
    duration=std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    double average=duration/(double)numofRuns;
    std::cout<<"Average time creating SSe register: "<<duration<<std::endl;

}
void ShuffleTesting(int numofRuns,double*testdata)
{
    auto duration=0;
    auto t1=std::chrono::high_resolution_clock::now();
    __m128d holder;
    for(int i=0; i<numofRuns*2; i+=2)
    {
         holder=_mm_set_pd(testdata[i],testdata[i+1]);
         holder=_mm_shuffle_pd(holder,holder,1);
    }
    auto t2=std::chrono::high_resolution_clock::now();
    duration=std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    double average=duration/(double)numofRuns;
    std::cout<<"Average time creating and shuffling SSe register: "<<duration<<std::endl;
}
void SSEcomparisontest(int numofRuns,double*testdata)
{
     auto duration=0;
    __m128d sum;
    auto t1=std::chrono::high_resolution_clock::now();
    for(int i=0; i<numofRuns*2; i+=4)
    {
         sum=_mm_add_pd(_mm_set_pd(testdata[i],testdata[i+1]),_mm_set_pd(testdata[i+2],testdata[i+3]));
    }
    auto t2=std::chrono::high_resolution_clock::now();
    duration=std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    double average=duration/(double)numofRuns;
    std::cout<<"Average time of adding two registers: "<<duration<<std::endl;
     t1=std::chrono::high_resolution_clock::now();
    double temp1;
    double temp2;
    for(int i=0; i<numofRuns*2; i+=4)
    {
         temp1=testdata[i]+testdata[i+2];
         temp2=testdata[i+1]+testdata[i+3];
    }
     t2=std::chrono::high_resolution_clock::now();
    duration=std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    average=duration/(double)numofRuns;
    std::cout<<"Average time of adding two numbers: "<<duration<<std::endl;


}
double * CreateRandomnums(int size)
{
    double* testdata=new double[size];
    for(int i=0; i<size; i++)
    {
        testdata[i]=fRand(-100,100);
        testdata[i+1]=testdata[i]+fRand(0,100);
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
    if(false){
    AdditionTest(numofRuns);
    SubtracktionTest(numofRuns);
    MultiplicationTest(numofRuns);   
    DivisionTest(numofRuns);
    SinTest(numofRuns);
    CosTest(numofRuns);
    cout<<"Number of switches: "<<flowstar::NumofSwitches();}
    RoundingModeSwitchTest(numofRuns);
    NoSwitchComparisonTest(numofRuns);
    double* testdata=CreateRandomnums(numofRuns);
    TakingOppositeTest(numofRuns,testdata);
    double* sse_test=CreateRandomnums(numofRuns*2);
    SSETesting(numofRuns,sse_test);
    ShuffleTesting(numofRuns,sse_test);
    SSEcomparisontest(numofRuns,sse_test);
    
    

    
    return 0;
}