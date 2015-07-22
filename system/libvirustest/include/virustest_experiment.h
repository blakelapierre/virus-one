// virustest_experiment.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <string>
#include <list>

namespace VirusTest {

  class Experiment {
  public: // types

    enum ExperimentResult {
      kResultFail,
      kResultPass,
      kResultIncomplete
    };

    typedef std::list<std::string> MessageList;
    typedef MessageList::iterator MessageListIterator;
    typedef MessageList::const_iterator MessageListConstIterator;

  public: // interface methods

    virtual void run() = 0;

  public: // methods

    Experiment(const std::string& name);
    virtual ~Experiment();

    const std::string& getName();

    virtual void addChild(Experiment* pExperiment);
    virtual bool removeChild(Experiment* pExperiment);

    virtual ExperimentResult getResult() const;
    virtual const std::string getResultText() const;

  protected: // methods

    void expect(bool predicate, const std::string& message);
    void pass();
    void fail(const std::string& message);
    void incomplete(const std::string& message);

    void setResult(ExperimentResult result);

  protected: // attributes

    std::string m_name;
    ExperimentResult m_result;

    typedef std::list<Experiment*> ChildList;
    typedef ChildList::iterator ChildListIterator;
    typedef ChildList::const_iterator ChildListConstIterator;
    ChildList m_children;

  };

}
