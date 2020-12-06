#include "../include/corrected_area.h"

void corrected_area(
  const Eigen::VectorXd & xi,
  const Eigen::VectorXd & xj,
  const Eigen::VectorXd & xk,
  const Eigen::VectorXd & ui,
  const Eigen::VectorXd & uj,
  const Eigen::VectorXd & uk,
  double & area_density
  ){
    Eigen::Vector3d ubar = (ui+uj+uk) / 3;
    Eigen::Vector3d tmp1 = xj-xi;
    Eigen::Vector3d tmp2 = xk-xi;
    Eigen::Vector3d norm_tri = tmp1.cross(tmp2);
    area_density = (ubar.dot(norm_tri)) / 2;
  }

