// virus_exception.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#pragma once

#include <exception>

namespace VirusOne {

  class Exception : public std::exception {
  public: // methods

    Exception(const char* fmt, ...);
    Exception(const Exception& e);
    virtual ~Exception() throw();

    virtual const char* what() const throw();

  protected: // attributes

    unsigned int m_messageLen;
    char* m_message;

  };

}
