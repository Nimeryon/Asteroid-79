#pragma once
#include "Event.h"

class TickSystem
{
public:
	TickSystem();
	~TickSystem();

	static void update();

	/* Occurs every #TICK_TIME per seconds ( 10 / seconds ) */ static Event<void> onMiniEvent;
	/* Occurs every #TICK_TIME % 2 per seconds ( 5 / seconds) */ static Event<void> onSmallEvent;
	/* Occurs every #TICK_TIME % 5 per seconds ( 2 / seconds ) */ static Event<void> onLittleEvent;
	/* Occurs every #TICK_TIME % 10 per seconds ( 1 / seconds ) */ static Event<void> onTickEvent;
	/* Occurs every #TICK_TIME % 50 per seconds ( 1 / 5 seconds ) */ static Event<void> onLongEvent;

private:
	static constexpr float TICK_TIME = .1f;

	static int m_tick;
	static float m_tickTimer;
};