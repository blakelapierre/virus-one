// services/smoothed_value.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone/services/smoothed_value.h>

VirusOne::Services::SmoothedValue::SmoothedValue(
  size_t sampleCount
)
: m_value(0.0)
, m_maxSamples(sampleCount)
, m_samplesRead(0)
{}

VirusOne::Services::SmoothedValue::~SmoothedValue() {

}

void
VirusOne::Services::SmoothedValue::setMaxSamples(size_t maxSamples) {
  m_maxSamples = maxSamples;
  if (m_maxSamples > m_samplesRead) {
    m_samplesRead = m_maxSamples;
  }
}

void
VirusOne::Services::SmoothedValue::addValue(double value) {
  m_value = (m_value * m_samplesRead)
          + (((value * (m_samplesRead + 1)) - (m_value * m_samplesRead)) / (m_samplesRead + 1));
  
  if (m_samplesRead < m_maxSamples) {
    ++m_samplesRead;
  }
}

double
VirusOne::Services::SmoothedValue::currentValue() {
  return m_value;
}
