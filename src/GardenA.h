#pragma once

#include "BaseScene.h"

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

};
