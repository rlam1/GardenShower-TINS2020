#include "globals.h"
#include "scene-types.h"

BaseScene::BaseScene()
{
	type = SCENE_TYPE::NEW_SCENE;
}

TitleScreen::TitleScreen()
{
	type = SCENE_TYPE::TITLE_SCREEN;

	font = al_create_builtin_font();
	x = SCREEN_H - H_OVERSCAN;
	y = SCREEN_W - V_OVERSCAN - 15.0f;
}

TitleScreen::~TitleScreen()
{
	al_destroy_font(font);
}

bool TitleScreen::Update()
{
	x -= 3.0f;

	if (x <= -15.5f) {
		x = SCREEN_W;
	}

	return false;
}

void TitleScreen::Draw()
{
	al_draw_text(font, al_map_rgb(0, 255, 0), x, y, NULL, "HELLO WORLD!");
}

SCENE_TYPE TitleScreen::GetNextScene()
{
	return SCENE_TYPE::SCROLLER_INTRO;
}

SCENE_TYPE TitleScreen::GetCurrentScene()
{
	return type;
}
