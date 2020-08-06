#pragma once
#include "Vector2.h"

namespace nc
{
	namespace math
	{
		const float PI = 3.1415f;
		const float TWO_PI = PI * 2;
		const float HALF_PI = PI * 0.5f;

		inline float RadiansToDegrees(float radians) { return radians * (180 / PI); }
		inline float DegreesToRadians(float degrees) { return degrees * (PI / 180); }

		template <typename T> 
		inline T Clamp(T v, T min, T max)
		{
			if (v < min) v = min;
			if (v > max) v = max;
			return v;
		}

		template <>
		inline ky::Vector2 Clamp<ky::Vector2>(ky::Vector2 v, ky::Vector2 min, ky::Vector2 max)
		{
			v.x = Clamp(v.x, min.x, max.x);
			v.y = Clamp(v.y, min.y, max.y);
			return v;
		}

		template <typename T>
		inline T Lerp(T a, T b, float t)
		{
			t = Clamp(t, 0.0f, 1.0f);
			return (a + ((b - a) * t));
		}


	}
}