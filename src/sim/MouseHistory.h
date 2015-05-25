#pragma once

#include <list>

#include <Distance.h>
#include <Duration.h>
#include <Angle.h>

namespace sim {

// TODO: Perhaps like a separate playback or something like that... ghosting???

class MouseHistory {

public:
    MouseHistory();
    void append(const Distance& x, const Distance& y, const Angle& rotation, const Duration& sinceStart);
    // TODO: Figure out how to draw the path behind

private:

    typedef struct {
        float m_x; // x-position, in meters
        float m_y; // y-position, in meters
        float m_r; // rotation, in radians
        float m_t; // time, in seconds since the start of the run
    } position;

    std::list<position> m_history;

};

} // namespace sim
