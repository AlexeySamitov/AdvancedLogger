#include <iostream>
#include <benchmark/benchmark.h>
#include "../AdvancedLogger/FileLogger.h"

static void BM_TestCase(benchmark::State& state) {
    auto path = "file.log";
    FileLogger logger(path);

    for (auto _ : state)
    {
        double pi = 3.1459265359;

        logger << pi;

        int i = 1234;

        logger << i;

        logger << "A sample message";
    }
}
// Register the function as a benchmark
BENCHMARK(BM_TestCase);

BENCHMARK_MAIN();
