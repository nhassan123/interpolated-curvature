#ifndef MEAN_DENSITY_BALL
#define MEAN_DENSITY_BALL
#include <Eigen/Core>
#include <Eigen/Sparse>
// Compute the corrected area at each vertex by taking the weighted sum of the corrected area 
// of each triangle that shares a given vertex 
// Inputs:
//   V #V by 3 list of mesh vertex positions
//   F #V by 3 list of vertices in a face
//   A_ratio #F by 3 list of internal angle (area) ratios incident on respective corner
//   v  vertex of interest
// Outputs:
//   area_ball  computed sum of corrected area at vertex of interest
//
void mean_density_ball(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio,
  const int & v,
  double & mean_density_ball
  );

#endif