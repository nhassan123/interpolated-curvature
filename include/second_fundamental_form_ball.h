#ifndef SECOND_FUNDAMENTAL_BALL
#define SECOND_FUNDAMENTAL_BALL
#include <Eigen/Core>
// Compute the second fundamental form at each vertex by taking the weighted sum of the second fundamental form 
// of each triangle that shares a given vertex 
//
// Inputs:
//  V #V by 3 list of mesh vertex positions
//  F #V by 3 list of vertices in a face
//  X 3D vector for tangent direction
//  Y 3D vector for second tangent direction
//  A_ratio #F by 3 list of internal angle (area) ratios incident on respective corner
//  v  vertex of interest
// Outputs:
//  sff_ball computed sum of second fundamental form at vertex 
//
void second_fundamental_form_ball(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXd & F,
  const Eigen::VectorXd & X,
  const Eigen::VectorXd & Y,
  const Eigen::MatrixXd & A_ratio,
  const int & v,
  double sff_ball);
#endif
