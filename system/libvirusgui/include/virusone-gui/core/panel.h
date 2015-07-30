// core/panel.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <string>
#include <memory>
#include <SDL.h>

namespace VirusGui { namespace Core {

  class Window;

  class Panel {
  public:

    Panel(std::shared_ptr<Window> window, const std::string& name);
    virtual ~Panel();

    const std::string& name() const;
    void render();

  protected:

    std::string m_name;
    SDL_Rect m_region;

  };

} /* Core */ } /* VirusGui */
