#pragma once

#include <vector>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

enum class SCENE_TYPE
{
	NEW_SCENE,
	PAUSE_SCREEN,
	TITLE_SCREEN,
	SCROLLER_INTRO,
	GARDEN_A,
	GARDEN_B,
	GAMEOVER
};

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene() = default;

	virtual bool Update() = 0; // Returns true when a scene change is triggered.
	virtual void Draw() = 0;

	virtual SCENE_TYPE GetNextScene() = 0;
	virtual SCENE_TYPE GetCurrentScene() = 0;
	virtual void ResetScene() = 0;

protected:
	SCENE_TYPE type;

	std::vector<const char*> image_resources;
	std::vector<const char*> audio_resources;
};

class TitleScreen : public BaseScene
{
public:
	TitleScreen();
	~TitleScreen();

	bool Update() override;
	void Draw() override;

	SCENE_TYPE GetNextScene() override;
	SCENE_TYPE GetCurrentScene() override;
	void ResetScene() override;

private:
	ALLEGRO_FONT* font;
	float x, y;
};

