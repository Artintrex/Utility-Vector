//Author: Egemen Gungor
#pragma once
#include <string>

struct Vector4
{
	float x;
	float y;
	float z;
	float w;

	//Static vectors
	static const Vector4 one;
	static const Vector4 zero;
	static const Vector4 negativeInfinity;
	static const Vector4 positiveInfinity;

	//Returns dot product of two vectors
	static float Dot(const Vector4& lhs, const Vector4&rhs);

	//Returns distance between two vectors
	static float Distance(const Vector4& from, const Vector4& to);


	//Linear interpolates between to vectors
	static Vector4 Lerp(const Vector4& from, const Vector4& to, float t);

	//Lerp without clamping
	static Vector4 LerpNoClamp(const Vector4& from, const Vector4& to, float t);

	//Projects a vector on another vector
	static Vector4 Project(const Vector4& vector, const Vector4& normal);

	//Returns unit vector
	[[nodiscard]]
	Vector4 Normalize() const;

	//Returns square magnitude of this vector
	[[nodiscard]]
	float SqrMagnitude() const;

	//Returns magnitude of this vector
	[[nodiscard]]
	float Magnitude() const;

	[[nodiscard]]
	std::string ToString(int precision = 2) const;
	
	/// Constructors
	Vector4() {
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	Vector4(const Vector4& other)
	  : x(other.x),
		y(other.y),
		z(other.z),
		w(other.w)
	{
	}

	Vector4(Vector4&& other) noexcept
	  : x(other.x),
		y(other.y),
		z(other.z),
		w(other.w)
	{
	}

	Vector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) { ; }

	~Vector4() = default;

	/// Arithmetic operators
	Vector4 operator + (Vector4 const& p) const
	{
		return Vector4(x + p.x, y + p.y, z + p.z, w + p.w);
	}

	Vector4 operator - (Vector4 const& p) const
	{
		return Vector4(x - p.x, y - p.y, z - p.z, w - p.w);
	}

	Vector4 operator * (Vector4 const& p) const
	{
		return Vector4(x * p.x, y * p.y, z * p.z, w * p.w);
	}

	Vector4 operator / (Vector4 const& p) const
	{
		return Vector4(x / p.x, y / p.y, z / p.z, w / p.w);
	}

	/// Assignment operators
	Vector4& operator=(const Vector4& other)
	{
		if (this == &other)
			return *this;
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	Vector4& operator=(Vector4&& other) noexcept
	{
		if (this == &other)
			return *this;
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	Vector4 operator += (Vector4 const& p)
	{
		x += p.x; y += p.y; z += p.z; w += p.w;
		return *this;
	}

	Vector4 operator -= (Vector4 const& p)
	{
		x -= p.x; y -= p.y; z -= p.z; w -= p.w;
		return *this;
	}

	Vector4 operator *= (Vector4 const& p)
	{
		x *= p.x; y *= p.y; z *= p.z; w *= p.w;
		return *this;
	}

	Vector4 operator /= (Vector4 const& p)
	{
		x /= p.x; y /= p.y; z /= p.z; w /= p.w;
		return *this;
	}

	/// Arithmetic operators for float
	Vector4 operator + (float const& p) const
	{
		return Vector4(x + p, y + p, z + p, w +p);
	}

	Vector4 operator - (float const& p) const
	{
		return Vector4(x - p, y - p, z - p, w - p);
	}

	Vector4 operator * (float const& p) const
	{
		return Vector4(x * p, y * p, z * p, w * p);
	}

	Vector4 operator / (float const& p) const
	{
		return Vector4(x / p, y / p, z / p, w / p);
	}

	/// Assignation operators for float
	Vector4 operator += (float const& p)
	{
		x += p; y += p; z += p; w += p;
		return *this;
	}

	Vector4 operator -= (float const& p)
	{
		x -= p; y -= p; z -= p; w -= p;
		return *this;
	}

	Vector4 operator *= (float const& p)
	{
		x *= p; y *= p; z *= p; w *= p;
		return *this;
	}

	Vector4 operator /= (float const& p)
	{
		x /= p; y /= p; z /= p; w /= p;
		return *this;
	}

	//Logical operators
	bool operator == (Vector4 const& p) const;
	bool operator !=(Vector4 const& p) const;
};

//Vector3 definition
struct Vector3 {
	float x;
	float y;
	float z;

	//Static vectors
	static const Vector3 forward;
	static const Vector3 back;
	static const Vector3 left;
	static const Vector3 right;
	static const Vector3 up;
	static const Vector3 down;
	static const Vector3 one;
	static const Vector3 zero;
	static const Vector3 negativeInfinity;
	static const Vector3 positiveInfinity;

	///Static methods
	//Returns angle between two vectors
	static float Angle(const Vector3& from, const Vector3& to);

	//Returns cross product of two vectors
	static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);

	//Returns dot product of two vectors
	static float Dot(const Vector3& lhs, const Vector3& rhs);

	//Returns distance between two vectors
	static float Distance(const Vector3& from, const Vector3& to);

	//Linear interpolates between to vectors
	static Vector3 Lerp(const Vector3& from, const Vector3& to, float t);

	//Lerp without clamping
	static Vector3 LerpNoClamp(const Vector3& from, const Vector3& to, float t);

	//Moves a vector to target by delta
	static Vector3 MoveTowards(const Vector3& from, const Vector3& to, float delta);

	//Projects a vector on another vector
	static Vector3 Project(const Vector3& vector, const Vector3& normal);

	//Projects a vector on a plane
	static Vector3 ProjectOnPlane(const Vector3& vector, const Vector3& normalPlane);

	//Reflects a vector using normal vector
	static Vector3 Reflect(const Vector3& vector, const Vector3& normal);

	//Returns unit vector
	[[nodiscard]]
	Vector3 Normalize() const;

	//Returns square magnitude of this vector
	[[nodiscard]]
	float SqrMagnitude() const;

	//Returns magnitude of this vector
	[[nodiscard]]
	float Magnitude() const;

	[[nodiscard]]
	std::string ToString(int precision = 2) const;
	
	/// Constructors
	Vector3() {
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3(const Vector3& other)
		: x(other.x),
		  y(other.y),
		  z(other.z)
	{
	}

	Vector3(Vector3&& other) noexcept
		: x(other.x),
		  y(other.y),
		  z(other.z)
	{
	}

	Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) { ; }
	
	~Vector3() = default;

	/// Arithmetic operators
	Vector3 operator + (Vector3 const& p) const
	{
		return Vector3(x + p.x, y + p.y, z + p.z);
	}

	Vector3 operator - (Vector3 const& p) const
	{
		return Vector3(x - p.x, y - p.y, z - p.z);
	}

	Vector3 operator * (Vector3 const& p) const
	{
		return Vector3(x * p.x, y * p.y, z * p.z);
	}

	Vector3 operator / (Vector3 const& p) const
	{
		return Vector3(x / p.x, y / p.y, z / p.z);
	}

	/// Assignment operators
	Vector3& operator=(const Vector3& other)
	{
		if (this == &other)
			return *this;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	Vector3& operator=(Vector3&& other) noexcept
	{
		if (this == &other)
			return *this;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
	
	Vector3 operator += (Vector3 const& p)
	{
		x += p.x; y += p.y; z += p.z;
		return *this;
	}

	Vector3 operator -= (Vector3 const& p)
	{
		x -= p.x; y -= p.y; z -= p.z;
		return *this;
	}

	Vector3 operator *= (Vector3 const& p)
	{
		x *= p.x; y *= p.y; z *= p.z;
		return *this;
	}

	Vector3 operator /= (Vector3 const& p)
	{
		x /= p.x; y /= p.y; z /= p.z;
		return *this;
	}

	/// Arithmetic operators for float
	Vector3 operator + (float const& p) const
	{
		return Vector3(x + p, y + p, z + p);
	}

	Vector3 operator - (float const& p) const
	{
		return Vector3(x - p, y - p, z - p);
	}

	Vector3 operator * (float const& p) const
	{
		return Vector3(x * p, y * p, z * p);
	}

	Vector3 operator / (float const& p) const
	{
		return Vector3(x / p, y / p, z / p);
	}

	/// Assignation operators for float
	Vector3 operator += (float const& p)
	{
		x += p; y += p; z += p;
		return *this;
	}

	Vector3 operator -= (float const& p)
	{
		x -= p; y -= p; z -= p;
		return *this;
	}

	Vector3 operator *= (float const& p)
	{
		x *= p; y *= p; z *= p;
		return *this;
	}

	Vector3 operator /= (float const& p)
	{
		x /= p; y /= p; z /= p;
		return *this;
	}

	//Logical operators
	bool operator == (Vector3 const& p) const;
	bool operator !=(Vector3 const& p) const;
};


//Vector2 definition
struct Vector2
{
	float x;
	float y;

	//Static vectors
	static const Vector2 left;
	static const Vector2 right;
	static const Vector2 up;
	static const Vector2 down;
	static const Vector2 one;
	static const Vector2 zero;
	static const Vector2 negativeInfinity;
	static const Vector2 positiveInfinity;

	///Static methods
	//Returns angle between two vectors
	static float Angle(const Vector2& from, const Vector2& to);

	//Returns dot product of two vectors
	static float Dot(const Vector2& lhs, const Vector2& rhs);

	//Returns distance between two vectors
	static float Distance(const Vector2& from, const Vector2& to);

	//Linear interpolates between to vectors
	static Vector2 Lerp(const Vector2& from, const Vector2& to, float t);

	//Lerp without clamping
	static Vector2 LerpNoClamp(const Vector2& from, const Vector2& to, float t);

	//Moves a vector to target by delta
	static Vector2 MoveTowards(const Vector2& from, const Vector2& to, float delta);

	//Returns the vector that is perpendicular to the given vector in a counter clock wise direction
	static Vector2 Perpendicular(const Vector2& vector);

	//Reflects a vector using normal vector
	static Vector2 Reflect(const Vector2& vector, const Vector2& normal);

	//Returns unit vector
	[[nodiscard]]
	Vector2 Normalize() const;

	//Returns square magnitude of this vector
	[[nodiscard]]
	float SqrMagnitude() const;

	//Returns magnitude of this vector
	[[nodiscard]]
	float Magnitude() const;

	[[nodiscard]]
	std::string ToString(int precision = 2) const;

	/// Constructors
	Vector2() {
		x = 0;
		y = 0;
	}

	Vector2(const Vector2& other)
	  : x(other.x),
		y(other.y)
	{
	}

	Vector2(Vector2&& other) noexcept
	  : x(other.x),
		y(other.y)
	{
	}

	Vector2(const float x, const float y) : x(x), y(y) { ; }

	~Vector2() = default;

	/// Arithmetic operators
	Vector2 operator + (Vector2 const& p) const
	{
		return Vector2(x + p.x, y + p.y);
	}

	Vector2 operator - (Vector2 const& p) const
	{
		return Vector2(x - p.x, y - p.y);
	}

	Vector2 operator * (Vector2 const& p) const
	{
		return Vector2(x * p.x, y * p.y);
	}

	Vector2 operator / (Vector2 const& p) const
	{
		return Vector2(x / p.x, y / p.y);
	}

	/// Assignment operators
	Vector2& operator=(const Vector2& other)
	{
		if (this == &other)
			return *this;
		x = other.x;
		y = other.y;
		return *this;
	}

	Vector2& operator=(Vector2&& other) noexcept
	{
		if (this == &other)
			return *this;
		x = other.x;
		y = other.y;
		return *this;
	}

	Vector2 operator += (Vector2 const& p)
	{
		x += p.x; y += p.y;
		return *this;
	}

	Vector2 operator -= (Vector2 const& p)
	{
		x -= p.x; y -= p.y;
		return *this;
	}

	Vector2 operator *= (Vector2 const& p)
	{
		x *= p.x; y *= p.y;
		return *this;
	}

	Vector2 operator /= (Vector2 const& p)
	{
		x /= p.x; y /= p.y;
		return *this;
	}

	/// Arithmetic operators for float
	Vector2 operator + (float const& p) const
	{
		return Vector2(x + p, y + p);
	}

	Vector2 operator - (float const& p) const
	{
		return Vector2(x - p, y - p);
	}

	Vector2 operator * (float const& p) const
	{
		return Vector2(x * p, y * p);
	}

	Vector2 operator / (float const& p) const
	{
		return Vector2(x / p, y / p);
	}

	/// Assignation operators for float
	Vector2 operator += (float const& p)
	{
		x += p; y += p;
		return *this;
	}

	Vector2 operator -= (float const& p)
	{
		x -= p; y -= p;
		return *this;
	}

	Vector2 operator *= (float const& p)
	{
		x *= p; y *= p;
		return *this;
	}

	Vector2 operator /= (float const& p)
	{
		x /= p; y /= p;
		return *this;
	}

	//Logical operators
	bool operator == (Vector2 const& p) const;
	bool operator !=(Vector2 const& p) const;
};