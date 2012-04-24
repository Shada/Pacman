#pragma once

class BuffEffect
{
private:
	// is private so that effects wishing to change it
	// cant change it to values not excepted.
	static float multiplier;

	void addScore();
protected:
	// will be the amount of time it will be active
	// is decreased over time and when it reaches 0 the 
	// effect will be removed from the class handling effects
	double counter;
	int score;

	static float getMultplier() { return multiplier; }
	static void setMultiplier( float value )
	{
		if(value > 100.0f)
			value = 100.0f;
		else if(value < 0)
			value = 0;
		else
			multiplier = value;
	}
public:
	BuffEffect(int score);
	~BuffEffect();

	virtual void update(double dt) = 0;
	const double getCounter() { return counter; }
};