#pragma once

constexpr double FPS{ 60.0 };

extern int SCREEN_W;
extern int SCREEN_H;

constexpr int GAME_W{ 400 };
constexpr int GAME_H{ 224 };
/* Remember to limmit content to within 4px top-bottom
   and 8px within left-right.

   If we multiply this resolution by 5 we get a nice
   approximation to 1920x1080, with some overscan.*/

constexpr int V_OVERSCAN{ 4 };
constexpr int H_OVERSCAN{ 8 };