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
    Eigen::VectorXd ubar = (ui+uj+uk) / 3;
    Eigen::VectorXd norm_tri = (xj-xi).cross(xk-xi);
    area_density = (ubar.dot(norm_tri)) / 2;
  }

