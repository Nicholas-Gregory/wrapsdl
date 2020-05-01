#include <SDL.h>
#include <cstdio>
#include "texture.h"
#include "renderer.h"

Texture::Texture(Renderer& renderer, Uint32 format, int access, int w, int h)
{
	texture = SDL_CreateTexture(renderer.get_sdl_renderer(), format, access, w, h);
	if (texture == NULL)
	{
		printf("There was a problem creating the texture. SDL error: %s\n", SDL_GetError());
	}
}

void Texture::get_alpha_mod(Uint8* alpha)
{
	int err = SDL_GetTextureAlphaMod(texture, alpha);
	if (err < 0)
	{
		printf("There was a problem getting the texture alpha mod. SDL error: %s\n", SDL_GetError());
	}
}

void Texture::get_blend_mode(SDL_BlendMode* blendMode)
{
	int err = SDL_GetTextureBlendMode(texture, blendMode);
	if (err < 0)
	{
		printf("There was a problem getting the texture blend mode. SDL error: %s\n", SDL_GetError());
	}
}

void Texture::get_color_mod(Uint8* r, Uint8* g, Uint8* b)
{
	int err = SDL_GetTextureColorMod(texture, r, g, b);
	if (err < 0)
	{
		printf("There was a problem getting the color mod. SDL error: %s\n", SDL_GetError());
	}
}

void Texture::lock(const SDL_Rect* rect, void** pixels, int* pitch)
{
	int err = SDL_LockTexture(texture, rect, pixels, pitch);
	if (err < 0)
	{
		printf("There was a problem locking the texture. SDL error: %s\n", SDL_GetError());
	}
}

void Texture::query(Uint32* format, int* access, int* w, int* h)
{
	int err = SDL_QueryTexture(texture, format, access, w, h);
	if (err < 0)
	{
		printf("There was a problem querying the texture. SDL error: %s\n", SDL_GetError());
	}
}

void Texture::set_texture_alpha_mod(Uint8 alpha)
{
	int err = SDL_SetTextureAlphaMod(texture, alpha);
	if (err < 0)
	{
		printf("There was a problem setting the alpha mod of the texture. SDL error: %s\n", SDL_GetError());
	}
}

void Texture::set_blend_mode(SDL_BlendMode blendMode)
{
	int err = SDL_SetTextureBlendMode(texture, blendMode);
	if (err < 0)
	{
		printf("There was a problem setting the texture blend mode. SDL error: %s\n", SDL_GetError());
	}
}

void Texture::set_color_mod(Uint8 r, Uint8 g, Uint8 b)
{
	int err = SDL_SetTextureColorMod(texture, r, g, b);
	if (err < 0)
	{
		printf("There was a problem setting the color mod of the texture. SDL error: %s\n", SDL_GetError());
	}
}

void Texture::unlock()
{
	SDL_UnlockTexture(texture);
}

void Texture::update(const SDL_Rect* rect, const void* pixels, int pitch)
{
	int err = SDL_UpdateTexture(texture, rect, pixels, pitch);
	if (err < 0)
	{
		printf("There was a problem updating the texture. SDL error: %s\n", SDL_GetError());
	}
}


Texture::~Texture()
{
	SDL_DestroyTexture(texture);
}