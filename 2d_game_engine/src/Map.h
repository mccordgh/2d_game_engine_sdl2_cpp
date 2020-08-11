//
//  Map.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "Game.hpp"

class Map
{
public:
    Map();
    ~Map();
    
    void LoadMap(int arr[20][25]);
    void DrawMap();
    
private:
    SDL_Rect src, dest;
    
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    
    int map[20][25];
};
