#include <iostream>
#include <string>

#include "allegro5/allegro.h"
#include "allegro5/allegro_color.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"

constexpr int SCREEN_H{ 400 };
constexpr int SCREEN_W{ 224 };

int main(int argc, char const *argv[])
{
	bool sane = al_init();
	if(!sane){
		std::cout << "ALLEGRO 5 FAILED TO INITIALIZE!\n";
	}

	ALLEGRO_DISPLAY *display = al_create_display(SCREEN_H, SCREEN_W);
	if(nullptr == display) {
		std::cout << "FATAL ERROR: display " << display << "\n";
	}
	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	if(nullptr == queue) {
		std::cout << "FATAL ERROR: queue " << queue << "\n";
	}
	ALLEGRO_TIMER *timer = al_create_timer(1.0/60.0);
	if(nullptr == timer) {
		std::cout << "FATAL ERROR: timer " << timer << "\n";
	}

	al_install_keyboard();
	al_init_image_addon();
	al_init_primitives_addon();

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	bool running { true };
	bool draw { false };
	while(running){
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		switch(ev.type){
			case ALLEGRO_EVENT_KEY_DOWN:
				if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
					running = false;
				}
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				running = false;
				break;
			case ALLEGRO_EVENT_TIMER:
				draw = true;
				break;
		}

		if((draw == true) && al_is_event_queue_empty(queue)){
			draw = false;

			ALLEGRO_COLOR color = al_map_rgb_f(1.0f, 0.0f, 1.0f);
			al_clear_to_color(color);
			al_flip_display();
		}

	}
	return 0;
}