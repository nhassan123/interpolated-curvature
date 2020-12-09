#include "../include/second_fundamental_form_ball.h"
#include "../include/second_fundamental_form.h"
#include <iostream>

void second_fundamental_form_ball(
  const Eigen::VectorXd & X,
  const Eigen::VectorXd & Y,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio_at_v,
  const int & v,
  double & sff_ball){
    sff_ball = 0;
    int vert_1, vert_2, vert_3;
    Eigen::VectorXd xi, xj, xk, ui, uj, uk;
    double sff_store;


    for (Eigen::SparseVector<double>::InnerIterator it(A_ratio_at_v); it; ++it)
    {
      int i = it.index();

      vert_1 = F(i,0);
      vert_2 = F(i,1);
      vert_3 = F(i,2);

      xi = V.row(vert_1);
      xj = V.row(vert_2);
      xk = V.row(vert_3);

      ui = N.row(vert_1);
      uj = N.row(vert_2);
      uk = N.row(vert_3);
      
      second_fundamental_form(X,Y,xi, xj, xk, ui, uj, uk, sff_store);
      sff_ball = sff_ball + it.value()*sff_store;
    }
  }