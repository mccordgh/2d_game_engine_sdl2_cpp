//
//  GameObject.h
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#ifndef GameObject_h
#define GameObject_h

#include "Game.hpp"

class GameObject
{
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();
    
    void Update();
    void Render();
    
private:
    SDL_Texture* objTexture;
    
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    int xpos;
    int ypos;
};

#endif /* GameObject_h */
