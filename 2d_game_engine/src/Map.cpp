//
//  Map.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] = {
    { 0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,1,1,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,1,1,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,1,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,1,1,2,2,1,1,1,1,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,2,1,1,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,1,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
};

Map::Map() {
    dirt = TextureManager::LoadTexture("dirt");
    grass = TextureManager::LoadTexture("grass");
    water = TextureManager::LoadTexture("water");
    
    LoadMap(lvl1);
    
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;
    
    dest.x = 0;
    dest.y = 0;
    dest.w = 32;
    dest.h = 32;
}

Map::~Map() {
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
}

void Map:: LoadMap(int arr[20][25])
{
    for (int row = 0; row < 20; row += 1)
    {
        for (int col = 0; col < 25; col += 1)
        {
            map[row][col] = arr[row][col];
        }
    }
}

void Map::DrawMap()
{
    int type = 0;
    
    for (int row = 0; row < 20; row += 1)
    {
        for (int col = 0; col < 25; col += 1)
        {
            type = map[row][col];
            
            dest.x = col * 32;
            dest.y = row * 32;
            
            switch (type)
            {
                case 0:
                    TextureManager::Draw(water, src, dest);
                    break;
                    
                case 1:
                    TextureManager::Draw(grass, src, dest);
                    break;
                    
                case 2:
                    TextureManager::Draw(dirt, src, dest);
                    break;
                    
                default:
                    break;
            }
        }
    }
}
