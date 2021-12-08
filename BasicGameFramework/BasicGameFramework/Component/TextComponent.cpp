#include "TextComponent.h"

#include "../Object/GameObject.h"

void TextComponent::Render(HDC hdc)
{
	POINT pos = _owner->GetRenderPos();

	TextOut(hdc, pos.x, pos.y, _text.c_str(), _text.length());
}

void TextComponent::SetText(const std::wstring& text) noexcept
{
	_text = text;
}

std::wstring TextComponent::GetText() const noexcept
{
	return _text;
}
