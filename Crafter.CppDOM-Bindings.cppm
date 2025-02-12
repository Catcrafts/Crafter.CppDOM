/*
Crafter.CppDOM
Copyright (C) 2025 Catcrafts
Catcrafts.net

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
*/

module;
#include <string>
export module Crafter.CppDOM:Bindings;


export namespace Crafter::CppDOM {
    __attribute__((import_module("env"), import_name("freeJs"))) void FreeJs(void* ptr);
}

export namespace Crafter::CppDOM::Bindings {
    __attribute__((import_module("env"), import_name("getElementById"))) void* GetElementById(const char* id, std::size_t idLenght);
    inline void* GetElementById(const std::string& id) {
        return GetElementById(id.c_str(), id.size());
    }
    __attribute__((import_module("env"), import_name("setInnerHTML"))) void SetInnerHTML(void* ptr, const char* html, std::size_t htmlLenght);
    inline void SetInnerHTML(void* ptr, const std::string& html) {
        SetInnerHTML(ptr, html.c_str(), html.size());
    }
}
