#include <stdio.h>
#include <math.h>

/* ============================================================
   invertMatrix(C, A) implements the Gauss-Jordan algorithm  to
   invert the NxN input matrix A. The inverse matrix is stored in the NxN matrix C.

   invertMatrix(double C[N][N], double A[N][N]):

      input:  A = an NxN matrix that you need to find the inverse

              C = Output matrix
                  When the invertMatrix( ) function completes, 
		  the matrix C will contains the inverse of A

      (N = #row and # columns in A and C)
   ============================================================= */

void invertMatrix(double C[N][N], double A[N][N])
{

	//C=I (identity matrix)

	int i, j, k;
	double norm, oper, constant;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(i == j){
				C[i][j] = 1;
			}else{
				C[i][j] = 0;
			}
		}
	}

	for (i = 0; i < N; i++ ){
		//multiply row i in matrix A and I by 1/A[i][i]
		norm = A[i][i];
		for(j = 0; j < N; j++){
			A[i][j] /= norm;
			C[i][j] /= norm;
		}

		//row operation to make principal diagonal to 1
		for (j = 0; j < N; j++){
			if (j != i ){
				//Add -A[j][i]*rowi to rowj in matrix A and I
				constant = -A[j][i];
				for(k = 0; k < N; k++){
					A[j][k] += constant*A[i][k];
					C[j][k] += constant*C[i][k];
				}
			}
		}
	}

}

 
