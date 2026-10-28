#ifndef TRANSFORM2D_HPP_6A31CA41_7EDF_4BBD_BE8D_02F8ECD4A79D
#define TRANSFORM2D_HPP_6A31CA41_7EDF_4BBD_BE8D_02F8ECD4A79D

#include "stdtypes.hpp"

// For simplicity, these are defined only for Mat22f, i.e., the 2x2 float
// matrix type.
inline 
Mat22f make_scaling_2d( float aX, float aY ) noexcept
{
	return {
		aX,  0.f,
		0.f, aY
	}; //TODO: implement me
}
inline 
Mat22f make_scaling_2d( float aUniform ) noexcept
{
	return make_scaling_2d( aUniform, aUniform ); //TODO: implement me
}
inline
Mat22f make_rotation_2d( float aAngleInRadians ) noexcept
{
	float c = std::cos( aAngleInRadians );
	float s = std::sin( aAngleInRadians );
	return {
		c, -s,
		s,  c
	}; //TODO: implement me
}

#endif // TRANSFORM2D_HPP_6A31CA41_7EDF_4BBD_BE8D_02F8ECD4A79D
