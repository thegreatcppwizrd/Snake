#include <vector>
#include "raylib.h"


const int cell_size = 50;
const int cell_count_y = 15;
const int cell_count_x = 15;

void Draw_Cell(int cell_count_x, int cell_count_y, int cell_size)
{
    for (int i = 0; i < cell_count_y; i++)
    {
        for (int j = 0; j < cell_count_x; j++)
        {
          
            Color color = (i + j) % 2 == 0 ? Color{ 64, 64, 64, 255 } : Color{ 46, 45, 45, 255 };

            DrawRectangle(
                j * cell_size,
                i * cell_size,
                cell_size,
                cell_size,
                color
            );
             
        }

        
    }
}

class Snake
{
public:

    std::vector<Vector2> snake;
    Vector2 direction = { 1, 0 };


    void Draw()
    {
        for (auto &i : snake)
        {
            DrawRectangle(
                i.x,
                i.y,
                cell_size,
                cell_size,
                GREEN
            );
        }
    }

    void Move()
    {
        for (int i = snake.size() - 1; i > 0; i--)
        {
            snake[i] = snake[i - 1];
        }

        snake[0].y += direction.y * cell_size;
        snake[0].x += direction.x * cell_size;

     

      
        
    }
};

class Fruit
{
public:
    Vector2 position = { 0, 0 };

    void Set(Snake& snake)
    {
        while (true)
        {
            position.x = GetRandomValue(0, cell_count_x - 1);
            position.y = GetRandomValue(0, cell_count_y - 1);

            bool touching_snake = false;

            for (auto& i : snake.snake)
            {
                if (i.x == position.x * cell_size &&
                    i.y == position.y * cell_size)
                {
                    touching_snake = true;
                    break;
                }
            }

            if (!touching_snake)
                break;
        }
   
    }

    void Draw()
    {
        DrawRectangle(
            position.x * cell_size,
            position.y * cell_size,
            cell_size,
            cell_size,
            RED
        );
    }
};


int main()
{
  
    const float move_time_duration = 0.2f;
    float timer = move_time_duration;

    InitWindow(cell_size * cell_count_x, cell_size * cell_count_y, "Snake");

    SetTargetFPS(60);


    Snake snake;
    Fruit fruit;
    fruit.Set(snake);

    snake.snake.push_back({ 100, 50 });
    snake.snake.push_back({ 50, 50 });
    snake.snake.push_back({ 0, 50 });

    bool retray_screen = false;
    bool menu = false;


    while (!WindowShouldClose())
    {
       

        BeginDrawing();

        if (!retray_screen && !menu)
        {
            ClearBackground(RAYWHITE);

            Draw_Cell(cell_count_x, cell_count_y, cell_size);
            snake.Draw();
            fruit.Draw();

            if (IsKeyDown(KEY_LEFT))
            {
                if (snake.direction.x != 1 && snake.direction.y != 0)
                {
                    snake.direction = { -1, 0 };
                }
            }

            if (IsKeyDown(KEY_RIGHT))
            {
                if (snake.direction.x != -1 && snake.direction.y != 0)
                {
                    snake.direction = { 1, 0 };
                }
            }

            if (IsKeyDown(KEY_UP))
            {
                if (snake.direction.x != 0 && snake.direction.y != 1)
                {
                    snake.direction = { 0, -1 };
                }
            }

            if (IsKeyDown(KEY_DOWN))
            {
                if (snake.direction.x != 0 && snake.direction.y != -1)
                {
                    snake.direction = { 0, 1 };
                }
            }


            timer -= GetFrameTime();

            if (timer <= 0)
            {
                timer += move_time_duration;
                snake.Move();
            }

            for (auto& i : snake.snake)
            {
                if (i.x >= cell_count_x * cell_size) { i.x = 0; }
                if (i.x < 0) { i.x = GetScreenWidth() - cell_size; }

                if (i.y >= cell_count_y * cell_size) { i.y = 0; }
                if (i.y < 0) { i.y = GetScreenHeight() - cell_size; }
            }

            if (snake.snake[0].x == fruit.position.x * cell_size && snake.snake[0].y == fruit.position.y * cell_size)
            {
                fruit.Set(snake);
                snake.snake.push_back(snake.snake[snake.snake.size() - 1]);
            }

            for (int i = snake.snake.size() - 1; i > 1; i--)
            {
                if (snake.snake[i].x == snake.snake[0].x &&
                    snake.snake[i].y == snake.snake[0].y)
                {
                    retray_screen = true;
                }
            }

        }
        else if (retray_screen)
        {
            Draw_Cell(cell_count_x, cell_count_x, cell_size);
        }
        EndDrawing();
    }

    CloseWindow();
}
