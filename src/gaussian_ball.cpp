#include "../include/gaussian_ball.h"
#include "../include/gaussian.h"
#include <iostream> 

void gaussian_ball(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & N,
  const Eigen::SparseVector<double> & A_ratio_at_v,
  const int & v,
  double & gaussian_ball_sum
  ){
      int vert_1, vert_2, vert_3;
      Eigen::VectorXd xi, xj, xk, ui, uj, uk;
      double gaussian_store;

      gaussian_ball_sum = 0;
/*      for ( int i =0; i < A_ratio_at_v.rows(); i++){
        if(A_ratio_at_v(i) != 0){
             vert_1 = F(i,0);
              vert_2 = F(i,1);
              vert_3 = F(i,2);

              //xi = V.row(vert_1);
              //xj = V.row(vert_2);
              //xk = V.row(vert_3);

              ui = N.row(vert_1);
              uj = N.row(vert_2);
              uk = N.row(vert_3);
            // std::cout<<"xi: "<<xi(0)<<" "<<xi(1)<<" "<<xi(2)<<std::endl;
            // std::cout<<"xj: "<<xj(0)<<" "<<xj(1)<<" "<<xj(2)<<std::endl;
            // std::cout<<"ui: "<<ui(0)<<" "<<ui(1)<<" "<<ui(2)<<std::endl;
            // std::cout<<"uj: "<<uj(0)<<" "<<uj(1)<<" "<<uj(2)<<std::endl;
            // std::cout<<"uk: "<<uk(0)<<" "<<uk(1)<<" "<<uk(2)<<std::endl; 
            gaussian(xi, xj, xk, ui, uj, uk, gaussian_store);
            gaussian_ball_sum += A_ratio_at_v(i)*gaussian_store;   //need to figure out how this comes in, 
        // not defined rn 
        }
        
      }*/


      for (Eigen::SparseVector<double>::InnerIterator it(A_ratio_at_v); it; ++it)
      {
        int i = it.index();

        vert_1 = F(i,0);
        vert_2 = F(i,1);
        vert_3 = F(i,2);

        //xi = V.row(vert_1);
        //xj = V.row(vert_2);
        //xk = V.row(vert_3);

        ui = N.row(vert_1);
        uj = N.row(vert_2);
        uk = N.row(vert_3);
        // std::cout<<"xi: "<<xi(0)<<" "<<xi(1)<<" "<<xi(2)<<std::endl;
        // std::cout<<"xj: "<<xj(0)<<" "<<xj(1)<<" "<<xj(2)<<std::endl;
        // std::cout<<"ui: "<<ui(0)<<" "<<ui(1)<<" "<<ui(2)<<std::endl;
        // std::cout<<"uj: "<<uj(0)<<" "<<uj(1)<<" "<<uj(2)<<std::endl;
        // std::cout<<"uk: "<<uk(0)<<" "<<uk(1)<<" "<<uk(2)<<std::endl; 
        gaussian(xi, xj, xk, ui, uj, uk, gaussian_store);
        gaussian_ball_sum += it.value()*gaussian_store;   //need to figure out how this comes in, 
        // not defined rn 
      }

  }
