#pragma once

enum class SCENE_TYPE
{
	title_screen,
	scroller_intro,
	garden_a,
	garden_b,
	gameover
};

class Scene
{
public:
	Scene(SCENE_TYPE type);
	~Scene() = default;

	void Update();
	void Draw();

private:
	SCENE_TYPE current_scene;

	void update_title_screen();
	void update_scroller_intro();
	void update_garden();
	void update_gameover();

	void draw_title_screen();
	void draw_scroller_intro();
	void draw_garden();
	void draw_gameover();


};
