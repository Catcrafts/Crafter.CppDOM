# About

![alt text](https://github.com/Catcrafts/Crafter.Web/blob/master/hello.png?raw=true)

Crafter.Web is a C++ library to allow DOM access from WebAssembly.

# How to use

It is highly recommended to use this with [Crafter.WebBuild](https://github.com/Catcrafts/Crafter.WebBuild), but it is not strictly required if the same way of injecting the env is followed. The following instructions will be for Crafter.WebBuild.

## Quickstart
(This can also be seen in the ``sample`` folder)
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
                    "path":"path/to/Crafter.Web/project.json",
                    "configuration":"debug"
                }
            ]
        }
    ]
}
```
Save and close the file, create a ``main.cpp``
```cpp
import Crafter.Web;
using namespace Crafter::Web;

int main() {
    HtmlElement root("div", "Hello from C++!");
    root.RenderAsRoot();
}

```
Save and close, then run ``crafter-webbuild serve -c debug``. Now you can open the browser at ``http://localhost:8080/`` and ``Hello from C++!`` will appear in the browser.

A proper documentation is soon to follow, but for now please view the ``sample`` folder.
