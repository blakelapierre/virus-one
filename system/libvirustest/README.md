# libvirustest

A unit and performance testing framework for the VirusOne codebase.

## Building Tests

Tests are composed of Suites. Suites are composed of Controllers and their children. Controllers are composed of Experiments and their children. When a test runs, it iterates over the Suites calling their run() method. Suites iterate over their registered controllers calling run(). Controllers first iterate over their experiments, then iterate over their children recursively calling run(). Experiments essentially exist to conduct one test and resigter a pass/fail/incomplete result with logging.

An application developer would begin by creating Experiment classes to implement their actual test logic. The Experiments will then be organized into Controllers. Controllers will then be organized into heirarchies within Suites. Suites will be added to an Environment where they are run in concurrent parallel queues. Suites will be consumed by their Environment in the order they were registered as the next worker becomes available. This does not guarantee that Suites will be executed in-order/serially.

If serial test suite execution is desired, call Environment::setMaxWorkers(1) and you will have solved your problem. Your tests will be slower as the Environment won't be using multiple threads, 

### VirusTest::Environment

Tests are configured at the top level by creating one or more Environment instances and adding one or more Suite instances to each as follows:

    auto environment = std::make_shared<VirusTest::Environment>("virustest");
    environment.addSuite(std::make_shared<VirusTest::Suites::Json>());

The test will then execute the environment(s):

    environment.run();

When an Experiment fails, its containing Suite halts further execution and fails. Suite instances remaining in the Environment's queues will, however, all be executed.

Once an Environment is done running, its Suites, Controllers and Experiments can each be inspected for various conditions prior to test teardown.

### VirusTest::Suite

VirusTest::Suite implements a user-defined logical collection of test controllers intended to exercise application functionality. In the libvirus project, for example, all JSON processing components are tested as their own Suite.

A Suite is composed of Controller instances that will each be executed in the order they were registered. The Controller instances registered to a Suite are executed on the thread hosting the whole Suite. Thus, within a Suite, Controllers are guaranteed to be executed in-order/serially.

If any Experiment in any Controller in the Suite fails, the Suite halts further execution and fails.

### VirusTest::Controller

VirusTest::Controller implements the business logic necessary to drive a heirarchy of VirusTest::Experiment instances. Experiment instances are executed in the order they were registered to the Controller, and are executed on the thread hosting the containing Suite. Thus, they are guaranteed to be executed in-order/serially.

### VirusTest::Experiment

VirusTest::Experiment implements the business logic necessary to encapsulate Experiments of any type into heirarchies and run them. Experiment instances can accept child instances. If an Experiment has children, they are executed first. Then, the Experiment's run() method is called to execute its business logic and return its result. This allows an Experiment to reference its children and any results they may have registered while executing its own logic.

## Test Reporting

