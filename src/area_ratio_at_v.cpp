#include "../include/area_ratio_at_v.h"

void area_ratio_at_v(
  const int v,
  const Eigen::SparseMatrix<double>& A,
  const Eigen::MatrixXi & F, 
  const Eigen::MatrixXd & A_ratio,
  Eigen::VectorXd & area_ratio_list_v)
  {
    num_of_incident_edges = A.row(v).nonZeros() - 1;

	area_ratio_list_v.resize(num_of_incident_edges_to_v);

	int j = 0;		//counter to iterate through area_ratio_list_v

    for (int f = 0; f < F.rows(); ++f)
    {
  		for (int i = 0; i < 3; ++i)
  		{
  			if (F(f, i) == v)
			{
				area_ratio_list(j) = A_ratio(f, i);
				j += 1;
			}
  		}
    }
  }

