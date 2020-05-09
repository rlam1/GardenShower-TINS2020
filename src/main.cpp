#include "main.h"

int main(int argc, char const **argv)
{
	startSystems();

	al_start_timer(timer);

	int frames_skipped{ 0 };

	Scene director(SCENE_TYPE::TITLE_SCREEN);

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
				director.Update();

				draw = true;
				break;
		}

		if(draw && al_is_event_queue_empty(queue)){
			draw = false;

			ALLEGRO_COLOR color = al_map_rgb_f(1.0f, 0.0f, 1.0f);
			al_clear_to_color(color);

			director.Draw();

			al_flip_display();
		}

	}
	return 0;
}

inline void must_init(bool subsystem, const char* message)
{
	if (!subsystem) {
		std::cerr << message << "\n";
		exit(EXIT_FAILURE);
	}
}

inline void* must_exist(void* val, const char* message)
{
	if (!val) {
		std::cerr << message << "\n";
		exit(EXIT_FAILURE);
	}

	return val;
}

void startSystems()
{
	must_init(al_init(), "ALLEGRO 5 FAILED TO INITIALIZE!");

	display = (ALLEGRO_DISPLAY*)must_exist(al_create_display(SCREEN_H, SCREEN_W), "FATAL ERROR: display ");
	queue = (ALLEGRO_EVENT_QUEUE*)must_exist(al_create_event_queue(), "FATAL ERROR: queue ");
	timer = (ALLEGRO_TIMER*)must_exist(al_create_timer(1.0 / FPS), "FATAL ERROR: timer ");

	must_init(al_install_keyboard(), "KEYBOARD DRIVER ERROR!");
	must_init(al_init_image_addon(), "IMAGE ADD-ON ERROR!");
	must_init(al_init_primitives_addon(), "PRIMITIVES ADD-ON ERROR!");

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
}
