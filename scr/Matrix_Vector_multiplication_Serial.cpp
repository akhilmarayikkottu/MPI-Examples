#include <iostream>


int main(){

int m = 6;
int n = 60000;

int A[m][n], x[n], C[m];

for (int i= 0; i < m; i++){
  C[i] = 0 ;
   for (int j=0; j < n; j++){
    A[i][j] = i+j ;
    x[j]    = 1   ;
   }
}

/* for (int i= 0; i < m; i++){
   for (int j=0; j < n; j++){
   std::cout << A[i][j] << "  " ;
   }
   std::cout << " " << std::endl;
} */


for (int i= 0; i < m; i++){
   for (int j=0; j < n; j++){
    C[i] =  C[i]+A[i][j]*x[j];
   }
}

for ( int k = 0; k < m ; k++){
std::cout << C[k] << "   " ;
}

}
