#include "main_form.hpp"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    MainForm::show();

    // console::resize(1275, 750);
    // console::move_to::center();

    // console::resize(1920, 1080);// 377
    // console::move_to::center();

    /*
    form_info(
        "Enter your information",
        {"     Full name:",
         "       Address:",
         "  Phone number:",
         " Email address:"},
        box::BorderStyle::CORNER_DOUBLE
    );
    */

    // show_info_accounts();

    /*
    char key_press;
    int ascii_value;
    std::cout << "\n\t\tNhap phim bat ky de kiem tra ma ASCII\n\t\t\An ESC de "
                 "thoat\n\n\n";
    while (1) {
        key_press = _getch();
        ascii_value = key_press;
        // For ESC
        if (ascii_value == 27) {
            break;
        }
        std::cout << "Ban nhap phim-> \" " << key_press
                  << " \" Gia tri ASCII =  " << ascii_value << "\n";
    }
    */
    return EXIT_SUCCESS;
}
