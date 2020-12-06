#include "../include/compute_big_M.h"
#include "../include/anisotropic_measure.h"
#include <iostream>

void compute_big_M(
  const int v,
  const int K,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & N,
  const Eigen::SparseMatrix<double> & A,
  const Eigen::MatrixXd & A_ratio_at_V,
  Eigen::MatrixXd & big_M)
  {

  	//NOTE: do not pass elementary basis to anisotropic_measure
  	//anisotropic measure is passed the vertex positions and normals of vertices adjacent (and including) vertex v
  	//Eigen::SparseMatrix<double> vec = A.row(v);
    //int num_of_incident_edges = vec.nonZeros() - 1;
    //Eigen::MatrixXd V_local;
    //Eigen::MatrixXd N_local;
    // V_local.resize(num_of_incident_edges + 1, 3);			//V_local.row(0) is position of vertex v. Other rows are vertices adjacent to v, in order of V
    // N_local.resize(num_of_incident_edges + 1, 3);			//N_local.row(0) is normal at vertex v. Other rows are normals at vertices adjacent to v, in order of V
    // V_local.row(0) = V.row(v);
    // N_local.row(0) = N.row(v);

    // int j = 1;

    // for (int i = 0; i < V.rows(); ++i)
    // {
    // 	if (vec(i) == 1)
    // 	{
    // 		V_local.row(j) = V.row(i);
    // 		N_local.row(j) = N.row(i);
    // 		j += 1;
    // 	}
    // }
    //std::cout << "1" << std::endl;

    Eigen::MatrixXd mu_M = Eigen::MatrixXd::Zero(3, 3);
    anisotropic_measure(F, V, N, A_ratio_at_V, v, mu_M);					

    //std::cout << "2" << std::endl;

    big_M.resize(3, 3);
    big_M = 0.5 * (mu_M + mu_M.transpose()) + K * N.row(v) * N.row(v).transpose();

    //std::cout << "3" << std::endl;
  }

