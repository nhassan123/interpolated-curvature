#include "../include/mean_density.h"

void mean_density(
  const Eigen::VectorXd & xi,
  const Eigen::VectorXd & xj,
  const Eigen::VectorXd & xk,
  const Eigen::VectorXd & ui,
  const Eigen::VectorXd & uj,
  const Eigen::VectorXd & uk,
  double & mean_density
  ){
    Eigen::Vector3d ubar = (ui+uj+uk) / 3;
    Eigen::Vector3d tmp1 = uk-uj;
    Eigen::Vector3d tmp2 = ui-uk;
    Eigen::Vector3d tmp3 = uj-ui;
    Eigen::Vector3d n_xi, n_xj, n_xk;


    n_xi = xi;
    n_xj = xj;
    n_xk = xk;
    Eigen::Vector3d cross_sum = tmp1.cross(n_xi)+ tmp2.cross(n_xj) + tmp3.cross(n_xk);
    mean_density = (ubar.dot(cross_sum)) / 2;
  }

