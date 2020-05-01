#pragma once
#include <SDL.h>
#include "window.h"

class Renderer
{
	SDL_Renderer* renderer;

public:
	Renderer(Window& window, int index, Uint32 flags);

	SDL_Renderer* get_sdl_renderer();

	void get_draw_blend_mode(SDL_BlendMode* blendMode);

	void get_draw_color(Uint8* r, Uint8* g, Uint8* b, Uint8* a);

	SDL_Texture* get_target();

	void get_output_size(int* w, int* h);

	void clear();

	void copy(SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);

	void copy_ex(SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, const SDL_Point* center, const SDL_RendererFlip flip);

	void draw_line(int x1, int y1, int x2, int y2);

	void draw_lines(const SDL_Point* points, int count);

	void draw_point(int x, int y);

	void draw_points(const SDL_Point* points, int counts);

	void draw_rect(const SDL_Rect* rect);

	void draw_rects(const SDL_Rect* rects, int count);

	void fill_rect(const SDL_Rect* rect);

	void fill_rects(const SDL_Rect* rects, int count);

	void get_clip_rect(SDL_Rect* rect);

	SDL_bool get_integer_scale();

	void get_logical_size(int* w, int* h);

	void get_scale(float* scaleX, float* scaleY);

	void get_viewport(SDL_Rect* rect);

	SDL_bool is_clip_enabled();

	void present();

	void read_pixels(const SDL_Rect* rect, Uint32 format, void* pixels, int pitch);

	void set_clip_rect(const SDL_Rect* rect);

	void set_integer_scale(SDL_bool enable);

	void set_logical_size(int w, int h);

	void set_scale(float scaleX, float scaleY);

	void set_viewport(const SDL_Rect* rect);

	SDL_bool target_supported();

	void set_draw_blend_mode(SDL_BlendMode blendMode);

	void set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	void set_target(SDL_Texture* texture);

	~Renderer();
};