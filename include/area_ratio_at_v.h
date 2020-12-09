#ifndef AREA_RATIO_AT_V
#define AREA_RATIO_AT_V
#include <Eigen/Core>
#include <Eigen/Sparse>
/*
This function computes a list of area ratios at a specific vertex v
Inputs:
	v 		vertex index in [0, #V - 1] into V
	V 		#V by 3 list of mesh vertex positions
	F 		#F by 3 list of mesh face vertex indices
	A_angles #F by 3 list of internal angle (area) ratios incident on respective corner
  	r     Scale parameter (radius)
Outputs:
	area_ratio_list_v	#V by 1 list of area ratios at vertex v, in the order of appearance in F 

*/
void area_ratio_at_v(
  const int v,
  const Eigen::MatrixXd & V, 
  const Eigen::MatrixXi & F, 
  const Eigen::MatrixXd & A_angles,
  const Eigen::MatrixXd & Areas,
  const double r,
  Eigen::SparseVector<double> & area_ratio_list_v);

#endif
