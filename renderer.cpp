#include <cstdio>
#include <SDL.h>
#include "window.h"
#include "renderer.h"

Renderer::Renderer(Window& window, int index, Uint32 flags)
{
	SDL_Window* sdlwindow = window.get_sdl_window();
	renderer = SDL_CreateRenderer(sdlwindow, index, flags);
	if (renderer == NULL)
	{
		printf("There was a problem creating the renderer in window %d. SDL error: %s\n", window.get_id(), SDL_GetError());
	}
}

SDL_Renderer* Renderer::get_sdl_renderer()
{
	return renderer;
}

void Renderer::get_draw_blend_mode(SDL_BlendMode* blendMode)
{
	int err = SDL_GetRenderDrawBlendMode(renderer, blendMode);
	if (err < 0)
	{
		printf("There was a problem getting the render draw blend mode. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::get_draw_color(Uint8* r, Uint8* g, Uint8* b, Uint8* a)
{
	int err = SDL_GetRenderDrawColor(renderer, r, g, b, a);
	if (err < 0)
	{
		printf("There was a problem getting the render draw color. SDL error: %s\n", SDL_GetError());
	}
}

SDL_Texture* Renderer::get_target()
{
	SDL_Texture* ret = SDL_GetRenderTarget(renderer);
	if (ret == NULL)
	{
		printf("There was a problem getting the render target. SDL error: %s\n", SDL_GetError());
	}
	return ret;
}

void Renderer::get_output_size(int* w, int* h)
{
	int err = SDL_GetRendererOutputSize(renderer, w, h);
	if (err < 0)
	{
		printf("There was a problem getting the output size. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::clear()
{
	int err = SDL_RenderClear(renderer);
	if (err < 0)
	{
		printf("There was a problem clearing the render target. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::copy(SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect)
{
	int err = SDL_RenderCopy(renderer, texture, srcrect, dstrect);
	if (err < 0)
	{
		printf("There was a problem copying the texture to the render target. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::copy_ex(SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, const SDL_Point* center, const SDL_RendererFlip flip)
{
	int err = SDL_RenderCopyEx(renderer, texture, srcrect, dstrect, angle, center, flip);
	if (err < 0)
	{
		printf("There was a problem copying the texture to the render target. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::draw_line(int x1, int x2, int y1, int y2)
{
	int err = SDL_RenderDrawLine(renderer, x1, x2, y1, y2);
	if (err < 0)
	{
		printf("There was a problem drawing the line. SDL error:%s\n", SDL_GetError());
	}
}

void Renderer::draw_lines(const SDL_Point* points, int count)
{
	int err = SDL_RenderDrawLines(renderer, points, count);
	if (err < 0)
	{
		printf("There was a problem drawing the lines. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::draw_point(int x, int y)
{
	int err = SDL_RenderDrawPoint(renderer, x, y);
	if (err < 0)
	{
		printf("There was a problem drawing the point. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::draw_points(const SDL_Point* points, int counts)
{
	int err = SDL_RenderDrawPoints(renderer, points, counts);
	if (err < 0)
	{
		printf("There was a problem drawing the points. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::draw_rect(const SDL_Rect* rect)
{
	int err = SDL_RenderDrawRect(renderer, rect);
	if (err < 0)
	{
		printf("There was a problem drawing the rect. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::draw_rects(const SDL_Rect* rects, int count)
{
	int err = SDL_RenderDrawRects(renderer, rects, count);
	if (err < 0)
	{
		printf("There was a problem drawing the rects. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::fill_rect(const SDL_Rect* rect)
{
	int err = SDL_RenderFillRect(renderer, rect);
	if (err < 0)
	{
		printf("There was a problem filling the rects. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::fill_rects(const SDL_Rect* rects, int count)
{
	int err = SDL_RenderFillRects(renderer, rects, count);
	if (err < 0)
	{
		printf("There was a problem filling the rects. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::get_clip_rect(SDL_Rect* rect)
{
	SDL_RenderGetClipRect(renderer, rect);
}

SDL_bool Renderer::get_integer_scale()
{
	return SDL_RenderGetIntegerScale(renderer);
}

void Renderer::get_logical_size(int* w, int* h)
{
	SDL_RenderGetLogicalSize(renderer, w, h);
}

void Renderer::get_scale(float* scaleX, float* scaleY)
{
	SDL_RenderGetScale(renderer, scaleX, scaleY);
}

void Renderer::get_viewport(SDL_Rect* rect)
{
	SDL_RenderGetViewport(renderer, rect);
}

SDL_bool Renderer::is_clip_enabled()
{
	return SDL_RenderIsClipEnabled(renderer);
}

void Renderer::present()
{
	SDL_RenderPresent(renderer);
}

void Renderer::read_pixels(const SDL_Rect* rect, Uint32 format, void* pixels, int pitch)
{
	int err = SDL_RenderReadPixels(renderer, rect, format, pixels, pitch);
	if (err < 0)
	{
		printf("There was a problem reading the pixels. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::set_clip_rect(const SDL_Rect* rect)
{
	int err = SDL_RenderSetClipRect(renderer, rect);
	if (err < 0)
	{
		printf("There was a problem setting the clip rectangle for the rendering target. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::set_integer_scale(SDL_bool enable)
{
	int err = SDL_RenderSetIntegerScale(renderer, enable);
	if (err < 0)
	{
		printf("There was a problem setting the integer scale. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::set_logical_size(int w, int h)
{
	int err = SDL_RenderSetLogicalSize(renderer, w, h);
	if (err < 0)
	{
		printf("There was a problem setting the logical size. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::set_scale(float scaleX, float scaleY)
{
	int err = SDL_RenderSetScale(renderer, scaleX, scaleY);
	if (err < 0)
	{
		printf("There was a problem setting the scale. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::set_viewport(const SDL_Rect* rect)
{
	int err = SDL_RenderSetViewport(renderer, rect);
	if (err < 0)
	{
		printf("There was a problem setting the viewport. SDL error: %s\n", SDL_GetError());
	}
}

SDL_bool Renderer::target_supported()
{
	return SDL_RenderTargetSupported(renderer);
}

void Renderer::set_draw_blend_mode(SDL_BlendMode blendMode)
{
	int err = SDL_SetRenderDrawBlendMode(renderer, blendMode);
	if (err < 0)
	{
		printf("There was a problem setting the draw blend mode. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	int err = SDL_SetRenderDrawColor(renderer, r, g, b, a);
	if (err < 0)
	{
		printf("There was a problem setting the draw color. SDL error: %s\n", SDL_GetError());
	}
}

void Renderer::set_target(SDL_Texture* texture)
{
	int err = SDL_SetRenderTarget(renderer, texture);
	if (err < 0)
	{
		printf("There was a problem setting the render target. SDL error: %s\n", SDL_GetError());
	}
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
}