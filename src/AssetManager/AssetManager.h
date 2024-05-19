#ifndef CPORTA

#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <raylib.h>

namespace AssetManager {

    /**
     * @brief Enum class for texture type
     * 
     */
    enum class TextureType
    {
        SMALL_ENEMY = 0, LARGE_ENEMY, ASSET_COUNT
    };

    /**
     * @brief Loads all the necessary images
     */
    void LoadAssets();
    /**
     * @brief Unloads all the images loaded previously
     */
    void UnloadAssets();
    
    /**
     * @brief Returns the texture of the asset
     * 
     * @param asset The texture type
     * @return Texture2D* The texture of the asset ("AssetManager keeps ownership")
     */
    Texture2D* GetTexture(TextureType asset);
}


#endif

#endif