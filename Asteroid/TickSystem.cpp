#include <iostream>

#include "GameHandler.h"
#include "Time.h"
#include "TickSystem.h"

Event<void> TickSystem::onMiniEvent = Event<void>();
Event<void> TickSystem::onSmallEvent = Event<void>();
Event<void> TickSystem::onLittleEvent = Event<void>();
Event<void> TickSystem::onTickEvent = Event<void>();
Event<void> TickSystem::onLongEvent = Event<void>();

int TickSystem::m_tick = 0;
float TickSystem::m_tickTimer = 0.f;

TickSystem::TickSystem()
{
    GameHandler::onEarlyUpdate += EventHandler::bind(update);
}
TickSystem::~TickSystem()
{
	GameHandler::onEarlyUpdate -= EventHandler::bind(update);
}

void TickSystem::update()
{
    m_tickTimer += Time::deltaTime;
    if (m_tickTimer >= TICK_TIME)
    {
        m_tickTimer -= TICK_TIME;
        m_tick++;

        onMiniEvent();
        if (m_tick % 2 == 0) onSmallEvent();
        if (m_tick % 5 == 0) onLittleEvent();
        if (m_tick % 10 == 0) onTickEvent();
        if (m_tick % 50 == 0) onLongEvent();
    }
}
