#include "../include/area_ratio_at_v.h"
#include <iostream>

void area_ratio_at_v(
  const int v,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F, 
  const Eigen::MatrixXd & A_angles,
  const Eigen::MatrixXd & Areas,
  const double r,
  Eigen::SparseVector<double> & area_ratio_list_v)
  {
    area_ratio_list_v.resize(F.rows());

    double sum = 0;

    for (int f = 0; f < F.rows(); ++f)
    {

      bool face_contained = true;

      for (int i = 0; i < 3; ++i)
      {

        if (F(f, i) == v)         //checking all incident triangles
        {
          
          area_ratio_list_v.coeffRef(f) = A_angles(f, i) * r * r / (2 * Areas(f)); //for a circular section, A = theta/2 * r^2

        }

        if ((V.row(F(f, i)) - V.row(v)).norm() > r)    //checking to see if triangle is entirely contained by the ball
        {
          face_contained = false;
        }

      }

      if (face_contained)
      {
        area_ratio_list_v.coeffRef(f) = 1;
        
      }
    }     

  }

