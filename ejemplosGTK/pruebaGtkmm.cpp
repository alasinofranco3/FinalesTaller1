#include <gtkmm.h>

class Linea : public Gtk::DrawingArea {
public:
	Linea();
	~Linea();
protected:
	virtual bool on_expose_event(GdkEventExpose* event);
};

Linea::Linea() {}
Linea::~Linea() {}

bool Linea::on_expose_event(GdkEventExpose* event) {
	Glib::RefPtr<Gdk::Window> window = get_window();
	
	if (window) {
		Gtk::Allocation allocation = get_allocation();
		int width = allocation.get_width();
		int height = allocation.get_height();


		Cairo::RefPtr<Cairo::Context> context = window->create_cairo_context();
		context->scale(height,width);
		context->rectangle(0.0,0.0,1.0,1.0);
		context->set_source_rgb(1.0,1.0,1.0);
		context->fill();


		context->set_source_rgb(1.0,0.0,0.0);
		context->set_line_width(0.01);
		context->move_to(0.0,0.0);
		context->line_to(1.0,1.0);
		context->move_to(1.0,0.0);
		context->line_to(0.0,1.0);
		context->set_source_rgb(0.0,1.0,0.0);
		context->move_to(0.33,0.0);
		context->line_to(0.33,1.0);
		context->move_to(0.66,0.0);
		context->line_to(0.66,1.0);
		context->stroke();
	}
	return true;
}

int main(int argc, char* argv[]) {
	Gtk::Main kit(argc,argv);

	Gtk::Window win;

	Linea miLinea;
	win.add(miLinea);
	
	win.show_all();
	
	Gtk::Main::run(win);
	
	return 0;
}