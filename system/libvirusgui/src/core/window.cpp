// gui/window.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone-gui/core/window.h>
#include <SDL.h>

VirusMonitor::Gui::Window::Window(
  const std::string& title,
  int width,
  int height
)
: m_window(nullptr)
, m_renderer(nullptr)
{
  m_window = SDL_CreateWindow(
    title.c_str(),
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width, height,
    0
  );
  m_renderer = SDL_CreateRenderer(
    m_window,
    -1,
    SDL_RENDERER_ACCELERATED
  );
}

VirusMonitor::Gui::Window::~Window()
{
  destroy();
}

void
VirusMonitor::Gui::Window::clear()
{
  SDL_RenderClear(m_renderer);
}

void
VirusMonitor::Gui::Window::present()
{
  SDL_RenderPresent(m_renderer);
}

void
VirusMonitor::Gui::Window::destroy()
{
  if (m_window != nullptr) {
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
  }
}
