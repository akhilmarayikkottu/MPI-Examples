#include <mpi.h>
#include "iostream"

inline double fn( double x);

int main()
{

double x_lo = -4;
double x_hi =  5;
double dx, x_lo_local, x_hi_local, Area;

Area = 0.0;
int N ;

std::cout << fn(x_lo) << "   " << fn(x_hi) << std::endl;
std::cin >> N;

dx = (x_hi-x_lo)/N;

for (int i=0; i <N; i++)
 {
  x_lo_local = x_lo+i*dx;
  x_hi_local = x_lo+(i+1)*dx;
  Area = Area+0.5*(fn(x_hi_local)+fn(x_lo_local))*dx;
 }

std::cout << Area << "<--- Area" << std::endl;

}


inline double fn( double x)
{
return x*x;
}
