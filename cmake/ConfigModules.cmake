name: Build and Test

on: [push, pull_request]

jobs:
  build:
    runs-on: macos-latest
    steps:
      - uses: actions/checkout@v3
      - name: Install dependencies
        run: brew install opencv
      - name: Configure CMake
        run: cmake -S . -B build
      - name: Build
        run: cmake --build build
