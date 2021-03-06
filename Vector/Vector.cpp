// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//Author: Egemen Gungor

#include "Vector.h"
#include <limits>
#include <cmath>

float clamp(float x, float min, float max);

const Vector4 Vector4::one = Vector4(1, 1, 1, 1);
const Vector4 Vector4::zero = Vector4(0, 0, 0, 0);
const Vector4 Vector4::negativeInfinity = Vector4(-std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity());
const Vector4 Vector4::positiveInfinity = Vector4(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());

const Vector3 Vector3::forward = Vector3(0, 0, 1);
const Vector3 Vector3::back = Vector3(0, 0, -1);
const Vector3 Vector3::left = Vector3(-1, 0, 0);
const Vector3 Vector3::right = Vector3(1, 0, 0);
const Vector3 Vector3::up = Vector3(0, 1, 0);
const Vector3 Vector3::down = Vector3(0, -1, 0);
const Vector3 Vector3::one = Vector3(1, 1, 1);
const Vector3 Vector3::zero = Vector3(0, 0, 0);
const Vector3 Vector3::negativeInfinity = Vector3(-std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity());
const Vector3 Vector3::positiveInfinity = Vector3(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());

const Vector2 Vector2::left = Vector2(-1, 0);
const Vector2 Vector2::right = Vector2(1, 0);
const Vector2 Vector2::up = Vector2(0, 1);
const Vector2 Vector2::down = Vector2(0, -1);
const Vector2 Vector2::one = Vector2(1, 1);
const Vector2 Vector2::zero = Vector2(0, 0);
const Vector2 Vector2::negativeInfinity = Vector2(-std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity());
const Vector2 Vector2::positiveInfinity = Vector2(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());

//Vector4
bool Vector4::operator == (Vector4 const& p) const
{
	return static_cast<double>((*this - p).SqrMagnitude()) < DBL_EPSILON;
}

bool Vector4::operator !=(Vector4 const& p) const
{
	return static_cast<double>((*this - p).SqrMagnitude()) >= DBL_EPSILON;
}

float Vector4::SqrMagnitude() const
{
	return static_cast<float>(static_cast<double>(x) * x + static_cast<double>(y) * y + static_cast<double>(z) * z + static_cast<double>(w) * w);
}

float Vector4::Magnitude() const
{
	return sqrt(SqrMagnitude());
}

Vector4 Vector4::Normalize() const
{
	const float len = Magnitude();
	return Vector4(x / len, y / len, z / len, w / len);
}

float Vector4::Dot(const Vector4& lhs, const Vector4& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

float Vector4::Distance(const Vector4& from, const Vector4& to)
{
	return (from - to).Magnitude();
}

Vector4 Vector4::Lerp(const Vector4& from, const Vector4& to, float t)
{
	if (t > 1) t = 1;
	else if (t < 0) t = 0;

	return to * t + from * (1 - t);
}

Vector4 Vector4::LerpNoClamp(const Vector4& from, const Vector4& to, float t)
{
	return to * t + from * (1 - t);
}

Vector4 Vector4::Project(const Vector4& vector, const Vector4& normal)
{
	return normal * (Dot(vector, normal) / normal.SqrMagnitude());
}

//Vector3
bool Vector3::operator==(Vector3 const& p) const
{
	return static_cast<double>((*this - p).SqrMagnitude()) < DBL_EPSILON;
}

bool Vector3::operator!=(Vector3 const& p) const
{
	return static_cast<double>((*this - p).SqrMagnitude()) >= DBL_EPSILON;
}

float Vector3::SqrMagnitude() const
{
	return static_cast<float>(static_cast<double>(x) * x + static_cast<double>(y) * y + static_cast<double>(z) * z);
}

float Vector3::Magnitude() const
{
	return sqrt(SqrMagnitude());
}

float Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Vector3 Vector3::Cross(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
}

float Vector3::Angle(const Vector3& from, const Vector3& to)
{
	return acos(clamp(Dot(from.Normalize(), to.Normalize()), -1.0f, 1.0f)) * 57.29578f;
}

float  Vector3::Distance(const Vector3& from, const Vector3& to)
{
	return (from - to).Magnitude();
}

Vector3 Vector3::Lerp(const Vector3& from, const Vector3& to, float delta)
{
	delta = clamp(delta, 0, 1);
	
	return to * delta + from * (1 - delta);
}

Vector3 Vector3::LerpNoClamp(const Vector3& from, const Vector3& to, const float delta)
{
	return to * delta + from * (1 - delta);
}

Vector3 Vector3::MoveTowards(const Vector3& from, const Vector3& to, const float delta)
{
	const Vector3 direction = to - from;

	const float magnitude = direction.Magnitude();

	if (magnitude <= delta || delta < FLT_EPSILON)
	{
		return to;
	}

	return from + (direction / magnitude) * delta;
}

Vector3 Vector3::Project(const Vector3& vector, const Vector3& normal)
{
	const float magnitude = normal.SqrMagnitude();
	if (magnitude < FLT_EPSILON)
		return zero;
	const float dp = Dot(vector, normal) / magnitude;
	return Vector3(normal.x * dp, normal.y * dp, normal.z * dp);
}

Vector3 Vector3::ProjectOnPlane(const Vector3& vector, const Vector3& planeNormal)
{
	const float magnitude = planeNormal.SqrMagnitude();
	if (magnitude < FLT_EPSILON)
		return vector;
	const float dp = Dot(vector, planeNormal);
	return Vector3(vector.x - planeNormal.x * dp / magnitude, vector.y - planeNormal.y * dp / magnitude, vector.z - planeNormal.z * dp / magnitude);
}

Vector3 Vector3::Reflect(const Vector3& vector, const Vector3& normal)
{
	const float dp = -2 * Dot(normal, vector);
	return Vector3(dp * normal.x + vector.x, dp * normal.y + vector.y, dp * normal.z + vector.z);
}

float Vector3::TriangleArea(const Vector3& a, const Vector3& b, const Vector3& c) {
	return abs(Cross((a - c), (b - c)).Magnitude() / 2);
}

bool Vector3::PointTriangleIntersection(const Vector3& point, const Vector3& a, const Vector3& b, const Vector3& c) {
	const float area = TriangleArea(a, b, c);

	const float area1 = TriangleArea(point, b, c);
	const float area2 = TriangleArea(a, point, c);
	const float area3 = TriangleArea(a, b, point);
	
	return fabs(area - (area1 + area2 + area3)) < FLT_EPSILON;
}

bool Vector3::LinePlaneIntersection(Vector3& intersection, const Vector3& direction, const Vector3& origin, const Vector3& normal, const Vector3& plane)
{
	const float d = Dot(normal, direction);

	//Check if they are parallel
	if (fabs(d) < FLT_EPSILON) return false;

	const float x = (Dot(normal, plane - origin)) / d;

	//Check if the plane is behind the line
	if (x < 0) return false;
	
	intersection = origin + direction * x;

	return true;
}

bool Vector3::LineTriangleIntersection(Vector3& intersection, const Vector3& direction, const Vector3& origin, const Vector3& a, const Vector3& b, const Vector3& c)
{	
	const Vector3 edge1 = b - a;
	const Vector3 edge2 = c - a;
	
	const Vector3 normal = Cross(direction, edge2);
	
	float d = Dot(edge1, normal);
	
	if (fabs(d) < FLT_EPSILON) return false;
	
	d = (1.0f / d);
	
	const Vector3 s = origin - a;
	const float u = d * Dot(s, normal);
	if (u < 0.0 || u > 1.0)
		return false;
	const Vector3 q = Cross(s, edge1);
	const float v = d * Dot(direction, q);
	if (v < 0.0 || static_cast<double>(u) + v > 1.0)
		return false;
	
	const float t = d * Dot(edge2, q);
	if (t > FLT_EPSILON)
	{
		intersection = origin + direction * t;
		return true;
	}
		return false;
}

Vector3 Vector3::Normalize() const
{
	const float len = Magnitude();
	return Vector3(x / len, y / len, z / len);
}

//Vector2
bool Vector2::operator==(Vector2 const& p) const
{
	return static_cast<double>((*this - p).SqrMagnitude())< DBL_EPSILON;
}

bool Vector2::operator!=(Vector2 const& p) const
{
	return static_cast<double>((*this - p).SqrMagnitude()) >= DBL_EPSILON;
}

float Vector2::SqrMagnitude() const
{
	return static_cast<float>(static_cast<double>(x) * x + static_cast<double>(y) * y);
}

float Vector2::Magnitude() const
{
	return sqrt(SqrMagnitude());
}

Vector2 Vector2::Normalize() const
{
	const float len = Magnitude();
	return Vector2(x / len, y / len);
}

float Vector2::Angle(const Vector2& from, const Vector2& to)
{
	return acos(clamp(Dot(from.Normalize(), to.Normalize()), -1.0f, 1.0f)) * 57.29578f;
}

float Vector2::Distance(const Vector2& from, const Vector2& to)
{
	return (from - to).Magnitude();
}

float Vector2::Dot(const Vector2& lhs, const Vector2& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

Vector2 Vector2::Lerp(const Vector2& from, const Vector2& to, float delta)
{
	delta = clamp(delta, 0, 1);

	return to * delta + from * (1 - delta);
}

Vector2 Vector2::LerpNoClamp(const Vector2& from, const Vector2& to, float delta)
{
	return to * delta + from * (1 - delta);
}

Vector2 Vector2::MoveTowards(const Vector2& from, const Vector2& to, float delta)
{
	const Vector2 direction = to - from;

	const float magnitude = direction.Magnitude();

	if (magnitude <= delta || delta < FLT_EPSILON)
	{
		return to;
	}

	return from + (direction / magnitude) * delta;
}

Vector2 Vector2::Reflect(const Vector2& vector, const Vector2& normal)
{
	const float dp = -2 * Dot(normal, vector);
	return Vector2(dp * normal.x + vector.x, dp * normal.y + vector.y);
}

Vector2 Vector2::Perpendicular(const Vector2& vector)
{
	return Vector2(-vector.y, vector.x);
}

float Vector2::TriangleArea(const Vector2& a, const Vector2& b, const Vector2& c) {
	return static_cast<float>(abs((static_cast<double>(a.x) * (static_cast<double>(b.y) - c.y) + static_cast<double>(b.x) * 
		(static_cast<double>(c.y) - a.y) + static_cast<double>(c.x) * (static_cast<double>(a.y) - b.y)) / 2.0));
}

bool Vector2::PointTriangleIntersection(const Vector2& point, const Vector2& a, const Vector2& b, const Vector2& c) {
	const float area = TriangleArea(a, b, c);

	const float area1 = TriangleArea(point, b, c);
	const float area2 = TriangleArea(a, point, c);
	const float area3 = TriangleArea(a, b, point);

	return fabs(area - (area1 + area2 + area3)) < FLT_EPSILON;
}

//String operations
std::string Vector2::ToString(int precision) const
{
	char buffer[89];

	snprintf(buffer, 89, "%.*f, %.*f", precision, x, precision, y);

	return std::string(buffer);
}

std::string Vector3::ToString(int precision) const
{
	char buffer[134];

	snprintf(buffer, 134, "%.*f, %.*f, %.*f", precision, x, precision, y, precision, z);

	return std::string(buffer);
}

std::string Vector4::ToString(int precision) const
{
	char buffer[179];

	snprintf(buffer, 179, "%.*f, %.*f, %.*f, %.*f", precision, x, precision, y, precision, z, precision, w);

	return std::string(buffer);
}

float clamp(float x, float min, float max)
{
	if (x < min) x = min;
	else if (x > max) x = max;

	return x;
}