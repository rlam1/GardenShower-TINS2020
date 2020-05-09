#include "allegro5/allegro.h"

#include "scene.h"

Scene::Scene(SCENE_TYPE type)
{
	current_scene = type;
}

void Scene::Update()
{
}

void Scene::Draw()
{
}

void Scene::update_title_screen()
{
}

void Scene::update_scroller_intro()
{
}

void Scene::update_garden()
{
}

void Scene::update_gameover()
{
}

void draw_title_screen()
{
}

void draw_scroller_intro()
{
}

void draw_garden()
{
}

void draw_gameover()
{
}
