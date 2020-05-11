#pragma once
#include <vector>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "BaseScene.h"

enum typeofSpriteBMP
{
	player,
	flower1,
	flower2,
	flower3
};

enum typeofFontFile
{
	normal,
	title
};

class GardenA : public BaseScene
{
public:
	GardenA();
	~GardenA();

	bool Update(const InputState& state) override;
	void Draw() override;

	SCENE_TYPE GetNextScene() override;
	SCENE_TYPE GetCurrentScene() override;
	void ResetScene() override;

private:
	std::vector<ALLEGRO_BITMAP*> sprites;
	std::vector<ALLEGRO_FONT*> fonts;

	void setupFilepaths();
	void loadResources();
};
