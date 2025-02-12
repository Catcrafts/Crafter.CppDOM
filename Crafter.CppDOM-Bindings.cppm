module;
#include <string>
export module Crafter.CppDOM:Bindings;


export namespace Crafter::CppDOM::Bindings {
    __attribute__((import_module("env"), import_name("getElementById"))) void* GetElementById(const char* id, std::size_t idLenght);
    inline void* GetElementById(const std::string& id) {
        return GetElementById(id.c_str(), id.size());
    }
    __attribute__((import_module("env"), import_name("setInnerHTML"))) void SetInnerHTML(void* ptr, const char* html, std::size_t htmlLenght);
    inline void SetInnerHTML(void* ptr, const std::string& html) {
        SetInnerHTML(ptr, html.c_str(), html.size());
    }
    __attribute__((import_module("env"), import_name("freeJs"))) void FreeJs(void* ptr);
}
