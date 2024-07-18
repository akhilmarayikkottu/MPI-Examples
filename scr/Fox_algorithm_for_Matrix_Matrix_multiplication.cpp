#include "iostream"

int main()
{
int m, n, l, j_dash;

m = 4; n = 4 ; l = 4;
int A[m][n], B[n][l], C[m][l];
int A_dash[m][n], B_dash[n][l];
int diagonal[std::min(m,n)];


/* Initialize C matrix */

for (int i=0; i<m; i++){
for (int j=0; j<l; j++){
 C[i][j] = 0;
}
}

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

for (int j=0; j<n; j++)
  {
   /* Shuffle the B matrix and store 
      in B' matrix for element-wise
      product later */
  
   for (int k=0; k<m; k++){
    j_dash = (k+j)%m;
    for (int l=0; l<n; l++){
      B_dash[k][l] = B[j_dash][l];
    }    
    
   }


   /* Pick the upper row element  */

   for (int k=0; k<m; k++)
      {
       /* Pick diagonal elements and make A' matrix
          with rows same as the extracted element  */
          
       diagonal[k] = A[(0+k)%m][(j+k)%m];
      
       }
 
       for (int i = 0; i<m; i++){
         for (int j=0; j<n; j++){
        
          A_dash[i][j] = diagonal[i];
         
         }
        }

  /* Element-wise multiply and C */

 for (int i =0; i<m; i++){
  for (int j=0; j<l; j++){
     
     C[i][j] = C[i][j]+A_dash[i][j]*B_dash[i][j];
    }
  }



/*

 std::cout << "\n" << "B'" << "\n" << std::endl;

for (int i =0; i<n; i++){
 for (int j=0; j<l; j++){
  std::cout << B_dash[i][j] << "   " ;
    }
    std::cout << "\n" ;
  }
*/



     
/*      for (int i =0; i<m; i++){
      for (int j=0; j<n; j++){
     std::cout << A_dash[i][j] << "   " ;
       }
    std::cout << "\n" ;
      } */ 
  }

 std::cout << "/*** Original matrix on rank 0 ***/" << std::endl;
std::cout << "A" << "\n" << std::endl;

for (int i =0; i<m; i++){
 for (int j=0; j<n; j++){
  std::cout << A[i][j] << "   " ;
    }
    std::cout << "\n" ;
  } 

/* std::cout << "\n" << "B" << "\n" << std::endl;

for (int i =0; i<n; i++){
 for (int j=0; j<l; j++){
  std::cout << B[i][j] << "   " ;
    }
    std::cout << "\n" ;
  }
*/

std::cout << "\n" << "C" << "\n" << std::endl;

for (int i =0; i<m; i++){
 for (int j=0; j<l; j++){
  std::cout << C[i][j] << "   " ;
    }
    std::cout << "\n" ;
  }

}
