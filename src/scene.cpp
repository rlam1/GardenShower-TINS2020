#include <allegro5/allegro.h>

#include "scene.h"

Scene::Scene(SCENE_TYPE type)
{
	current_scene = type;

    font = al_create_builtin_font();
}

Scene::~Scene()
{
    al_destroy_font(font);
}

void Scene::Update()
{
	switch (current_scene)
	{
    case SCENE_TYPE::TITLE_SCREEN:
        title_Screen.Update();
        break;
    case SCENE_TYPE::SCROLLER_INTRO:
        update_scroller_intro();
        break;
    case SCENE_TYPE::GARDEN_A:
        update_garden();
        break;
    case SCENE_TYPE::GARDEN_B:
        update_garden();
        break;
    case SCENE_TYPE::GAMEOVER:
        update_gameover();
        break;
    default:
        // DRAW on top of everything an error maybe?
        break;
	}
}

void Scene::Draw()
{
    switch (current_scene)
    {
    case SCENE_TYPE::TITLE_SCREEN:
        title_Screen.Draw();
        break;
    case SCENE_TYPE::SCROLLER_INTRO:
        draw_scroller_intro();
        break;
    case SCENE_TYPE::GARDEN_A:
        draw_garden();
        break;
    case SCENE_TYPE::GARDEN_B:
        draw_garden();
        break;
    case SCENE_TYPE::GAMEOVER:
        draw_gameover();
        break;
    default:
        break;
    }
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

void Scene::draw_title_screen()
{
    
}

void Scene::draw_scroller_intro()
{
}

void Scene::draw_garden()
{
}

void Scene::draw_gameover()
{
}
