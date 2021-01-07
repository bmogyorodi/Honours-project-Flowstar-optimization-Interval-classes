
#include "Interval.h"
//#include "myInterval.h"
#include <iostream>
using namespace std;
//using namespace flow;
using namespace flowstar;

void printInterval(flowstar::Interval inter)
{
    std::cout<<"Low limit: "<<inter.inf()<<"\n";
    std::cout<<"Hi limit: "<<inter.sup()<<"\n";
}
void printInterval(Real real)
{
    std::cout<<"value of real: "<<real.getValue_RNDU()<<"\n";
}
void printMessage(string message)
{
    std::cout<<message<<"\n";
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
    std::cout<<"Low limit: "<<toBinary(inter.inf())<<"\n";
    std::cout<<"Hi limit: "<<toBinary(inter.sup())<<"\n";
}
int main()
{
    Interval a=Interval();
    BitPrint(a);
	Interval b=Interval (12);
    BitPrint(b);
    Real r=Real(12.2);
    Real r2=Real(19.64);
	Interval c =Interval(r);
    BitPrint(c);
    Interval d=Interval(10,20);
    BitPrint(d);
    Interval e=Interval(r,r2);
    BitPrint(e);
    Interval f=Interval(r,r2,5);
    BitPrint(f);
	char * strlo="34.2235235";
    char * strhi="54.225252";
    Interval g=Interval(strlo,strhi);
    BitPrint(g);
    Interval h=Interval(a);
    BitPrint(h);
    if(a.isZero())
    {
       std::cout<< "a is zero\n";
    }
    if(!b.isZero())
    {
        std::cout<<"b is not zero\n";
    }
    a.set(5,9);
    BitPrint(a);
    b.set(13);
    BitPrint(b);
    c.set(r2);
    BitPrint(c);

	a.setInf(-1);
    BitPrint(a);
    b.setInf(d);
    BitPrint(b);

    a.setSup(15);
    BitPrint(a);
    a.setSup(d);
    BitPrint(a);

    d.split(a,b);
    BitPrint(a);
    BitPrint(b);


	e.set_inf();
    BitPrint(e);
    printMessage("point");

    f.sup(e);
    BitPrint(e);
    f.inf(e);
    BitPrint(e);
    e.sup(r);
    BitPrint(r);
    e.inf(r2);
    BitPrint(r2);
    cout<< "Midpoint of d is:"<<toBinary(d.midpoint())<<"\n";
    d.midpoint(e);
    BitPrint(e); 
    d=Interval(24,65);
    d.toCenterForm(r,r2);
    std::cout<<"Centre: " <<toBinary(r.getValue_RNDU()) << "\n";
    std:: cout<<"Radius: " << toBinary(r2.getValue_RNDU())<<"\n";
    d.remove_midpoint(c);
    BitPrint(d);
    BitPrint(c);
    d=Interval(24,65);
    d.remove_midpoint();
    BitPrint(d);
    a.set(5,9);
    d=Interval(24,65);
    b.set(13,35);
    Interval intersect=b.intersect(d);
    BitPrint(intersect);
    b.intersect(d);
    BitPrint(b);
    b.bloat(52);
    BitPrint(b);
    b.set(24,30);
    std::cout<< "Within: "<<b.within(d,40) <<"\n";
    std::cout<< "Within: "<<b.within(d,30) <<"\n";
    std::cout<< "Width: "<< toBinary(d.width()) <<"\n";
    d.width(c);
    BitPrint(c);
    a=Interval(-110,54);
    std::cout<< "mag: "<<toBinary( a.mag()) <<"\n";
    a.mag(c);
    BitPrint(c);
    a.abs(c);
    BitPrint(c);
    a.abs_assign();
    BitPrint(a); 
    a=Interval(10,20);
    b=Interval(13,15);
    c=Interval(8,4);

    std::cout<< "Supseteq: "<<a.supseteq(b) <<"\n";
    std::cout<< "Supseteq: "<<b.supseteq(a) <<"\n";
    std::cout<< "Subseteq: "<<a.subseteq(b) <<"\n";
    std::cout<< "Subseteq: "<<b.subseteq(a) <<"\n";

    std::cout<< "Valid: "<<a.valid() <<"\n";
    std::cout<< "Valid: "<< c.valid()<<"\n";

    c=Interval(10,20);

    std::cout<< "==: "<< (a==c) <<"\n";
    std::cout<< "==: "<< (a==b) <<"\n";
    std::cout<< "!=: "<< (a!=c) <<"\n";
    std::cout<< "!=: "<< (a!=b) <<"\n";
    a=Interval(10,20);
    b=Interval(13,15);
    c=Interval(4,8);
    d=Interval(7,13);
    std::cout<< ">: "<< (a>c) <<"\n";
    std::cout<< ">: "<< (a>b) <<"\n";
    std::cout<< "<: "<< (c<a) <<"\n";
    std::cout<< "<: "<< (b<a) <<"\n";
    std::cout<< ">=: "<< (a>=b) <<"\n";
    std::cout<< ">=: "<< (d>=a) <<"\n";
    std::cout<< "<=: "<< (a<=b) <<"\n";
    std::cout<< "<=: "<< (b<=a) <<"\n";
    std::cout<< "smallereq: "<< (d.smallereq(b)) <<"\n";
    std::cout<< "smallereq: "<< (c.smallereq(d)) <<"\n";
    c=a;
    BitPrint(c);
    c=15;
    BitPrint(c);
    c=r;
    BitPrint(c);
    c=a+b;
    BitPrint(c);
    c+=d;
    BitPrint(c);
    c=b-d;
    BitPrint(c);
    c-=-30;
    BitPrint(c);
    c-=d;
    BitPrint(c);
    c=a*5;
    BitPrint(c);
    c/=5;
    BitPrint(c);
    c=c/10;
    BitPrint(c);
    c*=10;
    BitPrint(c);
    a=Interval(10,20);
    a.sqrt(c);
    BitPrint(c);
    a.inv(c);
    BitPrint(c);
    a.rec(c);
    BitPrint(c);
    a.sqrt_assign();
    BitPrint(a);
    a=Interval(10,20);
    a.inv_assign();
    BitPrint(a);
    a=Interval(10,20);
    a.rec_assign();
    BitPrint(a);
    a=Interval(10,20);
    a.add_assign(25.89);
    BitPrint(a);
    a.sub_assign(14.56);
    BitPrint(a);
    a.mul_assign(2.43);
    BitPrint(a);
    a.div_assign(1.312);
    BitPrint(a);


    Interval *intVec= new Interval[10];
    intVec[0]=Interval(1.242134,4.2345235);
    intVec[1]=Interval(4.2,5.87);
    intVec[2]=Interval(-3.24134,4.235);
    intVec[3]=Interval(0.134,6.2235);
    intVec[4]=Interval(8.24,11.235);
    intVec[5]=Interval(3.245846890,6.81189998119911);
    intVec[6]=Interval(10.2134,4.2235);
    intVec[7]=Interval(7.242134,9.345235);
    intVec[8]=Interval(10.4,14.58967);
    intVec[9]=Interval(1,4);

    a.mul_add(&b,intVec,10);
    BitPrint(b);
    intVec[0].pow_assign(7);
    BitPrint(intVec[0]);
    intVec[2].pow_assign(3);
    BitPrint(intVec[2]);

    cout<< "Width Ratio: "<< toBinary(intVec[8].widthRatio(intVec[9]))<<"\n";

    printMessage("Sin testing:");

    a=Interval(-2,1.5);
    BitPrint(a.sin());
    a.sin_assign();
    BitPrint(a);

    printMessage("Cos testing:");

    a=Interval(-3,2);
    BitPrint(a.cos());
    a.cos_assign();
    BitPrint(a);


    

    





	/*

	
	

	void mul_add(Interval *result, const Interval *intVec, const int size);

	Interval pow(const int n) const;
	void pow_assign(const int n);
	double widthRatio(const Interval & I) const;

	void toString(std::string & result) const;
	void dump(FILE *fp) const;
	void output(FILE *fp, const char * msg, const char * msg2) const;*/

	
}

