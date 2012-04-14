#pragma once
#include <functional>
#include "stdafx.h"
class GameButton
{
private:
	string text;
	function<void()> callback;
public:
	template<typename T> 
	explicit 
	GameButton(T const &t, string _text) : callback(t) {text = _text;}

	void press()
	{
		callback();
	}

	~GameButton();
};

