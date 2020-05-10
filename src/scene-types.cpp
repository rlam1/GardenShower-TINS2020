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
	x = GAME_W - H_OVERSCAN;
	y = GAME_H - V_OVERSCAN - al_get_font_line_height(font);
}

TitleScreen::~TitleScreen()
{
	al_destroy_font(font);
}

bool TitleScreen::Update()
{
	const char* text = "HELLO WORLD!";
	int text_width = al_get_text_width(font, text);

	x -= 1.0f;

	if (x <= -text_width) {
		x = GAME_W + text_width;
	}

	return false;
}

void TitleScreen::Draw()
{
	const char* text = "HELLO WORLD!";
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

void TitleScreen::ResetScene()
{
}
