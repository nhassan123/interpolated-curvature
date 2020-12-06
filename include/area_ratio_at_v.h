#ifndef AREA_RATIO_AT_V
#define AREA_RATIO_AT_V
#include <Eigen/Core>
#include <Eigen/Sparse>
/*
This function computes a list of area ratios at a specific vertex, indexed by v
Inputs:
	v 		vertex index in [0, #V - 1] into V
	A 		#V by #V adjacency matrix
	F 		#F by 3 list of mesh face indices into V
	A_ratio #F by 3 list of internal angle (area) ratios incident on respective corner
Outputs:
	area_ratio_list_v	#A(v).nonzeros()-1 list of area ratios at vertex v, in the order of appearance in F 

For a given vertex index v in [0, #V-1], search F for all occurences of that index.
For each occurence in F, reference the corresponding entry in A_ratio to obtain the angle ratio.
*/
void area_ratio_at_v(
  const int v,
  const Eigen::MatrixXi & F, 
  const Eigen::MatrixXd & A_angles,
  const Eigen::MatrixXd & Areas,
  const double r,
  Eigen::VectorXd & area_ratio_list_v);

#endif
