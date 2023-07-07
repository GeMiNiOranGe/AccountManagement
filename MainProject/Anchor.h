#ifndef ANCHOR_H
#define ANCHOR_H
#pragma once

class Anchor {
public:
	virtual void top_left() = 0;
	virtual void top() = 0;
	virtual void top_right() = 0;

	virtual void left() = 0;
	virtual void center() = 0;
	virtual void right() = 0;
	
	virtual void bottom_left() = 0;
	virtual void bottom() = 0;
	virtual void bottom_right() = 0;

};

#endif // end ANCHOR_H