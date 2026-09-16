# RTOS 02

[![RP2040 tests](https://github.com/uofu-advemb-26/lab02-g11/actions/workflows/main.yml/badge.svg)](https://github.com/uofu-advemb-26/lab02-g11/actions/workflows/main.yml)

## Simulated tests

The GitHub Actions workflow builds `build/test/mytest.elf` for the RP2040 and
runs it on a simulated Raspberry Pi Pico with Wokwi. The job passes only when
Unity prints `2 Tests 0 Failures 0 Ignored`, and fails immediately if it prints
`FAIL`.

Before the first workflow run, create a token in the
[Wokwi CI dashboard](https://wokwi.com/dashboard/ci) and save it as a GitHub
Actions repository secret named `WOKWI_CLI_TOKEN`.

To build the simulator ELF locally:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DPICO_SIMULATOR=ON
cmake --build build --target mytest --parallel
```

With `wokwi-cli` installed and `WOKWI_CLI_TOKEN` exported, run the same
simulation locally:

```sh
wokwi-cli . --timeout 12000 \
  --expect-text "2 Tests 0 Failures 0 Ignored" --fail-text FAIL
```
