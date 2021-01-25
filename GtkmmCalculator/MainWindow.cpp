#include "MainWindow.h"
#include "gtkmm/builder.h"


int lastNum = 0;
int currentNum = 0;
char lastOperation;

MainWindow::MainWindow()
{
    this->grid.attach(this->label, 0,0,1,1);
    this->label.set_text(std::to_string(currentNum));

    this->grid.attach(this->addition_button, 4, 1, 1, 1);
    this->addition_button.set_label("+");
    this->addition_button.signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::btn_click), 12));

    this->grid.attach(this->subtract_button, 4, 2, 1, 1);
    this->subtract_button.set_label("-");
    this->subtract_button.signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::btn_click), 13));

    this->grid.attach(this->multiply_button, 4, 3, 1, 1);
    this->multiply_button.set_label("x");
    this->multiply_button.signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::btn_click), 14));

    this->grid.attach(this->divide_button, 4, 4, 1, 1);
    this->divide_button.set_label("/");
    this->divide_button.signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::btn_click), 15));

    this->grid.attach(this->equals_button, 1, 4, 1, 1);
    this->equals_button.set_label("=");
    this->equals_button.signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::btn_click), 11));

    this->grid.attach(this->clear_button, 2, 4, 1, 1);
    this->clear_button.set_label("C");
    this->clear_button.signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::btn_click), 10));

    for (int i = 0; i < 10; i++) {
        this->grid.attach(this->m_buttons[i], i%3, i/3+1, 1,1);
        this->m_buttons[i].set_label(std::to_string(i));
        this->m_buttons[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::btn_click), i));
    }
    this->add(grid);
    
    this->grid.show_all();
}

void MainWindow::btn_click(int i) {
    std::cout << i << std::endl;

    if (i < 10) {
        std::string currentN = std::to_string(currentNum);
        currentNum = std::stoi(currentN + std::to_string(i));
        this->label.set_text(std::to_string(currentNum));
        
    }
    else if (i == 10) {
        currentNum = 0;
        lastNum = 0;
        this->label.set_text(std::to_string(currentNum));
    }
    else if (i == 11) {

    }
    else if (i == 12) {
        lastOperation = '+';
    }
    else if (i == 13) {
        lastOperation = '-';
    }
    else if (i == 14) {
        lastOperation = '*';
    }
    else if (i == 15) {
        lastOperation = '/';
    }
    
}
void calc() {

}