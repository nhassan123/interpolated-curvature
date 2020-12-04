#include "../include/curvatures_at_point.h"
#include <Eigen/Eigenvalues> 
#include <igl/adjacency_list.h>
#include <igl/per_vertex_normals.h>
#include "../include/compute_area_ratio.h"
#include "../include/area_ratio_at_v.h"
#include "../include/area_ball.h"
#include "../include/compute_big_M.h"

void curvatures_at_point(
  const int K,
	const Eigen::MatrixXd & V,
	const Eigen::MatrixXd & F,
	Eigen::MatrixXd & D1,
  Eigen::MatrixXd & D2,
  Eigen::VectorXd & K1,
  Eigen::VectorXd & K2){
	/*
	This function computes the principal curvature and principal curvature directions at all vertices
	
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

    K1 = Eigen::VectorXd::Zero(V.rows());
  	K2 = Eigen::VectorXd::Zero(V.rows());
  	D1 = Eigen::MatrixXd::Zero(V.rows(), 3);
  	D2 = Eigen::MatrixXd::Zero(V.rows(), 3);

  	Eigen::MatrixXd A_ratio;
  	compute_area_ratio(V, F, A_ratio);

  	Eigen::SparseMatrix<double> A;
  	igl::adjacency_list(V, F, A);

    Eigen::MatrixXd N;
    igl::per_vertex_normals(V, F, N);


  	for (int v = 0; v < V.rows(), ++v)
  	{
  		Eigen::VectorXd area_ratio_list_v;
  		area_ratio_at_v(v, A, F, A_ratio, area_ratio_list_v)		//compute area ratios

  		double mu_0;
  		area_ball(V, F, area_ratio_list_v, v, mu_0);			//compute mu_0

  		Eigen::MatrixXd big_M = Eigen::MatrixXd::Zero(3, 3);
  		compute_big_M(v, K, V, N, A, big_M);               //compute big_M

      //Note: big_M is symmetric, so we can use SelfAdjointEigenSolver for the eigendecomposition
      //SelfAdjointEigenSolver sorts eigenvalues in increasing order

      Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> es(big_M);
      double lambda_1 = es.eigenvalues()[0];
      double lambda_2 = es.eigenvalues()[1];
      double z_1 = es.eigenvectors().col(0);
      double z_2 = es.eigenvectors().col(1);

  		K1(v) = -lambda_2 / mu_0;
  		K2(v) = -lambda_1 / mu_0;
  		D1.row(v) = z_2.transpose() / mu_0;
  		D2.row(v) = z_1.transpose() / mu_0;
  	}
}
