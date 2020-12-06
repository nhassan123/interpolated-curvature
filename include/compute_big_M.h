#ifndef COMPUTE_BIG_M
#define COMPUTE_BIG_M
#include <Eigen/Core>
#include <Eigen/Sparse>
/*
This function computes big_M at a specific vertex, indexed by v
Inputs:
    v     vertex index in [0, #V - 1] into V
    K     int chosen significantly greater than maximal curvature. Set to 1000, for example.
    V     #V by 3 list of mesh vertex positions
    N     #V by 3 list of per vertex normal vectors. Eg. from igl::per_vertex_normals(V, F, N)
    A     #V by #V adjacency matrix
Outputs:
    big_M 3 by 3 matrix of stuff. The principal curvatures and principal curvature directions will be extracted from this matrix.
*/

void compute_big_M(
  const int v,
  const int K,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & N,
  const Eigen::MatrixXd & A_ratio_at_v,
  Eigen::MatrixXd & big_M);
#endif

