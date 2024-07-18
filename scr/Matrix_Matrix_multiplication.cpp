#include "iostream"

int main()
{
int m, n, l;

m = 4; n = 4 ; l = 4;
int A[m][n], B[n][l], C[m][l];

for (int i=0; i<m; i++){
for (int j=0; j<n; j++){
 A[i][j] = i+j*j;
}
}

for (int i=0; i<n; i++){
for (int j=0; j<l; j++){
 B[i][j] = i+j;
}
}

for (int i=0; i<m; i++){
  for (int j=0; j<l; j++){
     C[i][j] = 0;
      for (int k=0; k<n; k++){
        C[i][j] = C[i][j]+A[i][k]*B[k][j];
      }
  }
}

std::cout << "/*** Original matrix on rank 0 ***/" << std::endl;
std::cout << "A" << "\n" << std::endl;

for (int i =0; i<m; i++){
 for (int j=0; j<n; j++){
  std::cout << A[i][j] << "   " ;
    }
    std::cout << "\n" ;
  }

std::cout << "\n" << "B" << "\n" << std::endl;

for (int i =0; i<n; i++){
 for (int j=0; j<l; j++){
  std::cout << B[i][j] << "   " ;
    }
    std::cout << "\n" ;
  }

std::cout << "\n" << "Product matrix C" << "\n" << std::endl;

for (int i =0; i<m; i++){ 
 for (int j=0; j<l; j++){ 
  std::cout << C[i][j] << "   " ;
    }
    std::cout << "\n" ;
  }

}
