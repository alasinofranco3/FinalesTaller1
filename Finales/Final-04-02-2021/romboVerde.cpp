#include <gtkmm.h>

class RomboVerde : public Gtk::DrawingArea {
public:
	RomboVerde();
	~RomboVerde();
protected:	
	virtual bool on_expose_event(GdkEventExpose* event);
};

RomboVerde::RomboVerde() {}
RomboVerde::~RomboVerde() {}

bool RomboVerde::on_expose_event(GdkEventExpose* event) {
	Glib::RefPtr<Gdk::Window> window = get_window();
	if (window) {
		Gtk::Allocation allocation = get_allocation();
		const int width = allocation.get_width();
		const int height = allocation.get_height();

		Cairo::RefPtr<Cairo::Context> context = window->create_cairo_context();
		context->set_source_rgb(1.0,1.0,1.0);
		context->rectangle(0.0,0.0,width,height);
		context->fill();

		context->set_line_width(0.5);
		context->set_source_rgb(0.0,1.0,0.0);
		context->move_to(0.0,0.5*height);
		context->line_to(0.5*width,0.0);
		context->line_to(width,0.5*height);
		context->line_to(width*0.5,height);
		context->line_to(0.0,0.5*height);
		context->fill();
		context->stroke();
	}

	return true;
}

int main (int argc, char* argv[]) {
	Gtk::Main kit(argc,argv);

	Gtk::Window win;

	RomboVerde rombo;
	win.add(rombo);

	win.show_all();

	Gtk::Main::run(win);
	return 0;
}