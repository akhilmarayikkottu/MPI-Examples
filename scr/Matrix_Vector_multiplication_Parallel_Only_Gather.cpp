#include <iostream>
#include "mpi.h"

int main(){

/* MPI initialization */
int rank, N_proc;
MPI_Init(NULL,NULL);
MPI_Comm_size(MPI_COMM_WORLD, &N_proc);
MPI_Comm_rank(MPI_COMM_WORLD, &rank  );

/* local processor variables */
int l_start, l_end, l_size;

int m = 6;
int n = 60000;


l_size  = m/N_proc;
l_start = rank*l_size;
l_end   = l_start+l_size;


int A[m][n], x[n], C[l_size], globalC[m];

for (int i= 0; i < m; i++){
  C[i] = 0 ;
   for (int j=0; j < n; j++){
    A[i][j] = i+j ;
    x[j]    = 1   ;
   }
}

for (int i= l_start; i < l_end; i++){
   for (int j=0; j < n; j++){
    C[i-l_start] =  C[i-l_start]+A[i][j]*x[j];
   }
}

for ( int k = 0; k < l_size ; k++){
std::cout << C[k] << "   " ;
}
std::cout<< std::endl;

/* Gather the local products into root*/

MPI_Gather(&C, l_size, MPI_INT, &globalC, l_size, MPI_INT, 0, MPI_COMM_WORLD);

if ( rank == 0 ){
for (int k = 0; k < m ; k++){
std::cout << globalC[k] << "   "  ;
}}

std::cout << std::endl;

MPI_Finalize();
}
