#include <cstdio>
#include "window.h"

//constructor
Window::Window(const char title[], int x, int y, int width, int height, Uint32 flags)
{
	window = SDL_CreateWindow(title, x, y, width, height, flags);
	if (window == NULL)
	{
		printf("Window could not be made. SDL error: %s\n", SDL_GetError());
	}
}

SDL_Window* Window::get_sdl_window()
{
	return window;
}

void Window::get_borders_size(int* top, int* left, int* bottom, int* right)
{
	int err = SDL_GetWindowBordersSize(window, top, left, bottom, right);
	if (err < 0)
	{
		printf("There was a problem finding border size on window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

float Window::get_brightness()
{
	return SDL_GetWindowBrightness(window);
}

void* Window::get_data(const char* name)
{
	return SDL_GetWindowData(window, name);
}

int Window::get_display_index()
{
	int ret = SDL_GetWindowDisplayIndex(window);
	if (ret < 0)
	{
		printf("There was a problem finding the display index of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
	return ret;
}

void Window::get_display_mode(SDL_DisplayMode* mode)
{
	int ret = SDL_GetWindowDisplayMode(window, mode);
	if (ret < 0)
	{
		printf("There was a problem finding the display mode of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

Uint32 Window::get_flags()
{
	return SDL_GetWindowFlags(window);
}

SDL_Window* Window::get_window_from_id(Uint32 id)
{
	SDL_Window* ret = SDL_GetWindowFromID(id);
	if (ret == NULL)
	{
		printf("There was a problem finding the window from id. SDL error: %s\n", SDL_GetError());
	}
	return ret;
}

void Window::get_gamma_ramp(Uint16* red, Uint16* green, Uint16* blue)
{
	int err = SDL_GetWindowGammaRamp(window, red, green, blue);
	if (err < 0)
	{
		printf("There was a problem getting the gamma ramp of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

SDL_bool Window::get_grab()
{
	return SDL_GetWindowGrab(window);
}

Uint32 Window::get_id()
{
	Uint32 ret = SDL_GetWindowID(window);
	if (ret == 0)
	{
		printf("There was a problem getting the window id. SDL error: %s\n", SDL_GetError());
	}
	return ret;
}

void Window::get_maximum_size(int* w, int* h)
{
	SDL_GetWindowMaximumSize(window, w, h);
}

void Window::get_minimum_size(int* w, int* h)
{
	SDL_GetWindowMinimumSize(window, w, h);
}

void Window::get_opacity(float* opacity)
{
	int err = SDL_GetWindowOpacity(window, opacity);
	if (err < 0)
	{
		printf("There was a problem getting the opacity window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

Uint32 Window::get_pixel_format()
{
	Uint32 ret = SDL_GetWindowPixelFormat(window);
	if (ret == SDL_PIXELFORMAT_UNKNOWN)
	{
		printf("There was a problem getting the pixel format of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
	return ret;
}

void Window::get_position(int* x, int* y)
{
	SDL_GetWindowPosition(window, x, y);
}

void Window::get_size(int* x, int* y)
{
	SDL_GetWindowSize(window, x, y);
}

SDL_Surface* Window::get_surface()
{
	SDL_Surface* ret = SDL_GetWindowSurface(window);
	if (ret == NULL)
	{
		printf("There was a problem getting the surface of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
	return ret;
}

const char* Window::get_title()
{
	return SDL_GetWindowTitle(window);
}

void Window::hide()
{
	SDL_HideWindow(window);
}

void Window::maximize()
{
	SDL_MaximizeWindow(window);
}

void Window::minimize()
{
	SDL_MinimizeWindow(window);
}

void Window::raise()
{
	SDL_RaiseWindow(window);
}

void Window::restore()
{
	SDL_RestoreWindow(window);
}

void Window::set_bordered(SDL_bool bordered)
{
	SDL_SetWindowBordered(window, bordered);
}

void Window::set_brightness(float brightness)
{
	int err = SDL_SetWindowBrightness(window, brightness);
	if (err < 0)
	{
		printf("There was a problem setting the window brightness on window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

void* Window::set_data(const char* name, void* userdata)
{
	return SDL_SetWindowData(window, name, userdata);
}

void Window::set_display_mode(const SDL_DisplayMode* mode)
{
	int err = SDL_SetWindowDisplayMode(window, mode);
	if (err < 0)
	{
		printf("There was a problem setting the window display mode on window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

void Window::set_fullscreen(Uint32 flags)
{
	int err = SDL_SetWindowFullscreen(window, flags);
	if (err < 0)
	{
		printf("There was a problem with setting window %d to fullscreen. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

void Window::set_gamma_ramp(const Uint16* red, const Uint16* green, const Uint16* blue)
{
	int err = SDL_SetWindowGammaRamp(window, red, green, blue);
	if (err < 0)
	{
		printf("There was a problem with setting the gamma ramp of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

void Window::set_grab(SDL_bool grabbed)
{
	SDL_SetWindowGrab(window, grabbed);
}

void Window::set_hit_test(SDL_HitTest callback, void* callback_data)
{
	int err = SDL_SetWindowHitTest(window, callback, callback_data);
	if (err < 0)
	{
		printf("There was a problem setting the hit test of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

void Window::set_icon(SDL_Surface* icon)
{
	SDL_SetWindowIcon(window, icon);
}

void Window::set_input_focus()
{
	int err = SDL_SetWindowInputFocus(window);
	if (err < 0)
	{
		printf("There was a problem setting the input focus of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

void Window::set_maximum_size(int max_w, int max_h)
{
	SDL_SetWindowMaximumSize(window, max_w, max_h);
}

void Window::set_minimum_size(int min_w, int min_h)
{
	SDL_SetWindowMinimumSize(window, min_w, min_h);
}

void Window::set_opacity(float opacity)
{
	int err = SDL_SetWindowOpacity(window, opacity);
	if (err < 0)
	{
		printf("There was a problem setting the opacity of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

void Window::set_position(int x, int y)
{
	SDL_SetWindowPosition(window, x, y);
}

void Window::set_resizable(SDL_bool resizable)
{
	SDL_SetWindowResizable(window, resizable);
}

void Window::set_size(int w, int h)
{
	SDL_SetWindowSize(window, w, h);
}

void Window::set_title(const char* title)
{
	SDL_SetWindowTitle(window, title);
}

void Window::show()
{
	SDL_ShowWindow(window);
}

void Window::update_surface()
{
	int err = SDL_UpdateWindowSurface(window);
	if (err < 0)
	{
		printf("There was a problem updating the surface of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

void Window::update_surface_rects(SDL_Rect* rects, int numrects)
{
	int err = SDL_UpdateWindowSurfaceRects(window, rects, numrects);
	if (err < 0)
	{
		printf("There was a problem updating the surface rects of window %d. SDL error: %s\n", SDL_GetWindowID(window), SDL_GetError());
	}
}

//destructor
Window::~Window()
{
	SDL_DestroyWindow(window);
}