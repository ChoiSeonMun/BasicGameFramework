#include "Text.h"

#include "../Component/TextComponent.h"

void Text::Init()
{
	TextComponent* txt = new TextComponent(this);
	txt->SetText(L"Press Space Key");
}