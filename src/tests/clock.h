#ifndef GTKMM_EXAMPLE_CLOCK_H
#define GTKMM_EXAMPLE_CLOCK_H

#include <gtkmm/drawingarea.h>

class Clock : public Gtk::DrawingArea
{
    public:
        Clock();
        virtual ~Clock();

    protected:
    //Override default signal handler:
    virtual bool on_expose_event(GdkEventExpose* event);
    double m_radius;
    double m_lineWidth;
    bool onSecondElapsed(void);
};

#endif // GTKMM_EXAMPLE_CLOCK_H

