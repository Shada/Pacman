#pragma once
#include <functional>
#include "stdafx.h"
#include "GraphicsManager.h"
class GameButton
{
private:
	string text;
	function<void()> callback;
	ID3DX10Font* font;
	ID3DX10Sprite* sprite;
	D3DXCOLOR color;
	RECT rect;
public:

	//create a new button with a command that will execute when pressed
	template<typename T> 
	explicit 
	GameButton(T const &t, D3DXVECTOR2 _pos, string _text) : callback(t) 
	{
		text = _text;
		GraphicsManager* m = GraphicsManager::getInstance();
		
		m->createFont(&font,16,"Verdana");
		m->createSprite(&sprite);

		rect.top	= (long)_pos.y; 
		rect.bottom = (long)_pos.y + 16;
		rect.left   = (long)_pos.x;
		rect.right  = (long)_pos.x + 300;


		color = D3DXCOLOR(0.324f, 0.027f, 0.027f, 1.0f);
	}

	//call this to execute the code specific for this instance
	void press()
	{
		callback();
	}

	//draw the text on the button
	void draw()
	{
		sprite->Begin(0);
		font->DrawTextA(sprite, text.c_str(), -1, &rect, DT_LEFT, color);
		sprite->End();

		GraphicsManager::getInstance()->resetBlendState();
	}
	//to be called when selected
	void setSelected()
	{
		color = D3DXCOLOR(1, 0, 0, 1.0f);
	}
	//called when no longer selected
	void setUnselected()
	{
		color = D3DXCOLOR(0.324f, 0.027f, 0.027f, 1.0f);
	}
	~GameButton()
	{
		SAFE_RELEASE(font);
		SAFE_RELEASE(sprite);
	}
};