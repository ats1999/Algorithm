# Algorithm
Most popular algorithms from other categories, including DP, Greedy algorithm, etc.

### Format code
https://stackoverflow.com/questions/45823734/visual-studio-code-formatting-for

## c_cpp_properties
```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}
```
## lunch.json 
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "g++ build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": true,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "g++ build active file",
      "miDebuggerPath": "/usr/bin/gdb"
    }
  ]
}
```
## tasks.json
```json
{
    "version": "2.0.0",
    "tasks": [
      {
        "type": "shell",
        "label": "C/C++: g++.exe build active file",
        "command": "/usr/bin/g++",
        "args": [
          "-g",
          "${file}",
          "-o",
          "${fileDirname}/${fileBasenameNoExtension}",
          "&&",
          "clear",
          "&&",
          "${fileDirname}/${fileBasenameNoExtension}"
        ],
        "options": {
          "cwd": "/usr/bin"
        },
        "problemMatcher": [
          "$gcc"
        ],
        "group": {
          "kind": "build",
          "isDefault": true
        }
      },
      {
        "type": "cppbuild",
        "label": "C/C++: cpp build active file",
        "command": "/usr/bin/cpp",
        "args": [
          "-g",
          "${file}",
          "-o",
          "${fileDirname}/${fileBasenameNoExtension}"
        ],
        "options": {
          "cwd": "${workspaceFolder}"
        },
        "problemMatcher": [
          "$gcc"
        ],
        "group": "build",
        "detail": "compiler: /usr/bin/cpp"
      },
      {
        "type": "cppbuild",
        "label": "C/C++: cpp build active file",
        "command": "/bin/cpp",
        "args": [
          "-g",
          "${file}",
          "-o",
          "${fileDirname}/${fileBasenameNoExtension}"
        ],
        "options": {
          "cwd": "${fileDirname}"
        },
        "problemMatcher": [
          "$gcc"
        ],
        "group": "build",
        "detail": "compiler: /bin/cpp"
      }
    ]
  }
```

## snippet
```json
{
	"C++ Snippet":{
		"prefix":"cpp-snippet",
		"body": [
			"//============================================================================",
			"// Name        : .cpp",
			"// Author      : Rahul (ATS)",
			"// Version     : 2.0",
			"// cpp version : c++ 17",
			"// Copyright   : Everyone can freely use and distribute it.",
			"// Description :",
			"// T.C         : O()",
			"// A.S         : O()",
			"//============================================================================",
			"",
			"#include<bits/stdc++.h>",
			"using namespace std;",
			"",
			"#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)",
			"",
			"void file_io(){",
			"#ifndef ONLINE_JUDGE",
			"\tfreopen(\"/home/rahul/Desktop/Algorithm/input.txt\", \"r\", stdin);",
			"\tfreopen(\"/home/rahul/Desktop/Algorithm/output.txt\", \"w\", stdout);",
			"#endif",
			"}",
			"",
			"int main(){",
			"\tIOS; file_io(); int t; cin>>t;",
			"\twhile(t--){",
			"",
			"\t}",
			"\treturn 0;",
			"}"
		]
	}
}
```