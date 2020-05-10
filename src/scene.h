#pragma once

#include <vector>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "scene-types.h"

class Scene
{
public:
	Scene(SCENE_TYPE type);
	~Scene();

	void Update();
	void Draw();

private:
	SCENE_TYPE current_scene;

	TitleScreen title_Screen;

	ALLEGRO_FONT* font;
	ALLEGRO_BITMAP* gameScreen;

	void update_scroller_intro();
	void update_garden();
	void update_gameover();

	void draw_title_screen();
	void draw_scroller_intro();
	void draw_garden();
	void draw_gameover();
};
