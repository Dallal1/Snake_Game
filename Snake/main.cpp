#include "raylib.h"
#include <iostream>
#include <deque>

using namespace std;

//Color
Color green = { 173, 204, 96, 255 };
Color darkGreen = { 43, 51, 24, 255 };

//Cell
int cellSize = 30;
int cellCount = 25;

//Snake
class Snake
{
public:
	deque<Vector2> body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };

	void Draw()
	{
		for (unsigned int i = 0; i < body.size(); i++)
		{
			float x = body[i].x;
			float y = body[i].y;
			Rectangle segment = Rectangle{ x * cellSize, y * cellSize, (float)cellSize, (float)cellSize };
			DrawRectangleRounded(segment, 0.5, 6, darkGreen);
		}
	}
};

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
	Snake snake = Snake();

	//Screen Loob
	while (WindowShouldClose() == false)
	{
		BeginDrawing();

			//Drawing
			ClearBackground(green);
			foode.Drawing();
			snake.Draw();
		EndDrawing();
	}

	CloseWindow();

	return (0);
}