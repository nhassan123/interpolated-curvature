#include "../include/anisotropic_measure.h"
#include "../include/second_fundamental_form_ball.h"
#include <iostream>

void anisotropic_measure(
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio_at_v,
  const int & v,
  Eigen::MatrixXd & a_m)
  {
    Eigen::VectorXd e1 = Eigen::VectorXd::Zero(3);
    Eigen::VectorXd e2 = Eigen::VectorXd::Zero(3);
    Eigen::VectorXd e3 = Eigen::VectorXd::Zero(3);
    e1(0) = 1;
    e2(1) = 1;
    e3(2) = 1;
   
    Eigen::VectorXd ei, ej;

    double sff_ij;

    for(int i =0; i< 3; i++){
      for(int j=0; j<3; j++){
        switch(i){
          case 0:
            ei = e1;
            break;
          case 1:
            ei = e2;
            break;
          case 2:
            ei = e3;
            break;
        }
        switch(j){
          case 0:
            ej = e1;
            break;
          case 1:
            ej = e2;
            break;
          case 2:
            ej = e3;
            break;
        }
       
        second_fundamental_form_ball(ei, ej, F, V, N, A_ratio_at_v, v, sff_ij);
       
        a_m(i,j) =  sff_ij;
      
      }
    }
  }
