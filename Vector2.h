#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/* Vector2 with X, Y and usefull functions */
struct Vector2
{
	float X;
	float Y;

	explicit Vector2(float x, float y) : X(x), Y(y) {}

	// Static constructors
	static Vector2 Zero() { return Vector2(0, 0); }
	static Vector2 One() { return Vector2(1, 1); }
	static Vector2 Left() { return Vector2(-1, 0); }
	static Vector2 Right() { return Vector2(1, 0); }
	static Vector2 Up() { return Vector2(0, 1); }
	static Vector2 Down() { return Vector2(0, -1); }

	// Static methods
	static float Magnitude(const Vector2& v)
	{
		return sqrtf((v.X * v.X) + (v.Y * v.Y));
	}
	static float Distance(const Vector2& v1, const Vector2& v2)
	{
		float x = v2.X - v1.X;
		float y = v2.Y - v1.Y;

		return Magnitude(Vector2(x, y));
	}
	static float Determinant(const Vector2& v1, const Vector2& v2)
	{
		return v1.X * v2.Y - v2.X * v1.Y;
	}
	static Vector2 Normalize(const Vector2& v)
	{
		float magn = Magnitude(v);
		return Vector2(
			v.X / magn,
			v.Y / magn
		);
	}

	// Methods
	void Translate(const Vector2& v)
	{
		*this += v;
	}
	void Scale(const Vector2& v)
	{
		*this *= v;
	}
	void Scale(const float& f)
	{
		*this *= f;
	}
	float Magnitude() const
	{
		return Magnitude(*this);
	}
	float Determinant(const Vector2& v) const
	{
		return Determinant(*this, v);
	}
	float Distance(const Vector2& v) const
	{
		return Distance(*this, v);
	}
	Vector2 Normalized() const
	{
		return Normalize(*this);
	}

	// Operator when used with SFML
	operator sf::Vector2f() const { return { X, Y }; }

	// Operators
	Vector2& operator=(const Vector2& v2) = default;

	Vector2& operator+=(const Vector2& v2)
	{
		X += v2.X;
		Y += v2.Y;

		return *this;
	}
	Vector2& operator-=(const Vector2& v2)
	{
		X -= v2.X;
		Y -= v2.Y;

		return *this;
	}
	Vector2& operator*=(const Vector2& v2)
	{
		X *= v2.X;
		Y *= v2.Y;

		return *this;
	}
	Vector2& operator*=(const float& f)
	{
		X *= f;
		Y *= f;

		return *this;
	}
	Vector2& operator/=(const Vector2& v2)
	{
		X /= v2.X;
		Y /= v2.Y;

		return *this;
	}
};

// Operators
inline std::ostream& operator<<(std::ostream& os, const Vector2& v)
{
	os << "X: " << v.X << " Y: " << v.Y << std::endl;
	return os;
}

inline bool operator==(const Vector2& v1, const Vector2& v2)
{
	return v1.X == v2.X && v1.Y == v2.Y;
}
inline bool operator!=(const Vector2& v1, const Vector2& v2)
{
	return !(v1 == v2);
}

inline Vector2 operator+(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.X + v2.X, v1.Y + v2.Y);
}
inline Vector2 operator-(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.X - v2.X, v1.Y - v2.Y);
}
inline Vector2 operator*(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.X * v2.X, v1.Y * v2.Y);
}
inline Vector2 operator*(const Vector2& v1, const float& f)
{
	return Vector2(v1.X * f, v1.Y * f);
}
inline Vector2 operator/(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.X / v2.X, v1.Y / v2.Y);
}
inline Vector2 operator/(const Vector2& v1, const float& f)
{
	return Vector2(v1.X / f, v1.Y / f);
}