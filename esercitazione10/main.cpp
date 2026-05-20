# include <iostream>
# include <cmath>
# include <Eigen/Dense>
# include <Eigen/SVD>
# include "gradiente_coniugato.hpp"

int main() {
    const double tol = 1.0e-15;
    unsigned int n = 10;
    const unsigned int it_max = 10000;

    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

    if (std::abs(B.determinant()) < tol) {
        return -1;}

    Eigen::MatrixXd A = B.transpose() * B;
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
    Eigen::VectorXd b = A * x_ex;

    Eigen::VectorXd x = gradiente_coniugato(A,b,it_max,tol);
    std::cout<< std::scientific<< "soluzione"<< std::endl;
    std::cout<< std::scientific<< x << std::endl;
    
    return 0;
}