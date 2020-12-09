#ifndef MU_BALL
#define MU_BALL
#include <Eigen/Core>
#include <Eigen/Sparse>
// Compute the corrected area, corrected mean curvatures and corrected gaussian curvatures 
// at each vertex by taking the weighted sum of the corrected area 
// of each triangle that shares a given vertex 
// Inputs:
//   V #V by 3 list of mesh vertex positions
//   F #V by 3 list of vertices in a face
//   A_ratio #F SparseVector of area ratios of each triangle incident on respective corner
//   v  vertex of interest
// Outputs:
//   area_ball  computed sum of corrected area at vertex of interest
//   mean_desnity_ball  computed sum of corrected mean curvature at vertex of interest
//   gaussian_ball  computed sum of corrected gaussian curvature at vertex of interest
  
void mu_ball(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio,
  const int & v,
  double & area_ball,
  double & mean_density_ball,
  double & gaussian_ball_sum
  );

#endif