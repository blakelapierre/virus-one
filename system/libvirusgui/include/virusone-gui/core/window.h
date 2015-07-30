// core/window.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <string>
#include <memory>

/*
 * SDL forward decls
 */
struct SDL_Window;
struct SDL_Renderer;

namespace VirusMonitor { namespace Gui {

  class Panel;

  class Window {
  public:

    Window(const std::string& title, int width, int height);
    virtual ~Window();

    void clear();
    void present();
    void destroy();

    std::shared_ptr<Panel> createPanel(
      const std::string& name,
      int x, int y,
      int width, int height
    );

  protected:

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

 };

} /* Gui */ } /* VirusMonitor */
