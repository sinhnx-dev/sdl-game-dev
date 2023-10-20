# sdl-game-dev example

## SDL Create App
### Visual Studio Code Extensions:
    C/C++                   (Microsoft)
    C/C++ Extension Pack    (Microsoft)
    CMake Tools             (Microsoft)
### Windows config
#### C/C++ Compiler
##### tmd-gcc compiler
#### CMake Tools
##### .vscode folder:
###### c_cpp_properties.json:

###### tasks.json:
    {
        "version": "2.0.0",
        "tasks": [
            {
                "type": "shell",
                "label": "SDL2",
                "command": "D:\\sdk\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\g++.exe",
                "args": [
                    "-g",
                    "src\\*.cpp",
                    "-o",
                    "build\\game.exe",
                    "-ID:/sdk/sdl2/mingw/x86_64/include",
                    "-LD:/sdk/sdl2/mingw/x86_64/lib",
                    "-lmingw32",
                    "-lSDL2main",
                    "-lSDL2",
                    "-mwindows"
                ],
                "options": {
                    "cwd": "${workspaceFolder}"
                },
                "problemMatcher": [
                    "$gcc"
                ],
                "group": {
                    "kind": "build",
                    "isDefault": true
                }
            }
        ]
    }
###### launch.json:
    {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "(gdb)",
                "type": "cppdbg",
                "request": "launch",
                "program": "${workspaceFolder}\\build\\game.exe",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${workspaceFolder}",
                "environment": [],
                "externalConsole": false,
                "MIMode": "gdb",
                "miDebuggerPath": "D:\\sdk\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\gdb.exe",
                "setupCommands": [
                    {
                        "description": "Enably pretty printing",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    }
                ],
                "preLaunchTask": "SDL2"
            }
        ]
    }
### macOS config
##### C/C++ Compiler
##### CMake Tools
    brew install cmake
##### .vscode folder:
###### c_cpp_properties.json:
    {
        "configurations": [
            {
                "name": "Mac",
                "includePath": [
                    "${workspaceFolder}/**",
                    "/usr/local/include/SDL2"
                ],
                "defines": [],
                "macFrameworkPath": [
                    "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
                ],
                "compilerPath": "/usr/bin/clang",
                "cStandard": "c17",
                "cppStandard": "c++17",
                "intelliSenseMode": "macos-clang-arm64"
            }
        ],
        "version": 4
    }
###### settings.json:
    {
        "cmake.sourceDirectory": "/Users/sinhnx/Desktop/sinhnx-dev/sdl-game-dev/p1-sdl-create-app"
    }
### using command line to build and run:
    cd ./p1-sdl-create-app
    mkdir build
    cd ./build
    cmake ..
    cmake --build .
    # run app
    ./SdlCreateWindow
