#include "../include/gaussian.h"
#include <iostream>

void gaussian(
  const Eigen::VectorXd & xi,
  const Eigen::VectorXd & xj,
  const Eigen::VectorXd & xk,
  const Eigen::VectorXd & ui,
  const Eigen::VectorXd & uj,
  const Eigen::VectorXd & uk,
  double & gaussian_curvature
  ){
   
    Eigen::Vector3d n_ui, n_uj, n_uk;

    n_ui = ui;
    n_uj = uj;
    n_uk = uk;
    
    Eigen::Vector3d cross_prod = n_uj.cross(n_uk);
    gaussian_curvature = (n_ui.dot(cross_prod)) / 2;
    
  }

