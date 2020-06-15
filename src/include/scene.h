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

	bool Update();
	void Draw();


	InputState input;

private:
	SCENE_TYPE current_scene;

	TitleScreen title_Screen;
	GardenA garden;

	ALLEGRO_BITMAP* gameScreen;
};
