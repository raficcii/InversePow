#include "iPow.h"
#include "LUsolve.h"




// =========================================================================
// M A I N   P R O G R A M
// =========================================================================

int main(int argc, char *argv[])
{
  int m; // number of rows
  int n; // number of columns

  #include "setCase.h"

  // ---------------------------------------------
  // Set up Inverse Power Method
  // ---------------------------------------------

  int    iter      = 0;
  int    maxIter   = 100;
  int    converged = 0;// flag for if you're converging on the eigenvalues
  double tol       = pow(10, -5);//10^-10, 10^-5 or something like that
  double mu; // k
  double mu_old    = mu + 1; //k +1
  double lambda; // goal

  double x[n];     // Used during Inverse Power Method Iteration, see class notes
  double xhat[n];  //   "   "       "       "      "      "        "    "     "

  // Compute initial guess at x
  
  for ( int i = 0; i < 1; i++) // max value has to be one, you have to scale it anyway
  { 
    x[i] = alpha;
  }
  // Compute (A - alpha*I) and store in A.

  for (int l = 0; l < m;  l++) // alpha is initial guess, subtract alpha from diagonal
  { 
    for (int j = 0; j < n; j++)
    {
      A[l][j] = findPivot(m, n, A, b, l, j) - alpha;
    }
  }

  // Save new A = (A - alpha*I) in Asave:
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      Asave[i][j] = A[i][j];
    }
  }

  // Print (A - alpha*I)
  
  printSystem("Printing System", m, n, Asave, b); // use goodies
  
  // ---------------------------------------------
  // Perform LU factorization of new A
  // ---------------------------------------------
  
  #include "LU.h"

  // A now stores what.?  Point to the upper triangular A with  U:

    double **U = A;

  // ---------------------------------------------
  // Inverse Power Method Iterations
  // ---------------------------------------------

  while (  converged != 1 )
    {
      // Max iteration check
      
      if (iter == maxIter)    
      {
        break;
      }

      // Step 2a: Compute xhat (Solve  (A - alpha I) * xhat = x)

      LUsolve(L , U , xhat , x , m , n , Asave );   // Asave is passed to check solution
      
      // Step 2b: Scale xhat so that the largest value = 1
      // Loop over all the values, find the biggest one and divide everything by it
      int scale = 0;
      for (int i = 0; i < m; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if (Asave[i][j] >= scale)
          {
            scale = Asave[i][j];
          }
        }
      }
      for (int k = 0; k < m; k++)
      {
          xhat[k]/scale;
      }

      // Step 2c: Check for convergence
      // compare mu and mu old
      if (mu == mu_old)
      {
        converged == 1;
      }
      iter++;
      cout << "iter = " << iter << " mu = " << mu << endl;
      
    }

  // Compute final estimate for eigenvalue of original A, Aoriginal:

    lambda = alpha + 1/mu;
  
    cout << caseName << ": Inverse Power Method Converged in " << iter << " iterations." << endl;
    cout << caseName << ": =========================== Results " << endl;
    cout << caseName << ": mu = " << mu << endl;
    cout << caseName << ": lambda = " << lambda << endl;
    cout << caseName << ": ===========================         " << endl;
  
  
  // ---------------------------------------------
  // Test Eigenvalue/Eigenvector
  // ---------------------------------------------

    // Print eigenvector and Aoriginal * eigenvector, computing the ratio
    // to see how consistent that ratio is.


    
    iLOOP printf("%s: E-vector Check:     x[%d] = %5.2f     Ax[%d] = %5.2f     ratio = %s\n",
		 caseName.c_str(), ....);

    
    
  
}

