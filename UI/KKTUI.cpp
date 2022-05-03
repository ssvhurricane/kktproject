#include "KKTUI.h"
namespace UI {

void KKTUI::InitialUI()
{
    _mainContext = new UI::_Context::UIContextInstaller();
}

void KKTUI::PrintDebugMessage(std::string str)
{

}
    
IContextInstaller* KKTUI::GetContext()
{
    return _mainContext;
} 

} // namespace UI