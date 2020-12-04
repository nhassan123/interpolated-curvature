#ifndef AREA_BALL
#define AREA_BALL
#include <Eigen/Core>
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
void area_ball(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXd & F,
  const Eigen::MatrixXd & A_ratio,
  const int & v,
  double & area_ball
  );

#endif