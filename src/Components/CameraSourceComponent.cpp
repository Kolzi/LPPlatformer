/* 
 * File:   CameraSourceComponent.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 22:38
 */

#include "Components/CameraSourceComponent.hpp"

CameraSourceComponent::CameraSourceComponent(float offsetX, float offsetY, float offsetZ, 
						float sourceWidth, float sourceHeight,  int EID)
:Component(EID),offsetX(offsetX), offsetY(offsetY), offsetZ(offsetZ), 
	sourceHeight(sourceHeight), sourceWidth(sourceWidth) 
{}
