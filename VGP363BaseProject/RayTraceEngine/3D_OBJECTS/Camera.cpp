#include "../GameCore.h"

RayCamera::RayCamera()
{
	this->m_m3dCameraMatrix.SetIdentityMatrix();
	this->m_iWidth = 1920;
	this->m_iHeight = 1080;
	this->m_iFOVAngle = 60;
	this->m_dFocalLength = sqrt(3.0)/2.0;
	this->m_dWidth = 1.0;
	this->m_dStepSize = this->m_dWidth/(double)m_iWidth;
	this->m_dHeight = this->m_dStepSize*(double)m_iHeight;
	this->m_p3dPosition = Point3D(0.0, 0.0, 0.0, 1.0);
	this->m_p3dFocalPoint = Point3D(0.0, 0.0, -1.0*this->m_dFocalLength, 1.0);
}

void _Initialize(int w, int h, int angle)
{
	this->m_iWidth = w;
	this->m_iHeight = h;
	this->m_iFOVAngle;
	this->m_dFocalLength = this->m_dWidth/tan(((double)this->m_iFOVAngle/180.0)*3.14159265359);
	this->m_dWidth = 1.0;
	this->m_dStepSize = this->m_dWidth/(double)m_iWidth;
	this->m_dHeight = this->m_dStepSize*(double)m_iHeight;
	this->m_p3dFocalPoint = Point3D(0.0, 0.0, -1.0*this->m_dFocalLength, 1.0);
}

Point3D _CreateRay(int x, int y)
{
	Point3D RayVector = Point3D(((double)x*this->m_dStepSize)-(0.5*this->m_dWidth), ((double)y*this->m_dStepSize)-(0.5*this->m_dHeight), 0.0, 1.0) - this->m_p3dFocalPoint;
	RayVector = m_m3dCameraMatrix.Multiply(RayVector);
	RayVector.Normalize();
	return RayVector;
}

void _Draw(int *video, int w, int h)
{

}