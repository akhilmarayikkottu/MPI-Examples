#include "iostream"
#include <mpi.h>
using namespace std;

void even (int a)
{
cout << " Inside even ranks "<< a<< endl;
}

void odd (int a)
{
cout << " Inside odd ranks "<< a << endl;
}

int main()
{
int count, rank, tan;
MPI_Init(NULL,NULL);
MPI_Comm_size(MPI_COMM_WORLD, &count);
MPI_Comm_rank(MPI_COMM_WORLD,  &rank);

if (rank  == 0)
{
int Mail [4] = {};

MPI_Send(&Mail, 10, MPI_INT,1, 10,  MPI_COMM_WORLD);
// even(rank);
cout << rank << " RANK" << endl;
}

if (rank  == 1) 
{
int RecvMail;

MPI_Recv(&RecvMail, 10, MPI_INT, 0, 10, MPI_COMM_WORLD, NULL);
cout << "Recieved mail  --------> " << RecvMail << "   "<< rank << endl;
// odd(rank);
}

MPI_Finalize();
}
