// virustest_experiment.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <string>
#include <list>
#include <memory>

#include <spdlog/spdlog.h>

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

    virtual std::shared_ptr<Experiment> addChild(std::shared_ptr<Experiment> experiment);
    virtual bool removeChild(std::shared_ptr<Experiment> experiment);

    virtual ExperimentResult getResult() const;
    virtual const std::string getResultText() const;

  protected: // methods

    void it(const std::string& spec, const std::function<void (void)>& specRunner);
    void expect(bool predicate, const std::string& testName, const std::string& message);
    void pass();
    void fail(const std::string& message);
    void incomplete(const std::string& message);

    void setResult(ExperimentResult result);

  protected: // attributes

    std::string m_name;
    std::string m_currentSpecTitle;
    ExperimentResult m_result;
    std::shared_ptr<spdlog::logger> m_log;

    typedef std::list<std::shared_ptr<Experiment>> ChildList;
    typedef ChildList::iterator ChildListIterator;
    typedef ChildList::const_iterator ChildListConstIterator;
    ChildList m_children;

  };

}
