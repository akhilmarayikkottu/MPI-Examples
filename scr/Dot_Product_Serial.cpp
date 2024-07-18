#include <mpi.h>
#include "iostream"



int main()
{
int N;
N = 1000;
int A[N], B[N], C;
C = 0;

for (int i = 0 ; i<N ; i++){
A[i] = 1 ; B[i] = i;}

for (int i=0; i<N; i++){
C = C+A[i]*B[i];
} 

std::cout << C <<  std::endl;

}
