#pragma once
#include <iostream>
#include <string>

#include "allegro5/allegro.h"
#include "allegro5/allegro_color.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"

constexpr int MAX_FRAME_SKIPS{ 3 };
constexpr double FPS{ 60.0 };
constexpr int SCREEN_H{ 400 };
constexpr int SCREEN_W{ 224 };
/* Remember to limmit content to within 4px top-bottom
   and 8px within left-right.

   If we multiply this resolution by 5 we get a nice
   approximation to 1920x1080, with some overscan.*/

ALLEGRO_DISPLAY* display{ nullptr };
ALLEGRO_EVENT_QUEUE* queue{ nullptr };
ALLEGRO_TIMER* timer{ nullptr };

inline void must_init(bool subsystem, const char* message);
inline void* must_exist(void* val, const char* message);
void startSystems();
