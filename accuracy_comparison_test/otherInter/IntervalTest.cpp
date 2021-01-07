#include "Interval.h"
#include <iostream>
using namespace std;
//using namespace flow;
using namespace flowstar;
static int rownumber=0;
FILE * fp=fopen("outputs/opdouble.txt","w");
FILE* fpstr=fopen("outputs/opdoublestr.txt","w");
FILE* fpmsg=fopen("outputs/opdoublemsg.txt","w");
void printLineNumber()
{
    rownumber++;
    std::cout<<rownumber<<". ";
}
void printInterval(flowstar::Interval inter)
{
    printLineNumber();
    std::cout<<"Low limit: "<<inter.inf()<<"\n";
    printLineNumber();
    std::cout<<"Hi limit: "<<inter.sup()<<"\n";
}

void printInterval(Real real)
{
    printLineNumber();
    std::cout<<"value of real: "<<real.getValue_RNDU()<<"\n";
}
void printMessage(string message)
{
    printLineNumber();
    std::cout<<".........."<<message<<".........."<<endl;
}

string toBinary(int n)
{
    string sign;
    string answer;
    if(n<0)
    {
        sign="1";
        n*=-1;
    }
    else
    {
        sign="0";
    }
    while(n!=0)
    {
        if(n%2==0)
        {
            answer="0"+answer;
        }
        else
        {
            answer="1"+answer;
        }
        n/=2;
    }
    answer=sign+answer;
    return answer;

}
string toBinary(double n) 
{ 
    // Check if the number is Between 0 to 1 or Not 
    string answer; 
    if (n >= 1 || n <= 0) 
         {answer=toBinary((int)n);}
    
    n-=(int)n;
    double frac = 0.5; 
    answer.append("."); 
  
    // Setting a limit on length: 55 characters.          
    while (n > 0) 
    { 
          
        //Setting a limit on length: 55 characters      
        if (answer.length() >= 65) 
                return "ERROR"; 
  
            // Multiply n by 2 to check it 1 or 0 
            double b = n * 2; 
            if (b >= 1) 
            { 
                answer.append("1"); 
                n = b - 1; 
            } 
            else
            { 
                answer.append("0"); 
                n = b; 
            }
             
        } 
        return answer; 
} 
void BitPrint(flowstar::Interval inter)
{
    inter.dump(fp);
    fputs("\n",fp);
    string result;
    inter.toString(result);
    fputs(result.c_str(),fpstr);
    fputs("\n",fpstr);
    inter.output(fpmsg,"message1","message2");
    fputs("\n",fpmsg);
    printLineNumber();
    printf("Low limit: %a\n",inter.inf());
    //std::cout<<"Low limit: "<< inter.inf())<<"\n";
    printLineNumber();
    //std::cout<<"Hi limit: "<<std::hex<<inter.sup()<<"\n";
    printf("Hi limit: %a\n",inter.sup());
}
void BitPrint(double d)
{
    printLineNumber();
    //std::cout<<"Double to binary: "<<toBinary(d)<<endl;
    printf("Double to hex: %a\n",d);
}
Interval CreateIntervalfromDouble(double* doubles,int i,int j)
{
        Interval a=Interval(min(doubles[i],doubles[j]),max(doubles[i],doubles[j]));
        return a;
}
int main(int argc, char * argv[])
{
    //Firstly reading in 10 double to create the program
    //if input has less than 10 numbers or incorrect inputs, we fill out the double array with PI divided by different doubles
    double mod=1.0;
    double  doubles [10];
    for(int i=1; i<argc; i++)
    {
        try{
           
            doubles[i-1]=stod(argv[i]);
        }
        catch(const std::invalid_argument& e)
        {
            cout<<"Incorrect input!"<< "input:"<<i<<endl;
            doubles[i-1]=M_PI/mod;
            mod++;
        }
        
    }
    for(int i=argc-1; i<10; i++)
    {
        doubles[i]=M_PI/mod;
        mod++;
    }
    printMessage("Testing Interval intializer functions");
    Interval a=Interval();
    Interval b=CreateIntervalfromDouble(doubles,1,2);
    Interval c=Interval(doubles[5]);
    Interval d=CreateIntervalfromDouble(doubles,3,5);
    Interval e=Interval(Real(doubles[8]));
    BitPrint(a);
    BitPrint(b);
    BitPrint(c);
    BitPrint(d);
    BitPrint(e);
     if(a.isZero())
    {
       std::cout<< "a is zero\n";
    }
    if(!b.isZero())
    {
        std::cout<<"b is not zero\n";
    }
    printMessage("Testing Functions related to setters, plus split function");
    a=Interval(0);
    a.set(min(doubles[1],doubles[8]),max(doubles[1],doubles[8]));
    BitPrint(a);
    a.setInf(b);
    BitPrint(a);
    a.setSup(e);
    BitPrint(a);
    a=CreateIntervalfromDouble(doubles,5,9);
    BitPrint(a);
    a.split(b,d);
    BitPrint(b);
    BitPrint(d);
    printMessage("Testing functions related to width, radius, midpoint etc.");
    b=CreateIntervalfromDouble(doubles,3,8);
    BitPrint(b);
    b.bloat(doubles[0]);
    BitPrint(b);
    BitPrint(b.width());
    Real r;
    Real r2;
    b.toCenterForm(r,r2);
    std::cout<<"Centre: " <<toBinary(r.getValue_RNDU()) << "\n";
    std:: cout<<"Radius: " << toBinary(r2.getValue_RNDU())<<"\n";
    BitPrint(b.mag());
    BitPrint(b);
    b.remove_midpoint(a);
    BitPrint(b);
    BitPrint(a);
    printMessage("Interval arithmatic test");
    a=CreateIntervalfromDouble(doubles,0,9);
    b=CreateIntervalfromDouble(doubles,1,8);
    c=CreateIntervalfromDouble(doubles,2,7);
    d=CreateIntervalfromDouble(doubles,3,6);
    e=CreateIntervalfromDouble(doubles,4,5);
    BitPrint(a);
    BitPrint(b);
    BitPrint(c);
    BitPrint(d);
    BitPrint(e);
    printMessage("Addition:");
    a+=5;
    BitPrint(a);
    a=a+d;
    BitPrint(a);
    printMessage("Subtraction:");
    b-=3.145424;
    BitPrint(b);
    b=b-e;
    BitPrint(b);
    printMessage("Multiplication:");
    c*=1.11476;
    BitPrint(c);
    c=c*d;
    BitPrint(c);
    printMessage("Division:");
    d/=2.12;
    BitPrint(d);
    b=CreateIntervalfromDouble(doubles,1,8);
    b+=100;
    BitPrint(b);
    d=d/b;
    BitPrint(d);
    printMessage("Sqrt, inverse, reciprocal,pow, sin, cosine test");
    a=CreateIntervalfromDouble(doubles,0,9);
    b=CreateIntervalfromDouble(doubles,1,8);
    c=CreateIntervalfromDouble(doubles,2,7);
    d=CreateIntervalfromDouble(doubles,3,6);
    e=CreateIntervalfromDouble(doubles,4,5);
    a.abs_assign();
    BitPrint(a);
    a.sqrt_assign();
    BitPrint(a);
    b.inv_assign();
    BitPrint(b);
    c+=100;
    c.rec_assign();
    BitPrint(c);
    d.pow_assign(4);
    BitPrint(d);
    e.pow_assign(3);
    BitPrint(e);
    printMessage("Sin test");
    b=CreateIntervalfromDouble(doubles,4,6);
    b/=65;
    b.sin_assign();
    BitPrint(b);
    printMessage("Cosine test");
    d=CreateIntervalfromDouble(doubles,8,3);
    d/=65;
    d.cos_assign();
    BitPrint(d);
    fclose(fp);
    fclose(fpmsg);
    fclose(fpstr);







}