// virusone/services/smoothed_value.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <cstddef>

namespace VirusOne { namespace Services {

  class SmoothedValue {
  public: // types

    SmoothedValue(size_t maxSamples);
    virtual ~SmoothedValue();

    void setMaxSamples(size_t maxSamples);
    void addValue(double value);
    double currentValue();

  protected: // methods

    double m_value;

    size_t m_maxSamples;
    size_t m_samplesRead;

  };


} /* Services */ } /* VirusOne */
