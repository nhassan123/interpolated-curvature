#include "../include/mu_ball.h"
#include "../include/corrected_area.h"
#include "../include/mean_density.h"
#include "../include/gaussian.h"
#include <iostream> 

void mu_ball(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio_at_v,
  const int & v,
  double & area_ball,
  double & mean_density_ball,
  double & gaussian_ball_sum
  ){
      int vert_1, vert_2, vert_3;
      Eigen::VectorXd xi, xj, xk, ui, uj, uk;
      double area_store, gaussian_store, density_store;

      area_ball = 0;
      mean_density_ball = 0;
      gaussian_ball_sum = 0;

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
         
        corrected_area(xi, xj, xk, ui, uj, uj, area_store);
        area_ball = area_ball + it.value()*area_store;   
        mean_density(xi, xj, xk, ui, uj, uj, density_store);
        mean_density_ball = mean_density_ball + it.value()*density_store;
        gaussian(xi, xj, xk, ui, uj, uk, gaussian_store);
        gaussian_ball_sum += it.value()*gaussian_store;
        
      
      }

  }
