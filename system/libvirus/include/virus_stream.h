// virus_stream.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#pragma once

#include <virus_pollable.h>
#include <cstddef>

namespace VirusOne {

  class Stream : public Pollable {
  public:

    Stream() {}
    virtual ~Stream() {}

    virtual bool canRead() = 0;
    virtual bool read(void* dest, size_t maxBytes, size_t& bytesRead) = 0;

    virtual bool canWrite() = 0;
    virtual bool write(const void* src, size_t bytes, size_t& bytesWritten) = 0;

  };

}
