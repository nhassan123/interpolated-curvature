#ifndef ANGLE_DEFECT_H
#define ANGLE_DEFECT_H
#include <Eigen/Core>
// Compute the discrete angle defect at each vertex of a triangle mesh
// (`V`,`F`), that is, the _locally integrated_ discrete Gaussian
// curvature.
//
// Inputs:
//   V  #V by 3 list of mesh vertex positions
//   F  #F by 3 list of mesh face indices into V
// Outputs:
//   A_ratio  #F by 3 list of internal angle (area) ratios incident on respective corner
void compute_area_ratio(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & A_ratio);
#endif
