//Camera.h
///////////////////////////////////////////////////////////
#pragma once
#include "../GameCore.h"

class RayCamera
{
public:
	Point3D m_p3dPosition, m_p3dFocalPoint;
	double m_dFocalLength, m_dStepSize, m_dWidth, m_dHeight;
	int m_iWidth, m_iHeight, m_iFOVAngle;
	Matrix3D m_m3dCameraMatrix;
	RayCamera();
	void _Initialize(int w, int h, int angle);
	Point3D _CreateRay(int x, int y);
	void _Draw(int *video, int w, int h);
}

	