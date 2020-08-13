#pragma once

#include <windows.h>
#include <istream>
#include <SDL.h>

namespace nc
{
	struct Color
	{
		float r, g, b, a;

		Color() : r{ 0 }, g{ 0 }, b{ 0 }{};
		Color(float r, float g, float b, float a = 1.0f) : r{ r }, g{ g }, b{ b }, a{ a } {};

		float& operator [] (size_t index) { return (&r)[index]; }
		const float& operator [] (size_t index) const { return (&r)[index]; }

		void Set(float r, float g, float b) { this->r = r; this->g = g; this->b = b; };

		Color operator + (const Color& c) const { return Color(r + c.r, g + c.g, b + c.b); }
		Color operator - (const Color& c) const { return Color(r - c.r, g - c.g, b - c.b); }

		Color operator * (const Color& c) const { return Color(r * c.r, g * c.g, b * c.b); }
		Color operator / (const Color& c) const { return Color(r / c.r, g / c.g, b / c.b); }



		Color operator + (float s) const { return Color(r + s, g + s, b + s); }
		Color operator - (float s) const { return Color(r - s, g - s, b - s); }

		Color operator * (float s) const { return Color(r * s, g * s, b * s); }
		Color operator / (float s) const { return Color(r / s, g / s, b / s); }



		Color operator += (const Color& c) { r += c.r; g += c.g; b += c.b; return *this; }
		Color operator -= (const Color& c) { r -= c.r; g -= c.g; b -= c.b; return *this; }

		Color operator *= (const Color& c) { r *= c.r; g *= c.g; b *= c.b; return *this; }
		Color operator /= (const Color& c) { r /= c.r; g /= c.g; b /= c.b; return *this; }



		Color operator += (float s) { r += s; g += s; b += s; return *this; }
		Color operator -= (float s) { r -= s; g -= s; b -= s; return *this; }

		Color operator *= (float s) { r *= s; g *= s; b *= s; return *this; }
		Color operator /= (float s) { r /= s; g /= s; b /= s; return *this; }


		friend std::istream& operator >> (std::istream& stream, Color& c);
		friend std::ostream& operator << (std::ostream& stream, Color& c)
		{
			stream << c.r << " " << c.g << " " << c.b << " " << c.a;

			return stream;
		}


		Color operator - () { return *this * -1.0f; };

		SDL_Color Pack888() const;

		operator SDL_Color() const { return Pack888(); }

		

	};


	inline SDL_Color Color::Pack888() const
	{
		SDL_Color color;
		color.r = static_cast<BYTE>(r * 255.0f);
		color.g = static_cast<BYTE>(g * 255.0f);
		color.b = static_cast<BYTE>(b * 255.0f);
		color.a = static_cast<BYTE>(a * 255.0f);

		return color;
	}
}