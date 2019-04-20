# EcoTracker
Object tracker using ECO-HC algorithm

## Prerequisties
- opencv

## Build
```
git clone https://github.com/hez2010/EcoTracker.git
cd EcoTracker
mkdir build && cd build
cmake .. -DSIMD=1 -DMULTI_THREAD=1

// for linux
make -j8
sudo make install

// for Windows + Visual Studio
msbuild Project.sln /p:Configuration=Release /p:TargetPlatform=x64 /m -verbosity:m
msbuild INSTALL.csproj /p:Configuration=Release /p:TargetPlatform=x64 /m -verbosity:m
```
