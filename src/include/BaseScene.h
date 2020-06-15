#pragma once

#include <vector>

#include "input.h"

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

	virtual bool Update(const InputState& state) = 0; // Returns true when a scene change is triggered.
	virtual void Draw() = 0;

	virtual SCENE_TYPE GetNextScene() = 0;
	virtual SCENE_TYPE GetCurrentScene() = 0;
	virtual void ResetScene() = 0;

protected:
	SCENE_TYPE type;

	std::vector<const char*> image_resources;
	std::vector<const char*> font_resources;
	std::vector<const char*> audio_resources;
};