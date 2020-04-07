#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };
  std::vector<SDL_Point> body;

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();
  void SpeedIncrease() { speed += incr_speed; }

  void GrowBody();
  bool SnakeCell(int x, int y);
  int Size() const { return size; }
  std::pair<int, int> Head() const { return std::make_pair(head_x, head_y); }
  bool IsAlive() const { return alive; }

  Direction direction = Direction::kUp;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  bool growing{false};
  int grid_width;
  int grid_height;
  static constexpr float incr_speed = 0.02;
};

#endif
