#ifndef AREA_RATIO_H
#define AREA_RATIO_H
#include <Eigen/Core>
#include <Eigen/Sparse>
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
void area_ratio_get(
  const int v,
  const Eigen::SparseMatrix<double> & A,
  const Eigen::MatrixXi & F, 
  const Eigen::MatrixXd & A_ratio,
  Eigen::VectorXd & area_ratio_list_v);

#endif
