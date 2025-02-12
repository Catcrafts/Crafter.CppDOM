import Crafter.CppDOM;
using namespace Crafter::CppDOM::Bindings;

int main(){
    void* body = GetElementById("body");
    SetInnerHTML(body, "Hello World!");
    FreeJs(body);
}