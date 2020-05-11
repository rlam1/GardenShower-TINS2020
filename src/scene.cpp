#include <cmath>

#include <allegro5/allegro.h>

#include "globals.h"
#include "scene.h"

Scene::Scene(SCENE_TYPE type)
{
	current_scene = type;

    gameScreen = al_create_bitmap(GAME_W, GAME_H);
}

Scene::~Scene()
{
    al_destroy_bitmap(gameScreen);
}

bool Scene::Update()
{
    bool keepRunning{ true };

    // Whenever the Update() methods return true, a scene change is triggered.
	switch (current_scene)
	{
    case SCENE_TYPE::TITLE_SCREEN:
        if (title_Screen.Update(input)) {
            current_scene = title_Screen.GetNextScene();
            title_Screen.ResetScene();
        }
        break;
    case SCENE_TYPE::SCROLLER_INTRO:
        break;
    case SCENE_TYPE::GARDEN_A:
        break;
    case SCENE_TYPE::GARDEN_B:
        break;
    case SCENE_TYPE::GAMEOVER:
        break;
    case SCENE_TYPE::PAUSE_SCREEN:
        // Handle special keepRunning variable to signal program exit. Catch the ESCAPE key here.
        break;
    default:
        // DRAW on top of everything an error maybe?
        break;
	}

    return keepRunning;
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
        break;
    case SCENE_TYPE::GARDEN_A:
        break;
    case SCENE_TYPE::GARDEN_B:
        break;
    case SCENE_TYPE::GAMEOVER:
        break;
    default:
        break;
    }

    // Add any additional drawing calls here!

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
