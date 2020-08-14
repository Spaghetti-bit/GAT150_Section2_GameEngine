#include "pch.h"
#include "Color.h"
#include <string>

namespace nc
{

	inline std::istream& operator >> (std::istream& stream, Color& c)
	{
		std::string line;
		std::getline(stream, line);

		if (line.find("{") != std::string::npos)
		{

			std::string cr = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
			c.r = std::stof(cr);
			c.g = 1;
			c.b = 1;
			line = line.substr(line.find(",") + 1, line.find("}") - line.find(","));

			/*std::string cg = line.substr(0, line.find(","));
			c.g = std::stof(cg);

			std::string cd = line.substr(line.find(",") + 1, line.find("}") - line.find(",") - 1);
			c.b = std::stof(cd);*/
		}
		return stream;
	}

	std::ostream& operator << (std::ostream& stream, Color& c)
	{
		stream << c.r << " " << c.g << " " << c.b << " " << c.a;

		return stream;
	}
}