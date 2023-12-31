#include <gtkmm.h>
#include <iostream>
#include <regex>
// Sendo compilado por MINGW64 pela linha de comando g++ Main.cpp $(pkg-config gtkmm-3.0 --cflags --libs)

Gtk::Window *pWindow;
Gtk::Entry *num1, *num2, *result;
Gtk::Button *btn_soma, *btn_subtracao, *btn_mult, *btn_div;
Gtk::Label *label_title;

bool eh_numero(std::string str){
    std::regex re ("^[0-9]+$");
    std::smatch match;
    return std::regex_search(str, match, re);
}

void on_btn_soma_clicked(){
    std::string a = num1->get_text();
    std::string b = num2->get_text();

    if(eh_numero(a) && eh_numero(b)){
        int x = std::stoi(a);
        int y = std::stoi(b);

        result->set_text(std::to_string(x + y));
        label_title->set_text("SOMA EFETUADA!");
    }else{
        label_title->set_text("INSIRA SOMENTO NUMEROS!");
    }
}

void on_btn_subtracao_clicked(){
    std::string a = num1->get_text();
    std::string b = num2->get_text();

    if(eh_numero(a) && eh_numero(b)){
        int x = std::stoi(a);
        int y = std::stoi(b);

        result->set_text(std::to_string(x - y));
        label_title->set_text("SUBTRAÇÃO EFETUADA!");
    }else{
        label_title->set_text("INSIRA SOMENTO NUMEROS!");
    }
}

void on_btn_mult_clicked(){
    std::string a = num1->get_text();
    std::string b = num2->get_text();

    if(eh_numero(a) && eh_numero(b)){
        int x = std::stoi(a);
        int y = std::stoi(b);

        result->set_text(std::to_string(x * y));
        label_title->set_text("MULTIPLICAÇÃO EFETUADA!");
    }else{
        label_title->set_text("INSIRA APENAS NÚMEROS");
    }
}

void on_btn_div_clicked(){
    std::string a = num1->get_text();
    std::string b = num2->get_text();

    if(eh_numero(a) && eh_numero(b)){
        int x = std::stoi(a);
        int y = std::stoi(b);

        result->set_text(std::to_string(x / y));
        label_title->set_text("DIVISÃO EFETUADA!");
    }else{
        label_title->set_text("INSIRA APENAS NÚMEROS");
    }
}

int main(int argc, char** argv){
    Gtk::Main create(argc, argv, "org.gtkmm.example");  
    auto refBuilder = Gtk::Builder::create();
    refBuilder->add_from_file("soma.glade");
    refBuilder->get_widget("window", pWindow);

    if(pWindow){
        refBuilder->get_widget("num1", num1);
        refBuilder->get_widget("num2", num2);
        refBuilder->get_widget("btn_soma", btn_soma);
        refBuilder->get_widget("result", result);
        refBuilder->get_widget("label_title", label_title);
        refBuilder->get_widget("btn_subtracao", btn_subtracao);
        refBuilder->get_widget("btn_mult", btn_mult);
        refBuilder->get_widget("btn_div", btn_div);
    }

    if(btn_soma){
        btn_soma->signal_clicked().connect(sigc::ptr_fun(on_btn_soma_clicked));
    }

    if(btn_subtracao){
        btn_subtracao->signal_clicked().connect(sigc::ptr_fun(on_btn_subtracao_clicked));
    }

    if(btn_mult){
        btn_mult->signal_clicked().connect(sigc::ptr_fun(on_btn_mult_clicked));
    }
    
    if(btn_div){
        btn_div->signal_clicked().connect(sigc::ptr_fun(on_btn_div_clicked));
    }
    
    Gtk::Main::run(*pWindow);

    delete(pWindow);
    return 0;
}