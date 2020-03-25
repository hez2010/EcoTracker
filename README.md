# EcoTracker
Object tracker using ECO-HC algorithm

## Prerequisties
- opencv

## Build
```
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
