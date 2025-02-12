module;
#include <string>
export module Crafter.CppDOM:HtmlElement;
import :Bindings;

namespace Crafter::CppDOM {
    export class HtmlElement {
        public:
        void* const ptr;
        inline HtmlElement(const char* id, std::size_t idLenght): ptr(Bindings::GetElementById(id, idLenght)) {
            
        }
        inline HtmlElement(const std::string& id): ptr(Bindings::GetElementById(id)) {
            
        }
        inline void SetInnerHTML(const char* html, std::size_t htmlLenght) {
            Bindings::SetInnerHTML(ptr, html, htmlLenght);
        }
        inline void SetInnerHTML(const std::string& html) {
            Bindings::SetInnerHTML(ptr, html);
        }
        inline ~HtmlElement(){
            Bindings::FreeJs(ptr);
        }
    };
}