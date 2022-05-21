#include <gtkmm.h>


class CruzDiagonal : public Gtk::DrawingArea {
public:
	CruzDiagonal();
	~CruzDiagonal();
protected:
	virtual bool on_expose_event(GdkEventExpose* event);
};

CruzDiagonal::CruzDiagonal() {}
CruzDiagonal::~CruzDiagonal() {}

bool CruzDiagonal::on_expose_event(GdkEventExpose* event) {
	Glib::RefPtr<Gdk::Window> window = get_window();
	if (window) {
		Gtk::Allocation allocation = get_allocation();
		const int width = allocation.get_width();
		const int height = allocation.get_height();

		Cairo::RefPtr<Cairo::Context> context = window->create_cairo_context();
		context->set_source_rgb(1.0,1.0,1.0);
		context->rectangle(0.0,0.0,width,height);
		context->fill();

		context->set_line_width(1.0);
		context->set_source_rgb(1.0,0.0,0.0);
		context->move_to(0.0,0.0);
		context->line_to(width,height);
		context->move_to(0.0,height);
		context->line_to(width,0.0);
		context->stroke();
	}

	return true;
}

int main (int argc, char* argv[]) {
	Gtk::Main kit(argc,argv);

	Gtk::Window win;
	CruzDiagonal cruz;

	win.add(cruz);
	win.show_all();

	Gtk::Main::run(win);

	return 0;
}