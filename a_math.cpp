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

aMath::Vec2 aMath::add(const aMath::Vec2& a, const aMath::Vec2& b) { return aMath::Vec2(a.x + b.x, a.y + b.y); }
aMath::Vec2 aMath::subtract(const aMath::Vec2& a, const aMath::Vec2& b) { return aMath::Vec2(a.x - b.x, a.y - b.y); }
aMath::Vec2 aMath::mul(const aMath::Vec2& a, const aMath::Vec2& b) { return aMath::Vec2(a.x * b.x, a.y * b.y); }
aMath::Vec2 aMath::mul(float a, const aMath::Vec2& b) { return aMath::Vec2(a * b.x, a * b.y); }
float aMath::dot(const aMath::Vec2& a, const aMath::Vec2& b) { return ((a.x * b.x) + (a.y * b.y)); }

aMath::Vec3 aMath::add(const aMath::Vec3& a, const aMath::Vec3& b) { return aMath::Vec3(a.x + b.x, a.y + b.y, a.z + b.z); }
aMath::Vec3 aMath::subtract(const aMath::Vec3& a, const aMath::Vec3& b) { return aMath::Vec3(a.x - b.x, a.y - b.y, a.z - b.z); }
aMath::Vec3 aMath::mul(const aMath::Vec3& a, const aMath::Vec3& b) { return aMath::Vec3(a.x * b.x, a.y * b.y, a.z * b.z); }
aMath::Vec3 aMath::mul(float a, const aMath::Vec3& b) { return aMath::Vec3(a * b.x, a * b.y, a * b.z); }
aMath::Vec3 aMath::cross(const aMath::Vec3& a, const aMath::Vec3& b) { return aMath::Vec3((a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y * b.x)); }
float aMath::dot(const aMath::Vec3& a, const aMath::Vec3& b) { return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z)); }

aMath::Vec4 aMath::add(const aMath::Vec4& a, const aMath::Vec4& b) { return aMath::Vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
aMath::Vec4 aMath::subtract(const aMath::Vec4& a, const aMath::Vec4& b) { return aMath::Vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
aMath::Vec4 aMath::mul(const aMath::Vec4& a, const aMath::Vec4& b) { return aMath::Vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
aMath::Vec4 aMath::mul(float a, const aMath::Vec4& b) { return aMath::Vec4(a * b.x, a * b.y, a * b.z, a * b.w); }
float aMath::dot(const aMath::Vec4& a, const aMath::Vec4& b) { return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w)); }

aMath::Vec3 aMath::mul(const aMath::Mat3& m, const aMath::Vec3& v)
{
	return {
		(m.values[0] * v.x) + (m.values[3] * v.y) + (m.values[6] * v.z),
		(m.values[1] * v.x) + (m.values[4] * v.y) + (m.values[7] * v.z),
		(m.values[2] * v.x) + (m.values[5] * v.y) + (m.values[8] * v.z)
	};
}
aMath::Vec3 aMath::mul(const aMath::Vec3& v, const aMath::Mat3& m)
{
	return mul(m, v); //aMath::mul(vec3 v, mat3 m)
}
aMath::Vec4 aMath::mul(const aMath::Mat4& m, const aMath::Vec4& v)
{
	return {
		(m.values[0] * v.x) + (m.values[1] * v.y) + (m.values[2] * v.z) + (m.values[3] * v.w),
		(m.values[4] * v.x) + (m.values[5] * v.y) + (m.values[6] * v.z) + (m.values[7] * v.w),
		(m.values[8] * v.x) + (m.values[9] * v.y) + (m.values[10] * v.z) + (m.values[11] * v.w),
		(m.values[12] * v.x) + (m.values[13] * v.y) + (m.values[14] * v.z) + (m.values[15] * v.w)
	};
}
aMath::Vec4 aMath::mul(const aMath::Vec4& v, const aMath::Mat4& m)
{
	return mul(m, v); // aMath::mul(vec4 v, mat4 m)
}

aMath::Mat3 aMath::mul(float a, const aMath::Mat3& m)
{
	aMath::Mat3 retMatrix;
	for (int i = 0; i < sizeof(m.values) / sizeof(float); i++)
	{
		retMatrix.values[i] = a * m.values[i];
	}
	return retMatrix;
}
aMath::Mat4 aMath::mul(float a, const aMath::Mat4& m)
{
	aMath::Mat4 retMatrix;
	for (int i = 0; i < sizeof(m.values) / sizeof(float); i++)
	{
		retMatrix.values[i] = a * m.values[i];
	}
	return retMatrix;
}

aMath::Mat3 aMath::mul(const aMath::Mat3& a, const aMath::Mat3& b)
{
	aMath::Mat3 retMatrix;
	for (int i = 0; i < 3; i++)
	{
		float a0 = a.values[i*3+0];
		float a1 = a.values[i*3+1];
		float a2 = a.values[i*3+2];

		retMatrix.values[i*3+0] = a0*b.values[0] + a1*b.values[3] + a2*b.values[6];
		retMatrix.values[i*3+1] = a0*b.values[1] + a1*b.values[4] + a2*b.values[7];
		retMatrix.values[i*3+2] = a0*b.values[2] + a1*b.values[5] + a2*b.values[8];
	}
	return retMatrix;
}
aMath::Mat4 aMath::mul(const aMath::Mat4& a, const aMath::Mat4& b)
{
	aMath::Mat4 retMatrix;
	for (int i = 0; i < 4; i++)
	{
		float a0 = a.values[i*4+0];
		float a1 = a.values[i*4+1];
		float a2 = a.values[i*4+2];
		float a3 = a.values[i*4+3];

		retMatrix.values[i*4+0] = a0*b.values[0] + a1*b.values[4] + a2*b.values[8] + a3*b.values[12];
		retMatrix.values[i*4+1] = a0*b.values[1] + a1*b.values[5] + a2*b.values[9] + a3*b.values[13];
		retMatrix.values[i*4+2] = a0*b.values[2] + a1*b.values[6] + a2*b.values[10] + a3*b.values[14];
		retMatrix.values[i*4+3] = a0*b.values[3] + a1*b.values[7] + a2*b.values[11] + a3*b.values[15];
	}
	return retMatrix;
}

aMath::Mat3 aMath::add(const aMath::Mat3& a, const aMath::Mat3& b)
{
	aMath::Mat3 retMatrix;
	for (int i = 0; i < sizeof(a.values) / sizeof(float); i++)
	{
		retMatrix.values[i] = a.values[i] + b.values[i];
	}
	return retMatrix;
}
aMath::Mat3 aMath::subtract(const aMath::Mat3& a, const aMath::Mat3& b)
{
	aMath::Mat3 retMatrix;
	for (int i = 0; i < sizeof(a.values) / sizeof(float); i++)
	{
		retMatrix.values[i] = a.values[i] - b.values[i];
	}
	return retMatrix;
}
aMath::Mat4 aMath::add(const aMath::Mat4& a, const aMath::Mat4& b)
{
	aMath::Mat4 retMatrix;
	for (int i = 0; i < sizeof(a.values) / sizeof(float); i++)
	{
		retMatrix.values[i] = a.values[i] + b.values[i];
	}
	return retMatrix;
}
aMath::Mat4 aMath::subtract(const aMath::Mat4& a, const aMath::Mat4& b)
{
	aMath::Mat4 retMatrix;
	for (int i = 0; i < sizeof(a.values) / sizeof(float); i++)
	{
		retMatrix.values[i] = a.values[i] - b.values[i];
	}
	return retMatrix;
}

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