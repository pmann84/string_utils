# string_utils
A small collection of useful string utility functions.

NOTE: All of this functionality is available in Boost if you have access to this. It's also a lot more complete than this. Sometimes you want simple string parsing in a header only library, without having to compile/link boost.

## Check out
If you haven't checked out the code then check it out with all the submodules
```
git clone <repository name> --recursive
```

If you've already cloned the repo, then update the submodules manually
```
git submodule update --init --recursive
```

## Build
Do an out of source build in either `Release` or `Debug`

```
mkdir cmake-debug
cd cmake-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug
```

## Functionality
For examples of these see the tests in the tests folder.
* split
* join
* starts_with
* ends_with
* trim_left
* trim_right
* trim
* replace_all
* string to wstring conversion
* upper and lower case conversion

