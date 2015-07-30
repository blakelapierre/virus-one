// panel.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)


#include <virusone-gui/core/panel.h>
#include <virusone-gui/core/window.h>

VirusGui::Core::Panel::Panel(
  std::shared_ptr<Window> window,
  const std::string& name
)
{}

VirusGui::Core::Panel::~Panel()
{}

const std::string&
VirusGui::Core::Panel::name() const
{
  return m_name;
}

void
VirusGui::Core::Panel::render()
{
//   SDL_RenderSetClipRect(m_renderer, &m_region);
}
