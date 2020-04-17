// kawpow: C/C++ implementation of Kawpow, the Ethereum Proof of Work algorithm.
// Copyright 2018-2019 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.

#include <kawpow/kawpow.hpp>

#include <benchmark/benchmark.h>

static void get_epoch_context(benchmark::State& state)
{
    const auto e = static_cast<int>(state.range(0));

    kawpow::get_global_epoch_context(0);

    for (auto _ : state)
    {
        auto& ctx = kawpow::get_global_epoch_context(e);
        benchmark::DoNotOptimize(&ctx);
    }
}
BENCHMARK(get_epoch_context)->Arg(0)->ThreadRange(1, 8);
