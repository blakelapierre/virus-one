// virusone/system/exception.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#pragma once

#include <cstdarg>
#include <string>
#include <exception>

namespace VirusOne { namespace System {

  class Exception : public std::exception {
  public: // methods

    Exception();
    Exception(const std::string& fmt, ...);
    Exception(const std::string& fmt, va_list args);
    Exception(const Exception& e);
    virtual ~Exception() throw();

    virtual void buildMessage(const std::string& fmt, ...);
    virtual void buildMessage(const std::string& fmt, va_list argsIn);
    virtual const char* what() const throw();

  protected: // methods

    void clearMessage();

  protected: // attributes

    unsigned int m_messageLen;
    char* m_message;

  };

} /* System */ } /* VirusOne */
