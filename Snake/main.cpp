#include "raylib.h"
#include <iostream>

using namespace std;

//Color
Color green = { 173, 204, 96, 255 };
Color darkGreen = { 43, 51, 24, 255 };

//Cell
int cellSize = 30;
int cellCount = 25;

//Food
class Foode
{
public:
	Vector2 position;
	Texture2D texture;

	Foode()
	{
		Image image = LoadImage("Graphics/apll.png");
		texture = LoadTextureFromImage(image);
		UnloadImage(image);
		position = GenerateRandomPos();
	}

	~Foode()
	{
		UnloadTexture(texture);
	}

	void Drawing()
	{
		DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
	}

	Vector2 GenerateRandomPos()
	{
		float x = GetRandomValue(0, cellCount - 1);
		float y = GetRandomValue(0, cellCount - 1);
		return Vector2{ x, y };
	}
};

int main()
{
	// Initialize window and OpenGL context
	InitWindow(cellSize * cellSize, cellSize * cellCount, "Snake");

	//FPS
	SetTargetFPS(144);

	Foode foode = Foode();

	//Screen Loob
	while (WindowShouldClose() == false)
	{
		BeginDrawing();

			//Drawing
			ClearBackground(green);
			foode.Drawing();
		EndDrawing();
	}

	CloseWindow();

	return (0);
}