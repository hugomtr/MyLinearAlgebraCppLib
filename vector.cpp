/**
 * @file vector.cpp
 * @author hugo
 * @brief 
 * @version 0.1
 * @date 2022-02-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include "vector.hpp"

namespace jmk {

    double magnitude(jmk::Vector<double> v){
        double res=0;
        for (int i = 0; i < 3;i++){
            res = res + v[i]*v[i];
            std::cout << res << std::endl;
        }
        std::cout << "ok" << res << std::endl;
        return sqrt(res);
    }

    Vector3f crossProduct3d(Vector3f a, Vector3f b){
        float _x,_y,_z;
        _x = a[Y]*b[Z] - a[Z]*b[Y];
        _y = -a[X]*b[Z] + a[Z]*b[X];
        _z = a[X]*b[Y] - a[X]*b[Y];
        return Vector3f(_x,_y,_z);
    }

    float crossProduct2d(Vector2f a, Vector2f b){
        float res;
        return a[X]*b[Y] - a[Y]*b[X];
    }

    float scalerTripleProduct(Vector3f a, Vector3f b, Vector3f c)
    {
        Vector3f b_cross_c = crossProduct3d(b, c);
        float value = a.dotProd(b_cross_c);
        return value;
    }

    bool orthogonal(Vector3f a, Vector3f b)
    {
        float value = a.dotProd(b);
        return isEqualD(value, 0.0);
    }

    Vector2f perpendicluar(Vector2f& vec)
    {
        return Vector2f( vec[Y], -vec[X]);
    }

}