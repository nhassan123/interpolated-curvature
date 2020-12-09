#ifndef COMPUTE_BIG_M
#define COMPUTE_BIG_M
#include <Eigen/Core>
#include <Eigen/Sparse>
/*
This function computes big_M, the symmetrized anisotropic measure, at vertex v
Inputs:
    v     vertex index in [0, #V - 1] into V
    K     int chosen significantly greater than maximal curvature. Set to 1000 by default in main.cpp.
    V     #V by 3 list of mesh vertex positions
    F     #F by 3 list of mesh face vertex indices
    N     #V by 3 list of per vertex normal vectors. (From igl::per_vertex_normals(V, F, N))
    area_ratio_list_v #V by 1 list of area ratios at vertex v, in the order of appearance in F 
Outputs:
    big_M 3 by 3 close-to-symmetric matrix. The principal curvatures and principal curvature directions will be extracted from this matrix.
*/

void compute_big_M(
  const int v,
  const int K,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio_at_v,
  Eigen::MatrixXd & big_M);
#endif

