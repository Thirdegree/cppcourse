#pragma once

#include "segment.h"
#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"
#include <vector>

class Snake
{
public:
	Snake(int length, float radius);

	Snake& operator++()
	{
		auto offset = (mCurrentDirection * cinder::vec2(-1.0f, -1.0f));
		mSegments.push_back(Segment(mSegments.back().GetPosition() + offset, mRadius));
		++mLength;
		return *this;
	}

	Snake operator++(int)
	{
		Snake old = *this;
		++*this;
		return old;
	}

	void Update();
	void Draw();
	int GetLength();
	void SetDirection(const cinder::vec2& directionOffset);
	cinder::vec2 SetInitialPosition(float width, float height);
	bool HeadIsCollidingWith(const cinder::vec2 &startingPosition);
	bool HeadIsCollidingWithSelf();
	bool IsCollidingWithWindow(float width, float height);

private:
	int mLength;
	float mRadius;
	cinder::vec2 mCurrentDirection;
	std::vector<Segment> mSegments;

	const cinder::vec2& GetSafeStartingDirection(const cinder::vec2& startingPosition, float width, float height);
};

