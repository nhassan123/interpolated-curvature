# interpolated-curvature

# Interpolated corrected curvature measures for polygonal surfaces - paper implementation

  
  

## Interpolated Corrected Curvature Measures

This paper introduces new corrected curvature measures that are used to formulate corrected curvatures on polyhedral surfaces. There are four corrected curvature measures that are built. In our implementation, separate functions were written to calculate each of these measures for a given triangle.

  

The first measure is <img src="https://render.githubusercontent.com/render/math?math=\mu^{(0)}>}, which is the corrected area density of a given triangle. In order to calculate this, the position of the vertices of the triangle $x_{i}$, $x_{j}$, $x_{k}$ along with the vectors describing the normals at each vertex $u_{i}$, $u_{j}$, $u_{k}$ are used.

  

$$ \mu^{(0)}_{\tau_{ijk}} = \frac{1}{2} \langle \overline{u} \mid (x_{j} - x_{i}) \times (x_{k} - x_{i}) \rangle$$

where $\overline{u}$ is the average of the three normals denoted by $\frac{1}{3}$ $(u_{i}+u_{j}+u_{k})$ and $\tau_{ijk}$ denotes a triangle. The operation $\langle \cdot \mid \cdot \rangle$ represents the dot product of two vectors.

  

The function for this calculation is as follows.

  

    void corrected_area(
        const Eigen::VectorXd & xi,
        const Eigen::VectorXd & xj,
        const Eigen::VectorXd & xk,
        const Eigen::VectorXd & ui,
        const Eigen::VectorXd & uj,
        const Eigen::VectorXd & uk,
        double & area_density
    )

  

The second quantity, $\mu^{(1)}$ is the corrected mean density of a triangle.

  

$$ \mu^{(1)}_{\tau_{ijk}} = \frac{1}{2} \langle \overline{u} \mid (u_{k} - u_{j}) \times x_{i} + (u_{i} - u_{k}) \times x_{j} + (u_{j} - u_{i}) \times x_{k} \rangle$$

  

The function for corrected mean density is below.

  

    void mean_density(
        const Eigen::VectorXd & xi,
        const Eigen::VectorXd & xj,
        const Eigen::VectorXd & xk,
        const Eigen::VectorXd & ui,
        const Eigen::VectorXd & uj,
        const Eigen::VectorXd & uk,
        double & mean_density
        )

  

$\mu^{(2)}$ is defined as the corrected Gaussian curvature density of a triangle.

$$\mu^{(2)}_{\tau_{ijk}} = \frac{1}{2} \langle u_{i} \mid u_{j} \times u_{k} \rangle$$

  

The function for Gaussian curvature density of a triangle is given below.

  

    void gaussian(
	    const Eigen::VectorXd & xi,
	    const Eigen::VectorXd & xj,
	    const Eigen::VectorXd & xk,
	    const Eigen::VectorXd & ui,
	    const Eigen::VectorXd & uj,
	    const Eigen::VectorXd & uk,
	    double & gaussian_curvature
    )

  

The anisotropic measure $\mu^{(X,Y)}$, is defined as the trace of the corrected second fundamental form along two directions X and Y, where X and Y are 3D vectors.

  

$$ \mu^{(X, Y)}_{\tau_{ijk}} = \frac{1}{2} \langle \overline{u} \mid \langle Y \mid (u_{k} - u_{i}) \rangle X \times (x_{j} - x_{i})\rangle - \frac{1}{2} \langle \overline{u} \mid \langle Y \mid (u_{j} - u_{i})\rangle X \times (x_{k} - x_{i}) \rangle$$

  

    void second_fundamental_form(
        const Eigen::VectorXd & X,
        const Eigen::VectorXd & Y,
        const Eigen::VectorXd & xi,
        const Eigen::VectorXd & xj,
        const Eigen::VectorXd & xk,
        const Eigen::VectorXd & ui,
        const Eigen::VectorXd & uj,
        const Eigen::VectorXd & uk,
        double & sff
    )

  

## Corrected Curvature Measures

  

From the interpolated corrected curvature measures, we can obtain the corrected curvature measure associated with $\mu^{(k)}$ on a subset $B$ of $\mathbb{R}^3$ with the following:

  

$$ \mu^{(k)}(B_{\rho}(x)) = \sum_{m=1}^{t} \mu^{(k)}(\tau_m)\frac{Area(\tau_m\cap B_{\rho}(x))}{Area(\tau_m)}$$

  

where the mesh is composed of $t$ triangles $\tau_m$ and the area ratios $\frac{Area(\tau_m\cap B_{\rho}(x))}{Area(\tau_m)}$ provide weighting for each triangle. We take $B = B_{\rho}(x)$ to be a ball in $\mathbb{R}^3$ with centre $x$ and radius $\rho$. The radius is a scale parameter that the user can adjust and it introduces a tradeoff between robustness and accuracy. In our implementation, $\rho = 0.001$ by default.

  

As a simplification, for sufficiently large $\rho$, we approximate the area ratios to be $1$ if the triangle $\tau_m$ is entirely inside of the ball, and $0$ if it is not. We do this by comparing the distance between each vertex of $\tau_m$ and the ball centre $x$. However, when we are considering a ball centered on a vertex, the area ratios of the adjacent faces will map to $(0, 1]$ exactly. We calculate this ratio utilizing the internal angles. This is a more precise approximation than the demo linked in the paper, where all triangle ratios are mapped to $\{0, 1\}$.

  
  

## Corrected Mean and Gaussian Curvatures

The corrected mean and corrected Gaussian curvatures are calculated using the interpolated corrected curvature methods for each ball $B$ centered at a vertex $x$ with radius $\rho$.

The paper defines the corrected mean curvature by using the corrected mean density and corrected area density of each triangle.

$$\hat{H}(x, \rho) := \mu^{(1)}(B_{\rho}(x)) / \mu^{(0)}(B_{\rho}(x)) $$

Using the functions defined above, we can calculate the corrected mean curvature.

`H(v) = mu_1 / mu_0;`

This updates a #$V \times 1$ vector with the mean curvature at the vertex of interest, where $F$ is the number of vertices in our mesh.

  

The image below shows the corrected mean curvatures on the Keenan-Ogre mesh.

  

![Corrected Mean curvature shown on Keenan-Ogre mesh](https://i.ibb.co/tx1dLnp/ogre-mean.png)

Similarly the corrected Gaussian curvature is defined as follows.

  

$$\hat{G}(x, \rho) := \mu^{(2)}(B_{\rho}(x)) / \mu^{(0)}(B_{\rho}(x)) $$

We can calculate the corrected Gaussian curvature.

`G(v) = mu_2 / mu_0;`

The image below shows the corrected Gaussian curvatures on the Keenan-Ogre mesh.

![Corrected Gaussian curvature shown on Keenan-Ogre mesh](https://i.ibb.co/B2sWSBF/ogre-gaussian.png)

  

As mentioned earlier, the anisotropic measure of a triangle represents the trace of the second fundamental form. The anisotropic measures of a triangle can be summed up into a 3x3 matrix using three basis vectors $e_{1}, e_{2}, e_{3}$ .

$$\mu^{(M)} = \left(\begin{array}{ccc}
\mu^{(e_1, e_1)}  & \mu^{(e_1, e_2)}  &  \mu^{(e_1, e_3)}  \\
\mu^{(e_2, e_1)}  & \mu^{(e_2, e_2)}  &  \mu^{(e_2, e_3)}  \\
\mu^{(e_3, e_1)}  & \mu^{(e_3, e_2)}  &  \mu^{(e_3, e_3)}  \\
\end{array}\right)
  $$


## Corrected Principal Curvatures and Directions

We symmetrize the $3\times3$ anisotropic measure $\mu^{(M)}$ over a local subset $B_{\rho}(x)$ and then add a term $Ku(x)u(x)^T$ to ensure that the principal direction eigenvectors are tangent to the surface. $K$ should be chosen such that it is significantly greater than the maximum curvature at any point. We define the modified $3\times3$ matrix as follows:

$$M_{\rho}(x) := \frac{1}{2}(\mu^{(M)}(B_{\rho}(x)) + (\mu^{(M)}(B_{\rho}(x)))^T) + Ku(x)u(x)^T $$

By performing an eigendecomposition, we obtain the corrected first and second principal curvatures $\hat{v}_1, \hat{v}_1$ and corrected first and second principal curvature directions $\hat{\kappa}_1, \hat{\kappa}_2$:

$$\hat{\kappa}_1(x, \rho) := \frac{-\lambda_2}{\mu^{(0)}(B_{\rho}(x))}$$

$$\hat{v}_1(x, \rho) := \frac{z_2}{\mu^{(0)}(B_{\rho}(x))}$$

$$\hat{\kappa}_2(x, \rho) := \frac{-\lambda_1}{\mu^{(0)}(B_{\rho}(x))}$$

$$\hat{v}_1(x, \rho) := \frac{z_1}{\mu^{(0)}(B_{\rho}(x))}$$

Where $\lambda_1 \le \lambda_2$ are the two smallest eigenvalues of $\mu^{(M)}(B_{\rho}(x))$ and $z1, z2$ the associated eigenvectors.

//ogre picture for corrected principal curvature directions, corrected first and second principal curvatures

//ogre picture for principal curvature directions, first and second principal curvatures (HW07)

We have chosen $K = 1000$.


## Conclusion


In contrast to the previous implementations in [HW07](https://github.com/alecjacobson/geometry-processing-curvature), where we have performed (i) a local fitting of a quadratic surface and (ii) a summation of internal angles to approximate curvature, the approach described in this paper defines curvature quantities as ratios of curvature measures.

  

In our implementation, the normal vector field was extracted from the vertices and faces via `igl::per_vertex_normals`. Unfortunately, this does not demonstrate the true strength of this method. The user is able to use this method to compute curvatures for any prescribed normal vector field at any point, completely uncoupled from the vertex positions. This means that for noisy positional datasets, the user is still able to determine consistent curvatures. In general, this method is robust to noise and is at least as accurate as other state-of-the-art methods on clean datasets (with appropriate radius).

