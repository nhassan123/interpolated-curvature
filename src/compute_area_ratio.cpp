#include "../include/compute_area_ratio.h"
#include <igl/squared_edge_lengths.h>
#include <math.h>

void compute_area_ratio(
	const Eigen::MatrixXd & V,
	const Eigen::MatrixXi & F,
	Eigen::MatrixXd & A_ratio){

	const double PI = 3.15149265358979323846;
  
  	//Create l_sqr #F by 3 list squared edge-lengths opposite respective corner
  	Eigen::MatrixXd l_sqr;
	l_sqr.resizeLike(F);
	igl::squared_edge_lengths(V, F, l_sqr);

	//Create A #F by 3 list of internal angles incident on respective corner (radians)
	Eigen::MatrixXd A_angles;
	A_angles.resizeLike(l_sqr);

	for (int i = 0; i < A_angles.rows(); ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
	  		double a = l_sqr(i, j);
	  		double b = l_sqr(i, (j + 1) % 3);
	  		double c = l_sqr(i, (j + 2) % 3);
	  		A_angles(i, j) = acos((a - b - c) / (-2 * sqrt(b) * sqrt(c)));
	  	}
	}

	//Create A_ratio = A / 2*pi
	A_ratio.resizeLike(A_angles);
	A_ratio = A_angles / (2 * PI);
	//A_ratio = Eigen::MatrixXd::Zero(5,5);
  }



