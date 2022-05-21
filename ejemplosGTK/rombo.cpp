#include <gtkmm.h>
#include <iostream>

class Rombo : public Gtk::DrawingArea {
public:
	Rombo();
	~Rombo();
protected:
	virtual bool on_expose_event(GdkEventExpose* event);	
};

Rombo::Rombo() {}
Rombo::~Rombo() {}

bool Rombo::on_expose_event(GdkEventExpose* event) {
	Glib::RefPtr<Gdk::Window> window = get_window();
	if (window) {
		
		Gtk::Allocation allocation = get_allocation();
		const int width = allocation.get_width();
		const int height = allocation.get_height();

		Cairo::RefPtr<Cairo::Context> context = window->create_cairo_context();
		//context->scale(width,height);
		context->rectangle(0.0,0.0,width,height);
		context->set_source_rgb(1.0,1.0,1.0);
		context->fill();

		context->set_line_width(0.5);
		context->set_source_rgb(1.0,0.0,0.0);
		context->move_to(width*0.5,height*0.0);
		context->line_to(width*0.75,height*0.5);
		context->line_to(width*0.5,height*1);
		context->line_to(width*0.25,height*0.5);
		context->line_to(width*0.5,height*0.0);
		context->fill();
		context->stroke();

	}

	return true;
}

int main (int argc, char* argv[]) {
	Gtk::Main kit(argc,argv);

	Gtk::Window win;

	Rombo rombo;

	win.add(rombo);

	win.show_all();

	Gtk::Main::run(win);

	return 0;
}