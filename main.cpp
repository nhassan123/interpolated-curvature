#include "include/anisotropic_measure.h"
#include "include/compute_big_M.h"
#include "include/curvatures_at_point.h"
#include <igl/avg_edge_length.h>
#include <igl/read_triangle_mesh.h>
#include <igl/parula.h>
#include <igl/doublearea.h>
#include <igl/opengl/glfw/Viewer.h>
#include <Eigen/Core>


int main(int argc, char *argv[])
{
  // Scale for the color axis
  double scale = 100.0;
  Eigen::MatrixXd V;
  Eigen::MatrixXi F;
  // Load input meshes
  igl::read_triangle_mesh(
    (argc>1?argv[1]:"../data/cactus.obj"),V,F);

  Eigen::SparseMatrix<double> M;
  igl::massmatrix(V,F,igl::MASSMATRIX_TYPE_DEFAULT,M);
  Eigen::VectorXd A = M.diagonal();

  //std::cout << M << std::endl;
  //std::cout << A << std::endl;

  Eigen::VectorXd D,G,H,K1,K2;
  Eigen::MatrixXd D1,D2;

  int K = 1000;
  double r = 0.001;

  curvatures_at_point(K, r, V, F, D1, D2, K1, K2, G, H);
  // Angle defect ~ locally integrated Gaussian curvature
  //angle_defect(V,F,D);
  // average locally (i.e., "un-integrate" to pointwise quantity for
  // visualization)
  //G = D.array()/A.array();
  //mean_curvature(V,F,H);
  //principal_curvatures(V,F,D1,D2,K1,K2);

  igl::opengl::glfw::Viewer viewer;
  std::cout<<R"(
S,s      Stretch, squish color axis range
G        Show Gaussian curvature (using product of K1 and K2)
g        Show Gaussian curvature (using curvatures_at_point)
M        Show discrete mean curvature (using average of K1 and K2)
m        Show discrete mean curvature (using curvatures_at_point)
K, k     Increase, decrease K (should be significantly greater than maximal curvature)
R, r     Increase, decrease radius of ball (warning: slow for large r)
D,d      Show corrected principal curvature directions (using curvatures_at_point)
C        Show corrected first principal curvatures (using curvatures_at_point)
c        Show corrected second principal curvatures (using curvatures_at_point) 
)";
  
  //Default to mean curvature
  //Eigen::VectorXd Z = H;
  //Default to all zeros
  Eigen::VectorXd Z = Eigen::VectorXd::Zero(V.rows());
  const auto update = [&]()
  {
    Eigen::MatrixXd C;
    igl::parula(Z,-scale,scale,C);
    viewer.data().set_colors(C);
  };
  viewer.callback_key_pressed = 
    [&](igl::opengl::glfw::Viewer &, unsigned int key, int mod)
  {
    switch(key)
    {
      case 'D':
      case 'd':
        viewer.data().show_overlay ^= 1;
        break;
      case 'G':
        Z = K1.array()*K2.array();
        break;
      case 'g':
        Z = G;
        break;
      case 'K':
      case 'k':
        K *= key =='K' ? 10.0 : 0.1;
        std::cout <<"Recalculating..." << std::endl;
        curvatures_at_point(K, r, V, F, D1, D2, K1, K2, G, H);
        std::cout <<"K: " << K << std::endl;
        break;
      case 'M':
        Z = 0.5*(K1+K2);
        break;
      case 'm':
        Z = H;
        break;
      case 'S':
      case 's':
        scale *= key=='S' ? 2.0 : 0.5;
        std::cout<<"Color axis range: ["<<-scale<<","<<scale<<"]"<<std::endl;
        break;
      case 'C':
        Z = K1;
        break;
      case 'c':
        Z = K2;
        break;
      case 'R':
      case 'r':
        r *= key =='R' ? 10.0 : 0.1;
        std::cout <<"Recalculating..." << std::endl;
        curvatures_at_point(K, r, V, F, D1, D2, K1, K2, G, H);
        std::cout <<"Radius: " << r << std::endl;
        break;
      default:
        return false;
    }
    update();
    return true;
  };

  viewer.data().set_mesh(V,F);
  Eigen::MatrixXd lP(V.rows()*4,3);
  const double h = igl::avg_edge_length(V,F);
  lP << V-0.5*h*D1, V+0.5*h*D1, V-0.5*h*D2, V+0.5*h*D2;
  Eigen::MatrixXi lE(2*V.rows(),2);
  Eigen::MatrixXd lC(2*V.rows(),3);

  const Eigen::RowVector3d orange(1.0,0.7,0.2);
  const Eigen::RowVector3d yellow(1.0,0.9,0.2);
  const Eigen::RowVector3d blue(0.2,0.3,0.8);
  for(int e = 0;e<V.rows();e++)
  {
    lE(e,0)          = e+0*V.rows();
    lE(e,1)          = e+1*V.rows();
    lE(V.rows()+e,0) = e+2*V.rows();
    lE(V.rows()+e,1) = e+3*V.rows();
    lC.row(         e) = orange;
    lC.row(V.rows()+e) = blue;
  }
  viewer.data().set_edges(lP,lE,lC);

  update();
  viewer.data().show_lines = false;
  viewer.data().show_overlay = false;
  viewer.data().face_based = false;
  viewer.launch();
  return EXIT_SUCCESS;
}
