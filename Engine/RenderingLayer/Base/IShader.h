#pragma once

#include <string>

namespace Engine {
namespace RenderSystem {

struct IShader
{  
   virtual void Use() = 0;

   virtual void SetBool(const std::string &name, bool value) const = 0;  

   virtual void SetInt(const std::string &name, int value) const = 0;  

   virtual void SetFloat(const std::string &name, float value) const = 0;
};

} // namespace _Context
} // namespace Engine
