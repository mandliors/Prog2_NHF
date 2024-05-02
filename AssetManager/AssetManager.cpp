#include "AssetManager.h"

namespace AssetManager {

    static Texture2D textures[(int)TextureType::ASSET_COUNT];

    void LoadAssets()
    {
        textures[(int)TextureType::SMALL_ENEMY] = LoadTexture("assets/images/small_enemy.png");
        textures[(int)TextureType::LARGE_ENEMY] = LoadTexture("assets/images/large_enemy.png");
    }
    void UnloadAssets()
    {
        for (int i = 0; i < (int)TextureType::ASSET_COUNT; i++)
            UnloadTexture(textures[i]);
    }

    Texture2D* GetTexture(TextureType asset)
    {
        return &textures[(int)asset];
    }
}