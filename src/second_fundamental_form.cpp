#include "../include/second_fundamental_form.h"
#include <iostream>

void second_fundamental_form(
  const Eigen::VectorXd & X,
  const Eigen::VectorXd & Y,
  const Eigen::VectorXd & xi,
  const Eigen::VectorXd & xj,
  const Eigen::VectorXd & xk,
  const Eigen::VectorXd & ui,
  const Eigen::VectorXd & uj,
  const Eigen::VectorXd & uk,
  double & sff
  ){
    Eigen::Vector3d ubar = (ui+uj+uk)/3;
    Eigen::Vector3d tmp1, tmp2, tmp3, tmp4;
    
    tmp1 = (Y.dot(uk-ui))*X;
    tmp2 = xj - xi;
    tmp3 = (Y.dot(uj-ui))*X;
    tmp4 = xk - xi;
    sff = 0.5*(ubar.dot(tmp1.cross(tmp2))) - 0.5* (ubar.dot(tmp3.cross(tmp4)));
    //std::cout << sff << std::endl;
  }