# include <iostream>
# include <Eigen/Dense>
# include <Eigen/SVD>


Eigen::VectorXd gradiente_coniugato(Eigen::MatrixXd A, Eigen::VectorXd b, int it_max, double tol) {
    int n = b.size();

    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
    Eigen::VectorXd res = b - A * x;
    Eigen::VectorXd p = res;

   int it = 0 ;

    while (it < it_max && res.norm() > /*res_tol*res_norm*/ tol) {
        const double alpha_k = ((p.transpose() * res) / (p.transpose() * A * p)).value();
        x = x + alpha_k * p;
        res = b - A * x;
        const double beta_k = ((p.transpose() * A * res) / (p.transpose() * A * p)).value();
        p =res - beta_k * p;
        it++;

    }
    return x;
}