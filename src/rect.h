#pragma once

struct rect
{
	int x, y, w, h;
};

bool intersects(rect A, rect B);