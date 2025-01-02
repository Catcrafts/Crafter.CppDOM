/*
Crafter.Build
Copyright (C) 2024 Catcrafts
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
#include <cstddef>
export module Crafter.Web;
export import :HtmlElement;

extern "C" {
    void __cxa_allocate_exception() {

    }

    void __cxa_throw(int, int, int) {

    }
}

export namespace Crafter::Web::Bindings {
    __attribute__((import_module("env"), import_name("setInnerHTML"))) void SetInnerHTML(const char* id, std::size_t idLenght, const char* html, std::size_t htmlLenght);
    //__attribute__((import_module("env"), import_name("addEventListener"))) void AddEventListener(std::string id, std::string eventId, void (*listener)(void));
}

