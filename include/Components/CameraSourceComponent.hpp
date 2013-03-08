/* 
 * File:   CameraSourceComponent.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 22:38
 */

#ifndef CAMERASOURCECOMPONENT_HPP
#define	CAMERASOURCECOMPONENT_HPP

#include "Components/Component.hpp"

struct CameraSourceComponent : Component
{
	CameraSourceComponent(float offsetX, float offsetY, float offsetZ, 
							float sourceWidth, float sourceHeight, int EID);

	float offsetX, offsetY, offsetZ;
	float sourceHeight, sourceWidth;
};

#endif	/* CAMERASOURCECOMPONENT_HPP */

