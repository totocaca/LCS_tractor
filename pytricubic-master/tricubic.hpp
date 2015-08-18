#include <string>
#include <sstream>
#include <iomanip>
#include <Eigen/Dense>
#include <boost/version.hpp>
#include <boost/array.hpp>
#include <boost/multi_array.hpp>
#include <boost/python.hpp>
#include <Python.h>

using namespace boost::python;
typedef float fptype;

#ifndef TRI_CUBIC_INTERPOLATOR_H
#define TRI_CUBIC_INTERPOLATOR_H

//This code is adapted from https://github.com/deepzot/likely
class TriCubicInterpolator{
  // Performs tri-cubic interpolation within a 3D periodic grid.
  // Based on http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.89.7835
  public:
    TriCubicInterpolator(list data, list nkpoints);
    fptype ip(list xyz);
  private:
    boost::multi_array<fptype,1> _data;
    fptype _spacing;
    int _n1, _n2, _n3;
    int _i1, _i2, _i3;
    bool _initialized;

    Eigen::Matrix<fptype,64,1> _coefs;
    Eigen::Matrix<fptype,64,64> _C;
    inline int _index(int i1, int i2, int i3) const {
        if((i1 %= _n1) < 0) i1 += _n1;
        if((i2 %= _n2) < 0) i2 += _n2;
        if((i3 %= _n3) < 0) i3 += _n3;
        return i1 + _n1*(i2 + _n2*i3);
	}
};

#endif
