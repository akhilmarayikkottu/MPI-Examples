#include <iostream>
#include "mpi.h"


int main(){

int rank;
int N_proc;

MPI_Init(NULL, NULL);
MPI_Comm_size(MPI_COMM_WORLD, &N_proc);
MPI_Comm_rank(MPI_COMM_WORLD, &rank  );

MPI_Aint displacement[3];
int a = 8;
float b = 17.54;
char c = 'A';
int block_length[3] ;


char C;
int A;
float B;


MPI_Aint Address_a, Address_b, Address_c;
MPI_Datatype  typelist[3], send_mpi, recv_mpi;

block_length[0] = 1; block_length[1] = 1; block_length[2] = 1;

typelist[0] =  MPI_INT;
typelist[1] =  MPI_FLOAT;
typelist[2] =  MPI_CHAR;

if (rank == 0 ){
MPI_Get_address(&a, &Address_a);
MPI_Get_address(&b, &Address_b);
MPI_Get_address(&c, &Address_c);

displacement[0] = 0;
displacement[1] = Address_b-Address_a;
displacement[2] = Address_c-Address_a;

MPI_Type_create_struct(3,block_length, displacement,typelist, &send_mpi);  
MPI_Type_commit( &send_mpi) ;

MPI_Send(&a, 1, send_mpi, 1, 9, MPI_COMM_WORLD);
std::cout << rank << " -->   " << a << "  " <<  b <<"  "<<  c << std::endl;
}

if (rank == 1){
MPI_Get_address(&A, &Address_a);
MPI_Get_address(&B, &Address_b);
MPI_Get_address(&C, &Address_c);

displacement[0] = 0;
displacement[1] = Address_b-Address_a;
displacement[2] = Address_c-Address_a;

MPI_Type_create_struct(3,block_length, displacement,typelist, &recv_mpi);
MPI_Type_commit( &recv_mpi) ;

MPI_Recv(&A, 1, recv_mpi, 0, 9, MPI_COMM_WORLD, NULL);
std::cout << rank << " -->   " << A << "  " <<  B <<"  "<<  C << std::endl;
}


MPI_Finalize();
}
