#ifndef ANISOTROPIC_MEASURE
#define ANISOTROPIC_MEASURE
#include <Eigen/Core>
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
  const Eigen::VectorXd & e1,
  const Eigen::VectorXd & e2,
  const Eigen::VectorXd & e3,
  const Eigen::VectorXd & xi,
  const Eigen::VectorXd & xj,
  const Eigen::VectorXd & xk,
  const Eigen::VectorXd & ui,
  const Eigen::VectorXd & uj,
  const Eigen::VectorXd & uk,
  Eigen::MatrixXd & a_m);
#endif

