#ifndef SNAKE_H
#define SNAKE_H
struct Vector2 { float x, y; };
struct Snake {
	std::vector<Vector2> snake;
	Vector2 direction;
};
#endif