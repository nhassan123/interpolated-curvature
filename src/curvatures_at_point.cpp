#include "../include/curvatures_at_point.h"
#include <Eigen/Eigenvalues> 
#include <igl/per_vertex_normals.h>
#include <igl/squared_edge_lengths.h>
#include "../include/area_ratio_at_v.h"
#include "../include/mu_ball.h"
#include "../include/compute_big_M.h"
#include "../include/internal_angles.h"
#include <igl/doublearea.h>
#include <iostream>

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
  Eigen::VectorXd & H)
{
   
    K1 = Eigen::VectorXd::Zero(V.rows());
  	K2 = Eigen::VectorXd::Zero(V.rows());
  	D1 = Eigen::MatrixXd::Zero(V.rows(), 3);
  	D2 = Eigen::MatrixXd::Zero(V.rows(), 3);
    G = Eigen::VectorXd::Zero(V.rows());
    H = Eigen::VectorXd::Zero(V.rows());
    

    Eigen::MatrixXd l_sqr;
    l_sqr.resizeLike(F);
    igl::squared_edge_lengths(V, F, l_sqr);
    Eigen::MatrixXd A_angles;
    internal_angles(l_sqr, A_angles);

    Eigen::MatrixXd N;
    igl::per_vertex_normals(V, F, N);

    Eigen::MatrixXd Areas;
    igl::doublearea(V, F, Areas);
    Areas /= 2;

  	for (int v = 0; v < V.rows(); ++v)
  	{
      
  		Eigen::SparseVector<double> area_ratio_list_v;
  		area_ratio_at_v(v, V, F, A_angles, Areas, r, area_ratio_list_v);		//compute area ratios

  		double mu_0 = 0;
      double mu_1 = 0;
      double mu_2 = 0;
  	  mu_ball(V, F, N, area_ratio_list_v, v, mu_0, mu_1, mu_2);			//compute mu_0
      
  		Eigen::MatrixXd big_M = Eigen::MatrixXd::Zero(3, 3);
  		compute_big_M(v, K, V, F, N, area_ratio_list_v, big_M);               //compute big_M

      Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> es(big_M);
      double lambda_1 = es.eigenvalues()[0];
      double lambda_2 = es.eigenvalues()[1];
      Eigen::VectorXd z_1 = es.eigenvectors().col(0);
      Eigen::VectorXd z_2 = es.eigenvectors().col(1);
      
      K1(v) = -lambda_2 / mu_0;
      K2(v) = -lambda_1 / mu_0;
  	 
      D1.row(v) = z_2.transpose() / mu_0;
  	  D2.row(v) = z_1.transpose() / mu_0;
      D1.row(v).normalize(); 
      D2.row(v).normalize();
    
      H(v) = mu_1 / mu_0;
      G(v) = mu_2 / mu_0;
  	  

  	}
    
}
