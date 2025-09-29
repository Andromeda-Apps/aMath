#include "a_math.h"

void aMath::identity(aMath::Mat3& matrix)
{
	std::memset(matrix.values, 0, sizeof(matrix.values));
	matrix.values[0] = 1.0;
	matrix.values[4] = 1.0;
	matrix.values[8] = 1.0;
}
void aMath::identity(aMath::Mat4& matrix)
{
	std::memset(matrix.values, 0, sizeof(matrix.values));
	matrix.values[0] = 1.0;
	matrix.values[5] = 1.0;
	matrix.values[10] = 1.0;
	matrix.values[15] = 1.0;
}

float aMath::dot(const aMath::Vec2& a, const aMath::Vec2& b) { return ((a.x * b.x) + (a.y * b.y)); }

aMath::Vec3 aMath::cross(const aMath::Vec3& a, const aMath::Vec3& b) { return aMath::Vec3((a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y * b.x)); }
float aMath::dot(const aMath::Vec3& a, const aMath::Vec3& b) { return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z)); }

float aMath::dot(const aMath::Vec4& a, const aMath::Vec4& b) { return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w)); }


aMath::Mat4 aMath::translate(float x, float y, float z)
{
	aMath::Mat4 transformation;
	aMath::Vec3 translateVector(x, y, z);
	transformation.translate(translateVector);
	return transformation;
}
aMath::Mat4 aMath::translate(aMath::Vec3& pos) {return aMath::translate(pos.x, pos.y, pos.z);}

aMath::Mat4 aMath::scale(float x, float y, float z)
{
	aMath::Mat4 transformation;
	aMath::Vec3 scaleVector(x, y, z);
	transformation.scale(scaleVector);
	return transformation;
}
aMath::Mat4 aMath::scale(aMath::Vec3& s) {return aMath::scale(s.x, s.y, s.z);};

aMath::Mat4 aMath::rotateX(float angle) {
	aMath::Mat4 transformation;
	transformation.rotateX(angle);
	return transformation;
}
aMath::Mat4 aMath::rotateY(float angle) {
	aMath::Mat4 transformation;
	transformation.rotateY(angle);
	return transformation;
}
aMath::Mat4 aMath::rotateZ(float angle) {
	aMath::Mat4 transformation;
	transformation.rotateZ(angle);
	return transformation;
}

aMath::Mat4 aMath::orthographic(float left, float right, float top, float bottom, float near, float far)
{
	aMath::Mat4 orthographic_matrix;
	orthographic_matrix.values[0] = 2 / (right - left);
	orthographic_matrix.values[5] = 2 / (top - bottom);
	orthographic_matrix.values[10] = -2 / (far - near);
	orthographic_matrix.values[12] = -(right + left) / (right - left);
	orthographic_matrix.values[13] = -(top + bottom) / (top - bottom);
	orthographic_matrix.values[14] = -(far + near) / (far - near);
	return orthographic_matrix;
}

aMath::Mat4 aMath::perspective(float fov, float aspect, float near, float far)
{
	aMath::Mat4 perspective_matrix;
	float s = 1.0f / (tan( (fov / 2.0f) * (PI / 180.0f) ));
	perspective_matrix.values[0] = s / aspect;
	perspective_matrix.values[5] = s;
	perspective_matrix.values[10] = -( (far + near) / (far - near) );
	perspective_matrix.values[11] = -( (2.0 * far * near) / (far - near) );
	perspective_matrix.values[14] = -1.0;
	perspective_matrix.values[15] = 0.0;
	return perspective_matrix;
}


#pragma region MathFunctions

float aMath::deg_to_rad(float deg) {
	return (deg / 360.0) * (2.0 * PI);
}
float aMath::clamp(float value, float lower, float higher) {
	if (value < lower) return lower;
	if (value > higher) return higher;
	return value;
}

float aMath::min(float v1, float v2) {
	return (v1 < v2) ? v1 : v2;
}
float aMath::max(float v1, float v2) {
	return (v1 > v2) ? v1 : v2;
}

#pragma endregion MathFunctions