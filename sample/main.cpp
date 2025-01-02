import Crafter.Web;
using namespace Crafter::Web;

int main() {
    HtmlElement root("div", "", {}, {
        HtmlElement("h1", "HELLO FROM C++"),
        HtmlElement("h1", "blue text", {{"color","blue"}}),
        HtmlElement("h1", "", {{"display","flex"}, {"justify-content","space-between"}}, {
            HtmlElement("div", "c++"),
            HtmlElement("div", "webdev"),
            HtmlElement("div", "is"),
            HtmlElement("div", "awesome")
        }),
        HtmlElement("img", "", {}, {}, {{"src","https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/1822px-ISO_C%2B%2B_Logo.svg.png"},{"width","200"}}),
    });
    root.RenderAsRoot();
}
