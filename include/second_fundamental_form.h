#ifndef SECOND_FUNDAMENTAL
#define SECOND_FUNDAMENTAL
#include <Eigen/Core>
#include <Eigen/Dense>
// Compute the second fundamental form of a triangle using two given directions X, Y
// 
// Inputs:
//   X  3D Vector of tangent direction
//   Y  3D Vector of second tangent direction
//   xi 3D Vector position of vertex i of triangle
//   xj 3D Vector position of vertex j of triangle
//   xk 3D Vector position of vertex k of triangle
//   ui 3D Vector normal at vertex i of triangle
//   uj 3D Vector normal at vertex j of triangle
//   uk 3D Vector normal at vertex k of triangle
// Outputs:
//   sff  second fundamental form value for a triangle
//
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
  );

#endif
