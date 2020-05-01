#pragma once
#include <SDL.h>

class Window
{
	SDL_Window* window;

public:
	Window(const char title[], int x, int y, int width, int height, Uint32 flags);

	SDL_Window* get_sdl_window();

	void get_borders_size(int* top, int* left, int* bottom, int* right);

	float get_brightness();

	void* get_data(const char* name);

	int get_display_index();

	void get_display_mode(SDL_DisplayMode* mode);

	Uint32 get_flags();

	SDL_Window* get_window_from_id(Uint32 id);

	void get_gamma_ramp(Uint16* red, Uint16* green, Uint16* blue);

	SDL_bool get_grab();

	Uint32 get_id();

	void get_maximum_size(int* w, int* h);

	void get_minimum_size(int* w, int* h);

	void get_opacity(float* opacity);

	Uint32 get_pixel_format();

	void get_position(int* x, int* y);

	void get_size(int* x, int* y);

	SDL_Surface* get_surface();

	const char* get_title();

	//TODO get_wm_info

	void hide();

	void maximize();

	void minimize();

	void raise();

	void restore();

	void set_bordered(SDL_bool bordered);

	void set_brightness(float brightness);

	void* set_data(const char* name, void* userdata);

	void set_display_mode(const SDL_DisplayMode* mode);

	void set_fullscreen(Uint32 flags);

	void set_gamma_ramp(const Uint16* red, const Uint16* green, const Uint16* blue);

	void set_grab(SDL_bool grabbed);

	void set_hit_test(SDL_HitTest callback, void* callback_data);

	void set_icon(SDL_Surface* icon);

	void set_input_focus();

	void set_maximum_size(int max_w, int max_h);

	void set_minimum_size(int min_w, int min_h);

	//TODO: set_modal_for

	void set_opacity(float opacity);

	void set_position(int x, int y);

	void set_resizable(SDL_bool resizable);

	void set_size(int w, int h);

	void set_title(const char* title);

	void show();

	void update_surface();

	void update_surface_rects(SDL_Rect* rects, int numrects);

	~Window();
};