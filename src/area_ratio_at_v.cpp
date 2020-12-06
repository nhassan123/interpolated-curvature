#include "../include/area_ratio_at_v.h"
#include <iostream>

void area_ratio_at_v(
  const int v,
  const Eigen::MatrixXi & F, 
  const Eigen::MatrixXd & A_ratio,
  Eigen::VectorXd & area_ratio_list_v)
  {
 /*   std::cout << "1" << std::endl;
    Eigen::SparseMatrix <double> vec = A.row(v);

    int num_of_incident_edges = vec.nonZeros() - 1;

    std::cout << vec << std::endl;

    std::cout << "1" << std::endl;

  	area_ratio_list_v = Eigen::VectorXd::Zero(num_of_incident_edges);

    std::cout << "1" << std::endl;
  	int j = 0;		//counter to iterate through area_ratio_list_v

      for (int f = 0; f < F.rows(); ++f)
      {
    		for (int i = 0; i < 3; ++i)
    		{
      		if (F(f, i) == v)
    			{
            std::cout << "i:" << i << "j:" << j << std::endl;
            std::cout << area_ratio_list_v << std::endl;
            std::cout << A_ratio(f, i) << std::endl;
    				area_ratio_list_v(j) = A_ratio(f, i);
    				j += 1;
    			}
    		}
      }*/
      Eigen::VectorXd area_list_v = Eigen::VectorXd::Zero(F.rows());
      double sum = 0;
      for (int f = 0; f < F.rows(); ++f)
      {
        for (int i = 0; i < 3; ++i)
        {
          if (F(f, i) == v)
          {
            //std::cout << f << std::endl;
            area_list_v(f) = A_ratio(f, i);
            sum += A_ratio(f, i);
          }
        }
      }
      area_ratio_list_v = area_list_v / sum;

  }

