#ifndef CURVATURES_AT_POINTS
#define CURVATURES_AT_POINTS
#include <Eigen/Core>
/*
This function computes the principal curvature and principal curvature directions at a specific vertex, indexed by v

Inputs:
    K int chosen significantly greater than maximal curvature. Set to 1000, for example.
    V #V by 3 list of mesh vertex positions
    F #F by 3 list of mesh face indices into V
Outputs:
    D1 #V by 3 list of corrected first principal curvature directions
    D2 #V by 3 list of corrected second principal curvature directions
    K1 #V by 1 list of corrected first principal curvatures
    K2 #V by 1 list of corrected second principal curvatures
*/


void curvatures_at_points(
    const int K,
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXd & F,
    Eigen::MatrixXd & D1,
    Eigen::MatrixXd & D2,
    Eigen::VectorXd & K1,
    Eigen::VectorXd & K2);
#endif

