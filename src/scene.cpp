#include <cmath>

#include <allegro5/allegro.h>

#include "globals.h"
#include "scene.h"

Scene::Scene(SCENE_TYPE type)
{
	current_scene = type;

    font = al_create_builtin_font();

    gameScreen = al_create_bitmap(GAME_W, GAME_H);
}

Scene::~Scene()
{
    al_destroy_font(font);

    al_destroy_bitmap(gameScreen);
}

void Scene::Update()
{
	switch (current_scene)
	{
    case SCENE_TYPE::TITLE_SCREEN:
        if (title_Screen.Update()) {
            current_scene = title_Screen.GetNextScene();
            title_Screen.ResetScene();
        }
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
    al_set_target_bitmap(gameScreen);
    ALLEGRO_COLOR color = al_map_rgb_f(0.0f, 0.0f, 1.0f);
    al_clear_to_color(color);

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

    al_set_target_backbuffer(al_get_current_display());

    double sx = ((double)SCREEN_W / (double)GAME_W);
    double sy = ((double)SCREEN_H / (double)GAME_H);
    double scale = std::fmin(sx, sy);

    double scaleW = (double)GAME_W * scale;
    double scaleH = (double)GAME_H * scale;
    double scaleX = ((double)SCREEN_W - scaleW) / 2.0;
    double scaleY = ((double)SCREEN_H - scaleH) / 2.0;

    al_draw_scaled_bitmap(gameScreen,
        H_OVERSCAN, V_OVERSCAN, GAME_W - H_OVERSCAN, GAME_H - V_OVERSCAN,
        scaleX, scaleY, scaleW, scaleH,
        NULL);
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
