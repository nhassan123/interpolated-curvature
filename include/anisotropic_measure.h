#ifndef ANISOTROPIC_MEASURE
#define ANISOTROPIC_MEASURE
#include <Eigen/Core>
#include <Eigen/Sparse>
/*
    This function computes big_M at a specific vertex, indexed by v
    Inputs:
        e1
        e2
        e3
        xi 
        xj
        xk
        ui
        uj
        uk
    Outputs:
        a_m 3 x 3 matrix of anisotropic measure
*/

void anisotropic_measure(
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio_at_v,
  const int & v,
  Eigen::MatrixXd & a_m);
#endif

