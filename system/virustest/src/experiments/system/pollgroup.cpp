// experiments/pollgroup_poll.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone/system/pollable.h>
#include <virusone/services/pollgroup.h>

#include <virusone-test/experiments/system/pollgroup.h>

VirusTest::Experiments::PollGroup::PollGroup()
: Experiment("PollGroup")
{}

VirusTest::Experiments::PollGroup::~PollGroup()
{}

class TestPollable : public VirusOne::System::Pollable {
public:

  TestPollable(int id)
  : m_id(id)
  , m_pollCount(0)
  {}

  virtual ~TestPollable()
  {}

  virtual void poll() {
    ++m_pollCount;
    spdlog::get("virustest")->info("TestPollable{}::poll {}", m_id, m_pollCount);
  }

  virtual void destroy() {
    spdlog::get("virustest")->info("TestPollable{}::destroy with {} polls", m_id, m_pollCount);
  }

protected:

  int m_id;
  unsigned m_pollCount;

};

void
VirusTest::Experiments::PollGroup::run() {
  auto masterGroup = std::make_shared<VirusOne::Services::PollGroup>();
  auto pollable = std::make_shared<TestPollable>(1);
  masterGroup->add(pollable);

  auto group = std::make_shared<VirusOne::Services::PollGroup>();
  masterGroup->add(group);

  pollable = std::make_shared<TestPollable>(2);
  group->add(pollable);
  
  masterGroup->poll();
}
