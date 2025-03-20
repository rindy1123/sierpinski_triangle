#include "triangle.cpp"
#include <string>

const int MAX_SCALE = 4;

int main(int argc, char **argv) {
  int scale = MAX_SCALE;

  for (int i = 1; i < argc; i++) {
    string arg = argv[i];
    if (arg == "-h" || arg == "--help") {
      cout << "Usage: " << argv[0] << " [options]" << endl;
      cout << "Options:" << endl;
      cout << "  -h, --help\t\tShow this help message" << endl;
      cout << "  -s, --scale\t\tScale the triangle" << endl;
      return 0;
    } else if (arg == "-s" || arg == "--scale") {
      if (i + 1 >= argc) {
        cout << "Missing scale value" << endl;
        return 1;
      }

      try {
        scale = stoi(argv[i + 1]);
        if (scale < 1 || scale > MAX_SCALE) {
          cout << "Scale value should be between 1 and " << MAX_SCALE << endl;
          return 1;
        }
      } catch (exception e) {
        cout << "Invalid scale value" << endl;
        return 1;
      }
      i++;
    }
  }

  render(scale);
  return 0;
}
