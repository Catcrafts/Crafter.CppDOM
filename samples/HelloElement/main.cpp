import Crafter.CppDOM;
using namespace Crafter::CppDOM;

int main(){
    HtmlElement body("body");
    body.SetInnerHTML("Hello World!");
    //No need to call FreeJs, this is done in the destructor of HtmlElement.
}