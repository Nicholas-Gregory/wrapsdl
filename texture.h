#pragma once
#include <SDL.h>
#include "renderer.h"

class Texture
{
	SDL_Texture* texture;

public:
	Texture(Renderer& renderer, Uint32 format, int access, int w, int h);

	void get_alpha_mod(Uint8* alpha);

	void get_blend_mode(SDL_BlendMode* blendMode);

	void get_color_mod(Uint8* r, Uint8* g, Uint8* b);

	void lock(const SDL_Rect* rect, void** pixels, int* pitch);

	void query(Uint32* format, int* access, int* w, int* h);

	void set_texture_alpha_mod(Uint8 alpha);

	void set_blend_mode(SDL_BlendMode blendMode);

	void set_color_mod(Uint8 r, Uint8 g, Uint8 b);

	void unlock();

	void update(const SDL_Rect* rect, const void* pixels, int pitch);

	~Texture();
};