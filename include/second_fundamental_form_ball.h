#ifndef SECOND_FUNDAMENTAL_BALL
#define SECOND_FUNDAMENTAL_BALL
#include <Eigen/Core>
#include <Eigen/Sparse>
// Compute the second fundamental form at each vertex by taking the weighted sum of the second fundamental form 
// of each triangle that shares a given vertex 
//
// Inputs:
//  X 3D vector for tangent direction
//  Y 3D vector for second tangent direction
//  V #V by 3 list of mesh vertex positions
//  F #F by 3 list of vertices in a face
//  N #V by 3 list of normals at each vertex
//  A_ratio_at_v #F SpareVector of area ratios of faces incident on respective vertex
//  v  vertex of interest
// Outputs:
//  sff_ball computed sum of second fundamental form at vertex 
//
void second_fundamental_form_ball(
  const Eigen::VectorXd & X,
  const Eigen::VectorXd & Y,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio_at_v,
  const int & v,
  double & sff_ball);
#endif

