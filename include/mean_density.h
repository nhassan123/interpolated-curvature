#ifndef MEAN_DENSITY
#define MEAN_DENSITY
#include <Eigen/Core>
#include <Eigen/Dense>
// Compute the corrected area of a triangle using the scalar and cross product functions on its vertices and normals
// 
// Inputs:
//   xi 3D Vector position of vertex i of triangle
//   xj 3D Vector position of vertex j of triangle
//   xk 3D Vector position of vertex k of triangle
//   ui 3D Vector normal at vertex i of triangle
//   uj 3D Vector normal at vertex j of triangle
//   uk 3D Vector normal at vertex k of triangle
// Outputs:
//   area_density  scalar corrected area density for a triangle
//
void mean_density(
  const Eigen::VectorXd & xi,
  const Eigen::VectorXd & xj,
  const Eigen::VectorXd & xk,
  const Eigen::VectorXd & ui,
  const Eigen::VectorXd & uj,
  const Eigen::VectorXd & uk,
  double & mean_density
  );

#endif
