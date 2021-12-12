#include <iostream>

#include "Random.h"

float Random::randomf()
{
	return static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
}
float Random::randomf(const float& min, const float& max)
{
	return (randomf() * (max - min)) + min;
}
int Random::random(const int& min, const int& max)
{
	return static_cast<int>(randomf(min, max));
}

bool Random::randomb()
{
	return randomf() >= 0.5f;
}
