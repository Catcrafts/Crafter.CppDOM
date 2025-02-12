# About

![alt text](https://github.com/Catcrafts/Crafter.Web/blob/master/hello.png?raw=true)

Crafter.Web is a C++ library that exposes the browser DOM api's to C++ WebAssembly.

# How to use

It is highly recommended to use this with [Crafter.WebBuild](https://github.com/Catcrafts/Crafter.WebBuild), but it is not strictly required if the same way of injecting the env is followed. The following instructions will be for Crafter.WebBuild.

## Quickstart
create a ``project.json`` in an empty folder, open it in your preferred text editor.
Create a basic project file, that describes your web project.
```JSON
{
    "name": "sample-project",
    "configurations": [
        {
            "name": "debug",
            "standard": "c++26",
            "source_files": ["main"],
            "module_files": [],
            "build_dir": "./build",
            "output_dir": "./bin",
            "optimization_level": "0",
            "target": "wasm32-unknown-wasi",
            "type": "executable",
            "dependencies": [
                {
                    "path":"https://github.com/Catcrafts/Crafter.CppDOM.git",
                    "configuration":"debug"
                }
            ]
        }
    ]
}
```
Save and close the file, create a ``main.cpp``
```cpp
import Crafter.CppDOM;
using namespace Crafter::CppDOM;

int main(){
    HtmlElement body("body");
    body.SetInnerHTML("Hello World!");
}
```
Save and close, then run ``crafter-webbuild serve -c debug``. Now you can open the browser at ``http://localhost:8080/`` and ``Hello World!`` will appear in the browser.

This sample can also be viewed in the [HelloElement sample](https://github.com/Catcrafts/Crafter.CppDOM/tree/master/samples/HelloElement)
