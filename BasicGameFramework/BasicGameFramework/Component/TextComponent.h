#pragma once

#include <string>

#include "Component.h"

class TextComponent : public Component
{
public:
	using Component::Component;
	virtual ~TextComponent() noexcept = default;
	
	virtual void	Render(HDC hdc) override;

	void			SetText(const std::wstring& text) noexcept;

	std::wstring	GetText() const noexcept;
private:
	std::wstring			_text;
};