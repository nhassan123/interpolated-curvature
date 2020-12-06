#ifndef AREA_RATIO
#define AREA_RATIO
#include <Eigen/Core>
/*
ASSUMES CLOSED SURFACE
This function returns a list of all area ratios at each vertex

Inputs:
	V 	#V by 3 list of mesh vertex positions
	F 	#F by 3 list of mesh face indices into V
Outputs:
	A_ratio  #F by 3 list of internal angle ratios incident on respective corner

*/

void compute_area_ratio(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & A_ratio);
#endif
