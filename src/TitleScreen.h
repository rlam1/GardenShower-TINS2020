#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "BaseScene.h"

class TitleScreen : public BaseScene
{
public:
	TitleScreen();
	~TitleScreen();

	bool Update(const InputState& state) override;
	void Draw() override;

	SCENE_TYPE GetNextScene() override;
	SCENE_TYPE GetCurrentScene() override;
	void ResetScene() override;

private:
	ALLEGRO_BITMAP* bg;
	ALLEGRO_FONT* debug_font;
	float x, y;
};