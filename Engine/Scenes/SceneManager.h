#pragma once
#include <memory>
#include <SDL_timer.h>

#include "BaseScene.h"
#include "../EngineSingelton.h"
#include "../Core/Texture.h"

class SceneManager
{
    std::shared_ptr<BaseScene> currentScene = nullptr;

public:
    SceneManager();
    ~SceneManager();

    void update();

    template <class T>
    void changeScene()
    {
        //Only end scene if its valid
        if (currentScene)
        {
            currentScene->endScene();
        }

        for (Uint8 alpha = 255; alpha > 0; alpha -= 5)
        {
            SDL_SetRenderDrawColor(ENGINE->gSDL_Renderer, 0, 0, 0, 255);
            SDL_RenderClear(ENGINE->gSDL_Renderer);
            for (const auto& texture : ENGINE->gRenderer->getTextures())
            {
                SDL_SetTextureAlphaMod(texture->getSDLTexture(), alpha);
                SDL_Rect rec = {
                    static_cast<int>(texture->getPosition().x), static_cast<int>(texture->getPosition().y),
                    texture->getWidth(), texture->getHeight()
                };
                SDL_RenderCopy(ENGINE->gSDL_Renderer, texture->getSDLTexture(), nullptr, &rec);
            }
            SDL_RenderPresent(ENGINE->gSDL_Renderer);

            SDL_Delay(10); // Adjust the delay for the desired fade-out speed
        }
        
        currentScene = std::make_shared<T>();
        currentScene->startScene();
    }
};
