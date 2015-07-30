
#include <virusone-gui/core/window.h>

#include <memory>
#include <SDL.h>

int main(int argc, char ** argv) {
  SDL_Init(SDL_INIT_EVERYTHING);

  auto window = std::make_shared<VirusMonitor::Gui::Window>(
    "VirusOne Grow Monitor",
    1280,
    720
  );
  while (!SDL_QuitRequested()) {
    window->clear();
    window->present();
  }

  window->destroy();
  SDL_Quit();

  return 0;
}
