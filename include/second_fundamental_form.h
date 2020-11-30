#ifndef SEDOND_FUNDAMENTAL
#define SECOND_FUNDAMENTAL
#include <Eigen/Core>
// Compute the discrete mean curvature at each vertex of a mesh (`V`,`F`) by
// taking the signed magnitude of the mean curvature normal as a _pointwise_ or
// _integral average_ quantity.
//
// Inputs:
//   V  #V by 3 list of mesh vertex positions
//   F  #F by 3 list of mesh face indices into V
// Outputs:
//   H  #V list of mean curvature values in units 1/m²
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
