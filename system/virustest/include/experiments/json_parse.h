#pragma once

namespace VirusTest {

  class JsonParseExperiment : public VirusTest::Experiment {
  public: // interface methods

    virtual void run();

  public: // methods

    JsonParseExperiment();
    virtual ~JsonParseExperiment();

  protected:

  };

}
