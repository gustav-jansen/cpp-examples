#include <chrono>
#include <map>
#include <memory>
#include <string>
#include <thread>

#include <prometheus/counter.h>
#include <prometheus/exposer.h>
#include <prometheus/registry.h>

using namespace prometheus;

Family<Counter>& build_counter_family(std::shared_ptr<Registry> registry) {
  auto& counter_family = BuildCounter()
                             .Name("time_running_seconds_total")
                             .Help("How many seconds is this server running?")
//                             .Labels({{"label", "value"}})
                             .Register(*registry);

  return counter_family;
}


int main(int argc, char** argv) {

  // create an http server running on port 8080
  Exposer exposer{"127.0.0.1:8080"};

  // create a metrics registry with component=main labels applied to all its
  // metrics
  auto registry = std::make_shared<Registry>();
  // ask the exposer to scrape the registry on incoming scrapes
  exposer.RegisterCollectable(registry);

  // add a new counter family to the registry (families combine values with the
  // same name, but distinct label dimensions)
  auto& counter_family = build_counter_family(registry);

  // add a counter to the metric family
  auto& second_counter = counter_family.Add(
      {{"stride", "second"}});

  auto& twosecond_counter = counter_family.Add(
      {{"stride", "twosecond"}});

  auto& threesecond_counter = counter_family.Add(
      {{"stride", "threesecond"}});
  int i = 0;

  for (;;) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // increment the counter by one (second)
    second_counter.Increment();
    i++;
    if ( i%2==0 ) twosecond_counter.Increment();
    if ( i%3==0 ) threesecond_counter.Increment();
  }
  return 0;
}
