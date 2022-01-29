
#include <stdio.h>
#include <math.h>

// Emory Honor code statement: (must be a comment to avoid compile error)
//
// THIS CODE IS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING A TUTOR
// OR CODE WRITTEN BY OTHER STUDENTS - Mei Deng
//
// (Homework version: Fall 2021)


/* ---------------------------------------------------------------
   Project file for the pj10 in CS255 

   **********************************************
   *          How to run this project           *
   **********************************************

   Enter these command in EGTAPI terminal to run test1:  

         (1) gcc -o test1 -DN=3  test1.c helper.c inverse.c
         (2) test1
 
   Enter these command in EGTAPI terminal to run test2:  

         (1) gcc -o test2 -DN=3  test2.c helper.c inverse.c
         (2) test2

   Enter these command in EGTAPI terminal to run test3:  

         (1) gcc -o test3 -DN=7  test3.c helper.c inverse.c
         (2) test3
   --------------------------------------------------------------- */

/* ============================================================
   TODO: write the invertMatrix(C, A) function that
         implements the Gauss-Jordan algorithm  to
	 invert the NxN input matrix A.

	 The inverse matrix is stored in the NxN matrix C

   invertMatrix(double C[N][N], double A[N][N]):

      input:  A = an NxN matrix that you need to find the inverse
                  (You can change A if you like)

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

 