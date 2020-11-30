#ifndef SECOND_FUNDAMENTAL_BALL
#define SECOND_FUNDAMENTAL_BALL
#include <Eigen/Core>
// 
//
// Inputs:
//  
// Outputs:
//   
//
void second_fundamental_form_ball(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXd & F,
  const Eigen::VectorXd & X,
  const Eigen::VectorXd & Y,
  const Eigen::MatrixXd & A_ratio,
  const int v,
  double sff_ball);
#endif

