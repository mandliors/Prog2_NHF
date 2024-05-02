#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <raylib.h>

namespace AssetManager {

    enum class TextureType
    {
        SMALL_ENEMY = 0, LARGE_ENEMY, ASSET_COUNT
    };

    void LoadAssets();
    void UnloadAssets();
    
    Texture2D* GetTexture(TextureType asset);
}


#endif