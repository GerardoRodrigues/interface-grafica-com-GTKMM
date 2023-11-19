#include <gtkmm.h>
// Sendo compilado por MINGW64 pela linha de comando g++ Main.cpp $(pkg-config gtkmm-3.0 --cflags --libs)

int main(int argc, char** argv){
    Gtk::Main kit(argc, argv);  
    Gtk::Window window;
    window.set_default_size(600, 400);
    window.set_title("Teste");

    Gtk::Label label;
    label.set_text("Teste para aparecer na janela.");
    window.add(label);

    window.show_all();

    Gtk::Main::run(window);
    
    return 0;
}