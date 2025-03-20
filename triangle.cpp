#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
const int UNIT_HEIGHT = 5;
const int UNIT_WIDTH = UNIT_HEIGHT * 2 - 1;
const int SCREEN_SIZE = 150;
const char UNIT_CHAR = '1';

void unit_triangle(vector<vector<char>> *screen, pair<int, int> coordinate) {
  int x = coordinate.first;
  int y = coordinate.second;
  for (int i = y; i > y - UNIT_HEIGHT; i--) {
    int offset = y - i;
    for (int j = x + offset; j < x + UNIT_WIDTH - offset; j++) {
      (*screen)[i][j] = UNIT_CHAR;
    }
  }
}

/** Sierpinski triangle
 * @param screen Screen to render the triangle
 * @param origin Coordinate of the left bottom corner of the triangle
 * @param scale Scale of the triangle
 *
 * https://en.wikipedia.org/wiki/Sierpi%C5%84ski_triangle
 */
void sierpinski_triangle(vector<vector<char>> *screen, pair<int, int> origin,
                         int scale) {
  int x = origin.first;
  int y = origin.second;
  if (scale == 1) {
    pair<int, int> coordinate = {x, y};
    unit_triangle(screen, coordinate);
    pair<int, int> coordinate2 = {x + UNIT_WIDTH, y};
    unit_triangle(screen, coordinate2);
    pair<int, int> coordinate3 = {x + UNIT_HEIGHT, y - UNIT_HEIGHT};
    unit_triangle(screen, coordinate3);
    return;
  } else {
    sierpinski_triangle(screen, {x, y}, scale - 1);
    sierpinski_triangle(screen, {x + UNIT_WIDTH * pow(2, scale - 1), y},
                        scale - 1);
    sierpinski_triangle(screen,
                        {x + UNIT_HEIGHT * pow(2, scale - 1),
                         y - UNIT_HEIGHT * pow(2, scale - 1)},
                        scale - 1);
  }
}

void render(int scale) {
  vector<vector<char>> screen(SCREEN_SIZE, vector<char>(SCREEN_SIZE, ' '));
  pair<int, int> coordinate = {0, SCREEN_SIZE - 1};
  sierpinski_triangle(&screen, coordinate, scale);
  for (const auto &row : screen) {
    for (const auto &cell : row) {
      cout << cell;
    }
    cout << endl;
  }
}
