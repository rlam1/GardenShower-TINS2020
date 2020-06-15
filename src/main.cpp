#include "main.h"

int SCREEN_W{ 1280 };
int SCREEN_H{ 720 };

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
					// Note: IN THE FUTURE THIS WILL BE HANDLED by the Scene class {director}.
					running = false;
				}

				director.input.setKey(ev.keyboard.keycode);

				break;
			case ALLEGRO_EVENT_KEY_UP:
				director.input.unsetKey(ev.keyboard.keycode);

				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				running = false;
				break;
			case ALLEGRO_EVENT_TIMER:
				running = director.Update();

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

#ifdef WIN32
	al_set_new_display_flags(ALLEGRO_OPENGL_3_0);
#endif // WIN32

	//al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 4, ALLEGRO_SUGGEST);

	display = (ALLEGRO_DISPLAY*)must_exist(al_create_display(SCREEN_W, SCREEN_H), "FATAL ERROR: display ");
	queue = (ALLEGRO_EVENT_QUEUE*)must_exist(al_create_event_queue(), "FATAL ERROR: queue ");
	timer = (ALLEGRO_TIMER*)must_exist(al_create_timer(1.0 / FPS), "FATAL ERROR: timer ");

	must_init(al_install_keyboard(), "KEYBOARD DRIVER ERROR!");
	must_init(al_init_image_addon(), "IMAGE ADD-ON ERROR!");
	must_init(al_init_primitives_addon(), "PRIMITIVES ADD-ON ERROR!");
	must_init(al_init_font_addon(), "FONT ADD-ON ERROR!");
	must_init(al_init_ttf_addon(), "TTF FONT ADD-ON ERROR!");

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));

	SCREEN_W = al_get_display_width(display);
	SCREEN_H = al_get_display_height(display);
}
