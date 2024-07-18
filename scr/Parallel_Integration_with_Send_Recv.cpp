#include <mpi.h>
#include "iostream"

inline double fn( double x);

int main(){
MPI_Init(NULL,NULL);
int rank, num_proc;

MPI_Comm_rank(MPI_COMM_WORLD, &rank    );
MPI_Comm_size(MPI_COMM_WORLD, &num_proc);

double x_lo = -4 ;
double x_hi =  5 ;
double dx, x_lo_local, x_hi_local, Area;

Area  = 0.0        ;
int N = 1000000000 ;

int p_N         = N/num_proc ;
double p_dx     = (x_hi - x_lo)/num_proc ;
double p_x_lo   = rank*p_dx+x_lo         ;
double RecvArea = 0.0 ;
double TotArea  = 0.0 ;

dx = (x_hi-x_lo)/N;

for (int i=0; i < p_N ; i++)
 {
  x_lo_local = p_x_lo+i*dx    ;
  x_hi_local = x_lo_local+ dx ;
  Area = Area+0.5*(fn(x_hi_local)+fn(x_lo_local))*dx;
 }

MPI_Barrier(MPI_COMM_WORLD);

/* Send and recieve messages */

if (rank != 0 ){
MPI_Send(&Area    , 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD      );
}

if (rank == 0){
 TotArea = Area;
   for (int j = 1  ; j < num_proc ; j++)
        {
	   MPI_Recv(&RecvArea, 1, MPI_DOUBLE, j, 1, MPI_COMM_WORLD, NULL);
        //   std::cout << "Recieved message --->   " << RecvArea << std::endl;
           TotArea = TotArea+RecvArea ; 
	}
std::cout << "TOTAL AREA ~~~~~~~~~>  " << TotArea << std::endl;
              }
MPI_Finalize();
}

inline double fn( double x)
{
return x*x;
}
