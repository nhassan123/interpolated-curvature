#ifndef ANISOTROPIC_MEASURE
#define ANISOTROPIC_MEASURE
#include <Eigen/Core>
#include <Eigen/Sparse>
/*
    This function computes the anisotropic measure of a triangle with respect to the basis vectors
    and populates the 3x3 tensor mu_M that goes towards the second fundamental form
    Inputs:
        F #F by 3 list of mesh face indices into V
        V #V by 3 list of mesh vertex positions
        N #V by 3 list of mesh vertex normals
        A_ratio_at_v #F SparseVector of area ratios at vertex v of each triangle 
        v vertex of interst
    Outputs:
        a_m 3 x 3 matrix of anisotropic measure
*/

void anisotropic_measure(
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio_at_v,
  const int & v,
  Eigen::MatrixXd & a_m);
#endif

