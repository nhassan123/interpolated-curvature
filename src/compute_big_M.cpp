#include "../include/compute_big_M.h"
#include "../include/anisotropic_measure.h"
#include <iostream>

void compute_big_M(
  const int v,
  const int K,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio_at_V,
  Eigen::MatrixXd & big_M)
  {



    Eigen::MatrixXd mu_M = Eigen::MatrixXd::Zero(3, 3);
    anisotropic_measure(F, V, N, A_ratio_at_V, v, mu_M);					

    big_M.resize(3, 3);
    big_M = 0.5 * (mu_M + mu_M.transpose()) + K * N.row(v).transpose() * N.row(v);

}

