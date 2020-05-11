#pragma once

#include <vector>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "input.h"
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
};
