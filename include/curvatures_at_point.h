#ifndef CURVATURES_AT_POINTS
#define CURVATURES_AT_POINTS
#include <Eigen/Core>

/*
This function computes the corrected principal curvature and corrected principal curvature directions at vertex v

Inputs:
    K     int chosen significantly greater than maximal curvature. Set to 1000 by default in main.cpp
    r     Scale parameter (radius). Set to 0.001 by default in main.cpp
    V     #V by 3 list of mesh vertex positions
    F     #F by 3 list of mesh face vertex indices
Outputs:
    D1  #V by 3 list of corrected first principal curvature directions
    D2  #V by 3 list of corrected second principal curvature directions
    K1  #V by 1 list of corrected first principal curvatures
    K2  #V by 1 list of corrected second principal curvatures
    G   #V by 1 list of corrected Gaussian curvatures
    H   #V by 1 list of corrected mean curvatures
*/


void curvatures_at_point(
    const int K,
    const double r,
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    Eigen::MatrixXd & D1,
    Eigen::MatrixXd & D2,
    Eigen::VectorXd & K1,
    Eigen::VectorXd & K2,
    Eigen::VectorXd & G,
    Eigen::VectorXd & H
    );
#endif

