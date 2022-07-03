# EcoTracker
Object tracker using ECO-HC algorithm

## Prerequisties
- opencv

## Build
```bash
git clone https://github.com/hez2010/EcoTracker.git
cd EcoTracker
mkdir build && cd build
cmake .. -DSIMD=1 -DMULTI_THREAD=1 -DCMAKE_BUILD_TYPE=Release

// for linux
make -j8
sudo make install

// for Windows + Visual Studio
msbuild EcoTracker.sln /p:Configuration=Release /p:TargetPlatform=x64 /m -verbosity:m
```

## Note
Please build with **Release** configuration, there're some problems with Debug configuration need to be resolved.  

## Super quick start
```cpp
eco::ECO *tracker = new eco::ECO();
eco::EcoParameters parameters;
Rect2f roi = Rect2f(...); // initial ROI
tracker->init(/* cv::Mat */ frame, /* cv::Rect2f */ roi, /* eco::EcoParameters */ parameters);

// got an updated ROI on new frame
tracker->update(/* cv::Mat */ frame, /* cv::Rect2f */ roi);
```

Provided C ABI for interop with other languages, see EcoTrackerExtern.hpp

To use this EcoTracker in other projects, clone this project as a submodule and use the following `CMakeLists.txt` as a reference:

```cmake
find_package(OpenCV REQUIRED)

add_subdirectory(EcoTracker)

add_executable(main "main.cpp")
target_link_libraries(main ${OpenCV_LIBS} ecotracker)
```
