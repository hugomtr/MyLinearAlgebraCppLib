/**
 * @file vector.hpp
 * @author hugomtr
 * @brief 
 * @version 0.1
 * @date 2022-02-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <array>
#include "core.hpp"

namespace jmk {

#define DIM2 2
#define DIM3 3

#define X 0
#define Y 1
#define Z 2

template<class coordinate_type, size_t dimension = DIM3> 
class Vector {
    static_assert(dimension >= DIM2,"Dimensions must be > 2");

    std::array<coordinate_type, dimension> coords;

    public:
        Vector() {}

        Vector(std::array<coordinate_type, dimension> _coords): coords(_coords) {}

        Vector(coordinate_type _x, coordinate_type _y, coordinate_type _z): coords({_x, _y, _z}) {}

        Vector(coordinate_type _x, coordinate_type _y): coords({_x, _y}) {}

        // Equality Check
        bool operator==(const Vector<coordinate_type,dimension>&);

        //Not Equal
        bool operator!=(const Vector<coordinate_type,dimension>&);

        //Addition
        Vector<coordinate_type,dimension> operator+(const Vector<coordinate_type,dimension>&) const;

        //Substraction 
        Vector<coordinate_type,dimension> operator-(const Vector<coordinate_type,dimension>&) const;

        //Less than operator
        bool operator<(const Vector<coordinate_type,dimension>&);

        //Greater than operator
        bool operator>(const Vector<coordinate_type,dimension>&);

        // Access one coordinate
        coordinate_type operator[](int) const;

        // Assign
        void assign(coordinate_type,int);

        // dot product
        float dotProd(const Vector<coordinate_type,dimension>&) const; 

        // cross product
        Vector<coordinate_type,dimension> crossProd3d(const Vector<coordinate_type,dimension>&) const;

        float crossProd2d(const Vector<coordinate_type,dimension>&) const;

        // norm 2
        float norm2(void);

        // normalized vector
        Vector<coordinate_type,dimension> normalize(void) const;

        // Returns the underline array object 
		std::array<coordinate_type, dimension> data();
};


typedef Vector<float, DIM2> Vector2f;
typedef Vector<float, DIM3> Vector3f;


template <class coordinate_type, size_t dimension>
inline bool Vector<coordinate_type,dimension>::operator==(const Vector<coordinate_type,dimension>& _other){
    for (size_t i =0; i<dimension;i++){
        if (isEqualD(coords[i],_other.coords[i])){
            return false;
        }
    }
    return true;
};

template <class coordinate_type, size_t dimension>
inline bool Vector<coordinate_type,dimension>::operator!=(const Vector<coordinate_type,dimension>& _other){
    return !(this==(_other));
};

template <class coordinate_type, size_t dimension>
inline Vector<coordinate_type,dimension> Vector<coordinate_type,dimension>::operator+(const Vector<coordinate_type,dimension>& _other) const {
    std::array<coordinate_type, dimension> new_coords;
    for(size_t i = 0; i<dimension;i++){
        new_coords[i] = coords[i] - _other.coords[i];   
    }
    return Vector<coordinate_type,dimension>(new_coords);
};


template <class coordinate_type, size_t dimension>
inline Vector<coordinate_type,dimension> Vector<coordinate_type,dimension>::operator-(const Vector<coordinate_type,dimension>& _other) const {
    std::array<coordinate_type, dimension> new_coords;
    for(size_t i = 0; i<dimension;i++){
        new_coords[i] = coords[i] - _other.coords[i];   
    }
    return Vector<coordinate_type,dimension>(new_coords);
};

template <class coordinate_type, size_t dimension> 
inline bool Vector<coordinate_type,dimension>::operator<(const Vector<coordinate_type,dimension>& _other){
    for (size_t i = 0; i<dimension;i++){
        if (coords[i] <= _other.coords[i]) {
            return false;
        }
    }
    return true;
};

template <class coordinate_type, size_t dimension>
inline bool Vector<coordinate_type,dimension>::operator>(const Vector<coordinate_type,dimension>& _other){
    for (size_t i = 0; i<dimension;i++){
        if (coords[i] >= _other.coords[i]) {
            return false;
        }
    }
    return true;
};

template <class coordinate_type, size_t dimension>
inline coordinate_type Vector<coordinate_type,dimension>::operator[](int index) const{
    if (index < 0 || index >= dimension){
        std::cout << "Index out of bounds " << std::endl;
        return coordinate_type();
    }
    return this->coords[index];
};

template <class coordinate_type, size_t dimension>
inline void Vector<coordinate_type,dimension>::assign(coordinate_type value,int index) {
    coords[index] = value;
};


template <class coordinate_type, size_t dimension>
inline float Vector<coordinate_type,dimension>::dotProd(const Vector<coordinate_type,dimension>& vec) const {
    float res = 0;
    for (size_t i=0; i<dimension; i++){
        res += coords[i] * vec[i];
    }
    return res;
};

template <class coordinate_type, size_t dimension>
inline Vector<coordinate_type,dimension> Vector<coordinate_type,dimension>::crossProd3d(const Vector<coordinate_type,dimension>& vec) const {
    std::array<coordinate_type,dimension> vec_res;
    if (dimension == 2){
        std::cout << "only for size 3 vectors" << std::endl;
        exit(1);
    }
    vec_res[0] = coords[1] * vec[2] - coords[2]*vec[1]; 
    vec_res[1] = -coords[0] * vec[2] + coords[2]*vec[0];
    vec_res[2] = coords[0] * vec[1] - coords[1]*vec[0];
    return Vector<coordinate_type,dimension>(vec_res);
};

template <class coordinate_type, size_t dimension>
inline float Vector<coordinate_type,dimension>::crossProd2d(const Vector<coordinate_type,dimension>& vec) const {
    return coords[0] * vec[1] - coords[1]*vec[0];
};

template <class coordinate_type, size_t dimension>
inline float Vector<coordinate_type, dimension>::norm2(void) {
    float norm2 = 0.0;
    for (size_t i = 0; i < dimension; ++i){
        norm2 = norm2 + coords[i]*coords[i];
    }
    return sqrt(norm2);
};

template <class coordinate_type, size_t dimension>
inline Vector<coordinate_type,dimension> Vector<coordinate_type,dimension>::normalize(void) const {
    float norm2 = 0.0;
    for (size_t i = 0; i < dimension; ++i){
        norm2 = norm2 + coords[i]*coords[i];
    }
    norm2 = sqrt(norm2);

    std::array<coordinate_type,dimension> vec_norm;
    
    for (size_t i = 0; i < dimension; ++i){
        vec_norm[i] = coords[i]/norm2;
    }
    return Vector<coordinate_type,dimension>(vec_norm);
};

Vector3f crossProduct3d(Vector3f a, Vector3f b);

float crossProduct2d(Vector2f a, Vector2f b);

Vector2f perpendicluar(Vector2f&);

float scalerTripleProduct(Vector3f a, Vector3f b, Vector3f c);

bool orthogonal(Vector3f a, Vector3f b);
}
