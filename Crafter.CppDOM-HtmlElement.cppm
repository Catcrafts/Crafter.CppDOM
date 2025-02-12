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