#include "pch.h"
#include "Texture.h"

namespace nc
{
	bool Texture::Create(const std::string& name, SDL_Renderer* renderer)
	{
		m_renderer = renderer;

		SDL_Surface* surface = IMG_Load(name.c_str()); // loads sf2.bmp from Build
		if (surface == nullptr)
		{
			std::cout << "Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			return false;
		}

		m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
		SDL_FreeSurface(surface);
		if (m_texture == nullptr)
		{
			std::cout << "Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			return false;
		}



		return true;
	}

	void Texture::Destroy()
	{
		//delete m_texture;
	}

	void Texture::Draw(const Vector2& position, const Vector2& scale, float angle)
	{
		Vector2 size = GetSize();
		size = size * scale;



		SDL_Rect rect;
		rect.x = static_cast<int>(position.x);
		rect.y = static_cast<int>(position.y);
		rect.w = static_cast<int>(size.x);
		rect.h = static_cast<int>(size.y);

		SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &rect, angle, nullptr, SDL_FLIP_NONE);
	}

	Vector2 Texture::GetSize()
	{
		int w, h;
		SDL_QueryTexture(m_texture, NULL, NULL, &w, &h);

		return { w, h };
	}

}
