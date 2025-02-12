import Crafter.CppDOM;

int main(){
    void* body = Crafter::CppDOM::Bindings::GetElementById("body");
    Crafter::CppDOM::Bindings::SetInnerHTML(body, "Hello World!");
    Crafter::CppDOM::Bindings::FreeJs(body);
}