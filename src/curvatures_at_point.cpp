#include "../include/curvatures_at_point.h"
#include <Eigen/Eigenvalues> 
//#include <igl/adjacency_matrix.h>  //check is this should be list
#include <igl/per_vertex_normals.h>
#include <igl/squared_edge_lengths.h>
#include "../include/area_ratio_at_v.h"
#include "../include/area_ball.h"
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
    //std::cout << "1" << std::endl;
    K1 = Eigen::VectorXd::Zero(V.rows());
  	K2 = Eigen::VectorXd::Zero(V.rows());
  	D1 = Eigen::MatrixXd::Zero(V.rows(), 3);
  	D2 = Eigen::MatrixXd::Zero(V.rows(), 3);
    G = Eigen::VectorXd::Zero(V.rows());
    H = Eigen::VectorXd::Zero(V.rows());
    

    //std::cout << "2" << std::endl;

    Eigen::MatrixXd l_sqr;
    l_sqr.resizeLike(F);
    igl::squared_edge_lengths(V, F, l_sqr);
    Eigen::MatrixXd A_angles;
    internal_angles(l_sqr, A_angles);

  	//Eigen::MatrixXd A_ratio;
  	//compute_area_ratio(V, F, A_ratio);

    //std::cout << "3" << std::endl;

  	//Eigen::SparseMatrix<double> A;
  	//igl::adjacency_matrix(V, A);

    //std::cout << "4" << std::endl;

    Eigen::MatrixXd N;
    igl::per_vertex_normals(V, F, N);

    //std::cout << "5" << std::endl;

    Eigen::MatrixXd Areas;
    igl::doublearea(V, F, Areas);
    Areas /= 2;

  	for (int v = 0; v < V.rows(); ++v)
  	{
      //std::cout << "a" << std::endl;
  		Eigen::VectorXd area_ratio_list_v;
  		area_ratio_at_v(v, F, A_angles, Areas, r, area_ratio_list_v);		//compute area ratios
/*      for (int i = 0; i < area_ratio_list_v.rows(); ++i)
      {
        if (area_ratio_list_v(i) != 0)
        {
          std::cout << area_ratio_list_v(i) << std::endl;
        }
        
      }*/
     //std::cout << area_ratio_list_v.sum() << std::endl;

      //std::cout << "b" << std::endl;

  		double mu_0 = 0;
  		area_ball(V, F, N, area_ratio_list_v, v, mu_0);			//compute mu_0
        //std::cout<<"mu_0:"<< mu_0 <<std::endl;
      //std::cout << "c" << std::endl;

  		Eigen::MatrixXd big_M = Eigen::MatrixXd::Zero(3, 3);
  		compute_big_M(v, K, V, F, N, area_ratio_list_v, big_M);               //compute big_M

      //std::cout << "d" << std::endl;
      //Note: big_M is symmetric, so we can use SelfAdjointEigenSolver for the eigendecomposition
      //SelfAdjointEigenSolver sorts eigenvalues in increasing order

      Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> es(big_M);
      double lambda_1 = es.eigenvalues()[0];
      double lambda_2 = es.eigenvalues()[1];
      //double lambda_3 = es.eigenvalues()[2];
      Eigen::VectorXd z_1 = es.eigenvectors().col(0);
      Eigen::VectorXd z_2 = es.eigenvectors().col(1);
      //Eigen::VectorXd z_3 = es.eigenvectors().col(2);
/*      std::cout << "lamda_1:"<< lambda_1<< std::endl;
	    std::cout << "lamda_2:"<< lambda_2<< std::endl;
      std::cout << "lamda_3:"<< lambda_3<< std::endl;
	    std::cout<<"z_1: "<<z_1(0)<<" "<<z_1(1)<<" "<<z_1(2)<<std::endl;
	    std::cout<<"z_2: "<<z_2(0)<<" "<<z_2(1)<<" "<<z_2(2)<<std::endl;
      std::cout<<"z_3: "<<z_3(0)<<" "<<z_3(1)<<" "<<z_3(2)<<std::endl;*/
  	  K1(v) = -lambda_2 / mu_0;
      K2(v) = -lambda_1 / mu_0;
  	  D1.row(v) = z_2.transpose() / mu_0;
  	  D2.row(v) = z_1.transpose() / mu_0;
	  D1.row(v).normalize(); 
	  D2.row(v).normalize();


    double mu_1 = 0;
    double mu_2 = 0;
    //mu_1_function(V, F, N, area_ratio_list_v, v, mu_1);
    //mu_2_function(V, F, N, area_ratio_list_v, v, mu_2);
    H(v) = mu_1 / mu_0;
    G(v) = mu_2 / mu_0;
	  std::cout<<"vertex #:"<< v << std::endl;

    //std::cout<< big_M << std::endl;

  	}
    //std::cout << "6" << std::endl;
    
}
