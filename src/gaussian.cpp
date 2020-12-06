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

    n_ui = ui.normalized();
    n_uj = uj.normalized();
    n_uk = uk.normalized();
    //std::cout << "n_ui: " << n_ui << "; n_uj: " << n_uj << "; n_uk: " << n_uk << std::endl;

    Eigen::Vector3d cross_prod = n_uj.cross(n_uk);
    //std::cout << "cp: "<< cross_prod(0) <<std::endl;

    gaussian_curvature = (n_ui.dot(cross_prod)) / 2;
    //std::cout <<  gaussian_curvature <<std::endl;
  }

