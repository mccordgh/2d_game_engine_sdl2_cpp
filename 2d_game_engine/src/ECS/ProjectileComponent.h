//
//  ProjectileComponent.h
//  2d_game_engine
//
//  Created by Matthew mccord on 9/14/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

#pragma once

#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"

class ProjectileComponent : public Component
{
public:
    ProjectileComponent(Vector2D vel, int rng, int spd): range(rng), speed(spd), velocity(vel)
    {}
    
    ~ProjectileComponent() {};
    
    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        transform->velocity = velocity;
        
        std::cout << "Project INITIALIZED" << std::endl;
    }
    
    void update() override
    {
        distance += speed;
        
        // If it reached max range then destroy
        if (distance > range)
        {
            std::cout << "Project OUT OF RANGE ~DESTROYED" << std::endl;
            entity->destroy();
            return;
        }
        
        // Check if projectile has gone offscreen
        if (transform->position.x > (Game::camera.x + Game::camera.w + transform->width)
            || transform->position.x < Game::camera.x
            || transform->position.y > Game::camera.y + Game::camera.h + transform->height
            || transform->position.y < Game::camera.y)
        {
            std::cout << "Project OFFSCREEN ~DESTROYED" << std::endl;
            entity->destroy();
        }
    }
    
private:
    TransformComponent* transform;

    Vector2D velocity;

    int range = 0;
    int speed = 0;
    int distance = 0;
};
