#include "../include/internal_angles.h"

void internal_angles(
  const Eigen::MatrixXd & l_sqr,
  Eigen::MatrixXd & A_angles)
{
  // Add with your code
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

}
