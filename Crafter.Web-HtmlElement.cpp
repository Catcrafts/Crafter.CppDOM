/*
Crafter.Web
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
#include <string>
#include <format>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cstdint>
module Crafter.Web;
using namespace Crafter::Web;

HtmlElement::HtmlElement(std::string tag, std::string value, std::unordered_map<std::string, std::string> style, std::vector<HtmlElement*> children, std::unordered_map<std::string, std::string> attributes) : id(idCounter++), tag(tag), children(children), style(style), value(value), attributes(attributes) {

}


std::string HtmlElement::Render() const {
    std::string childrenRendered;
    for(HtmlElement* child : children){
        childrenRendered+=child->Render();
    }
    std::string styleRender;
    for(const auto& [key, value] : style){
        styleRender+=std::format("{}:{};",key,value);
    }
    std::string attributesRender;
    for(const auto& [key, value] : attributes){
        attributesRender+=std::format("{}=\"{}\"",key,value);
    }
    return std::format("<{} id=\"{}\" style=\"{}\" {}>{}{}</{}>",tag, id, styleRender, attributesRender, value, childrenRendered, tag);
}

void HtmlElement::RenderAsRoot() const {
    const std::string render = Render();
    const char id[] = "body";
    Crafter::Web::Bindings::SetInnerHTML(id, sizeof(id)-1, render.c_str(), render.size()-1);
}
