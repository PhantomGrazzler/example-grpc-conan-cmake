# Example C++ project using gRPC with Conan and CMake

## How to build

1. Make an out-of-source build directory.

```
mkdir build
cd build
```

2. Add `inexorgame` to the list of remotes for Conan.

```conan remote add inexorgame "https://api.bintray.com/conan/inexorgame/inexor-conan"```

3. Tell Conan to install our dependencies for a Debug build, and build any that need to be built.

```conan install .. -s build_type=Debug --build missing```

4. Configure the build using CMake.

```cmake .. -DCMAKE_BUILD_TYPE=Debug```

5. Build using CMake.

```cmake --build . --config Debug```

You can build a release version by running steps 3-5 with `Release` instead of `Debug`.

On Windows you can also replace step 5 with opening the generated solution file in the `build` directory. Note that if you do this you should `conan install` both `Debug` and `Release` first.
