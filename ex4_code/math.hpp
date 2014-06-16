#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <AL/alut.h>

template <typename T, unsigned int Dim>
using vec_type = Eigen::Matrix< T, Dim, 1 >;

typedef vec_type< double, 3 > vec3_type;