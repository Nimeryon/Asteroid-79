#include <algorithm>

#include "Math.h"

constexpr float PI = 3.14159265359f;
constexpr float DEG2RAD = (PI*2.f) / 360.f;

float Math::clamp(const float& value, const float& min, const float& max)
{
	return std::min(max, std::max(value, min));
}
int Math::clamp(const int& value, const int& min, const int& max)
{
	return std::min(max, std::max(value, min));
}
Vector2 Math::angleToVector(const float& angle)
{
	return Vector2(std::sinf(DEG2RAD * angle), -std::cosf(DEG2RAD * angle));
}
