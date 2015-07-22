#pragma once

namespace VirusTest {

  class JsonWriteExperiment : public VirusTest::Experiment {
  public: // interface methods

    virtual void run();

  public: // methods

    JsonWriteExperiment();
    virtual ~JsonWriteExperiment();

  protected:

  };

}
