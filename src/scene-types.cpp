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

	bg = al_load_bitmap("data/title_card.png");
	assert(nullptr != bg);
}

TitleScreen::~TitleScreen()
{
	al_destroy_font(font);
	al_destroy_bitmap(bg);
}

bool TitleScreen::Update(const InputState& state)
{
	const char* text = "HELLO WORLD!";
	int text_width = al_get_text_width(font, text);

	x -= 1.0f;

	if (x <= -text_width) {
		x = GAME_W + text_width;
	}

	if (state.isKeyActive(ALLEGRO_KEY_ENTER)) {
		return true;
	}

	return false;
}

void TitleScreen::Draw()
{
	al_draw_bitmap(bg, 0, 0, NULL);

	const char* text = "PRESS ENTER!!";
	al_draw_text(font, al_map_rgb(230, 69, 57), x, y, NULL, "PRESS ENTER!");
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
