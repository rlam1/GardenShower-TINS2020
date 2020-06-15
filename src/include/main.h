#pragma once
#include <iostream>
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "globals.h"
#include "scene.h"

ALLEGRO_DISPLAY* display{ nullptr };
ALLEGRO_EVENT_QUEUE* queue{ nullptr };
ALLEGRO_TIMER* timer{ nullptr };

inline void must_init(bool subsystem, const char* message);
inline void* must_exist(void* val, const char* message);
void startSystems();
