#include "raylib.h"
#include <iostream>

int main()
{
	// Initialize window and OpenGL context
	const int Screen_Widtth = 800;
	const int Screen_Higth = 450;
	InitWindow(Screen_Widtth, Screen_Higth, "Snake");

	//FPS
	SetTargetFPS(144);

	//Screen Loob
	while (WindowShouldClose() == false)
	{
		BeginDrawing();

			ClearBackground(BLACK);
		EndDrawing();
	}

	CloseWindow();

	return (0);
}