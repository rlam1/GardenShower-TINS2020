#include "include/GardenA.h"

GardenA::GardenA()
{
	setupFilepaths();
	loadResources();
}

GardenA::~GardenA()
{
	for (auto& sprite : sprites) {
		al_destroy_bitmap(sprite);
	}

	for (auto& font : fonts) {
		al_destroy_font(font);
	}
}

bool GardenA::Update(const InputState& state)
{
	return false;
}

void GardenA::Draw()
{
}

SCENE_TYPE GardenA::GetNextScene()
{
	return SCENE_TYPE();
}

SCENE_TYPE GardenA::GetCurrentScene()
{
	return SCENE_TYPE();
}

void GardenA::ResetScene()
{
}

void GardenA::setupFilepaths()
{
	image_resources.push_back("data/you.png");
	image_resources.push_back("data/flower1.png");
	image_resources.push_back("data/flower2.png");
	image_resources.push_back("data/flower3.png");

	font_resources.push_back("data/PlaymegamesReguler.ttf");
	font_resources.push_back("data/Pixelbroidery.ttf");
}

void GardenA::loadResources()
{
	for (const char* file : image_resources)
	{
		sprites.push_back(al_load_bitmap(file));
	}

	int fontsize{ 12 }; // TODO: Analyze font increase code below. This could be const.
	for (const char* file : font_resources)
	{
		fonts.push_back(al_load_font(file, fontsize, NULL));

		// TODO: Um, why I was increasing font size like this every new font?
		fontsize += 12;
	}
}
