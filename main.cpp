#include <raylib.h>
#include <ctime>

#include "AssetManager/AssetManager.h"
#include "World/World.h"
#include "GameObjects/Player.h"

int main()
{
    const int screenWidth = 1600;
    const int screenHeight = 1000;
    srand((unsigned)time(NULL));

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "window");

    SetTargetFPS(120);
    AssetManager::LoadAssets();

    World world;

    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);
    Shader defaultShader = LoadShader(0, TextFormat("assets/shaders/default.fs", 330));
    Shader bloomShader = LoadShader(0, TextFormat("assets/shaders/bloom.fs", 330));

    while (!WindowShouldClose())
    {
        world.Update(GetFrameTime());

        BeginTextureMode(target);
            ClearBackground(Color{ 40, 40, 40, 0 });
            world.Draw();
        EndTextureMode();
        
        BeginDrawing();
            ClearBackground(Color{ 40, 40, 40, 255 });
            BeginShaderMode(defaultShader);
                DrawTextureRec(target.texture, Rectangle{ 0, 0, (float)target.texture.width, (float)-target.texture.height }, Vector2{ 0.0f, 0.0f }, WHITE);
            EndShaderMode();
            char buffer[10];
            sprintf(buffer, "%d coins", world.GetMainPlayer()->GetCoinCount());
            DrawText(buffer, 10, 70, 40, YELLOW);
            sprintf(buffer, "%d fps", GetFPS());
            DrawText(buffer, GetScreenWidth() - 150, 20, 40, YELLOW);
        EndDrawing();
    }

    AssetManager::UnloadAssets();

    UnloadShader(defaultShader);
    UnloadShader(bloomShader);
    UnloadRenderTexture(target);

    CloseWindow();

    return 0;
}