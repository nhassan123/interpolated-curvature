#include "../include/area_ball.h"
#include "../include/corrected_area.h"

void area_ball(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXd & F,
  const Eigen::MatrixXd & N,
  const Eigen::MatrixXd & A_ratio_at_v,
  const int & v,
  double & area_ball
  ){
      int vert_1, vert_2, vert_3;
      Eigen::VectorXd xi, xj, xk, ui, uj, uk;
      double area_store;

      area_ball = 0;
      for ( int i =0; i < A_ratio_at_v.rows(); i++){
        vert_1 = F(i,0);
        vert_2 = F(i,1);
        vert_3 = F(i,2);

        xi = V.row(vert_1);
        xj = V.row(vert_2);
        xk = V.row(vert_3);

        ui = N.row(vert_1);
        uj = N.row(vert_2);
        uk = N.row(vert_3);

        corrected_area(xi, xj, xk, ui, uj, uj, area_store);
        area_ball = area_ball + A_ratio_at_v(i)*area_store;   //need to figure out how this comes in, 
        // not defined rn 
      }

  }
