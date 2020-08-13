#pragma once
#include <stdlib.h>

namespace nc
{
	inline float random()
	{
		return rand() / static_cast<float>(RAND_MAX);
	}

	inline float random(float min, float max) 
	{ 
		if (min > max)
		{
			std::swap(min, max);
		}
		return min + ((max - min) * random()); 
	}
}