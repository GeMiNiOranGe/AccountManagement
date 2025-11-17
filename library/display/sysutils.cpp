#include "display/sysutils.hpp"

int screen::get_taskbar_height() {
    RECT rect;
    HWND taskbar = FindWindow(L"Shell_traywnd", NULL);
    GetWindowRect(taskbar, &rect);
    int height = rect.bottom - rect.top;
    return height;
}

SIZE screen::get_work_area_size() {
    RECT rect_work_area;
    SystemParametersInfo(SPI_GETWORKAREA, 0, &rect_work_area, 0);
    LONG cx = rect_work_area.right - rect_work_area.left;
    LONG cy = rect_work_area.bottom - rect_work_area.top;
    return {cx, cy};
}

const SIZE window::WORK_AREA_SIZE = screen::get_work_area_size();

#pragma region Top of the screen
void window::move_to_top_left(bool visual) {
    if (visual) {
        window::visual::move_to_top_left();
    } else {
        window::standard::move_to_top_left();
    }
}

void window::move_to_top(bool visual) {
    if (visual) {
        window::visual::move_to_top();
    } else {
        window::standard::move_to_top();
    }
}

void window::move_to_top_right(bool visual) {
    if (visual) {
        window::visual::move_to_top_right();
    } else {
        window::standard::move_to_top_right();
    }
}
#pragma endregion

#pragma region Middle of the screen
void window::move_to_left(bool visual) {
    if (visual) {
        window::visual::move_to_left();
    } else {
        window::standard::move_to_left();
    }
}

void window::move_to_center(bool visual) {
    if (visual) {
        window::visual::move_to_center();
    } else {
        window::standard::move_to_center();
    }
}

void window::move_to_right(bool visual) {
    if (visual) {
        window::visual::move_to_right();
    } else {
        window::standard::move_to_right();
    }
}
#pragma endregion

#pragma region Bottom of the screen
void window::move_to_bottom_left(bool visual) {
    if (visual) {
        window::visual::move_to_bottom_left();
    } else {
        window::standard::move_to_bottom_left();
    }
}

void window::move_to_bottom(bool visual) {
    if (visual) {
        window::visual::move_to_bottom();
    } else {
        window::standard::move_to_bottom();
    }
}

void window::move_to_bottom_right(bool visual) {
    if (visual) {
        window::visual::move_to_bottom_right();
    } else {
        window::standard::move_to_bottom_right();
    }
}

void window::move_to_xy(LONG x_coord, LONG y_coord, bool visual) {
    if (visual) {
        window::visual::move_to_xy(x_coord, y_coord);
    } else {
        window::standard::move_to_xy(x_coord, y_coord);
    }
}
#pragma endregion

#pragma region Top of the screen
void window::standard::move_to_top_left() {
    int pos_x = 0;
    int pos_y = 0;
    move_to_xy(pos_x, pos_y);
}

void window::standard::move_to_top() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx / 2 - (bounds.right - bounds.left) / 2;
    int pos_y = 0;
    move_to_xy(pos_x, pos_y);
}

void window::standard::move_to_top_right() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx - (bounds.right - bounds.left);
    int pos_y = 0;
    move_to_xy(pos_x, pos_y);
}
#pragma endregion

#pragma region Middle of the screen
void window::standard::move_to_left() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = 0;
    int pos_y = WORK_AREA_SIZE.cy / 2 - (bounds.bottom - bounds.top) / 2;
    move_to_xy(pos_x, pos_y);
}

void window::standard::move_to_center() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx / 2 - (bounds.right - bounds.left) / 2;
    int pos_y = WORK_AREA_SIZE.cy / 2 - (bounds.bottom - bounds.top) / 2;
    move_to_xy(pos_x, pos_y);
}

void window::standard::move_to_right() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx - (bounds.right - bounds.left);
    int pos_y = WORK_AREA_SIZE.cy / 2 - (bounds.bottom - bounds.top) / 2;
    move_to_xy(pos_x, pos_y);
}
#pragma endregion

#pragma region Bottom of the screen
void window::standard::move_to_bottom_left() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = 0;
    int pos_y = WORK_AREA_SIZE.cy - (bounds.bottom - bounds.top);
    move_to_xy(pos_x, pos_y);
}

void window::standard::move_to_bottom() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx / 2 - (bounds.right - bounds.left) / 2;
    int pos_y = WORK_AREA_SIZE.cy - (bounds.bottom - bounds.top);
    move_to_xy(pos_x, pos_y);
}

void window::standard::move_to_bottom_right() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx - (bounds.right - bounds.left);
    int pos_y = WORK_AREA_SIZE.cy - (bounds.bottom - bounds.top);
    move_to_xy(pos_x, pos_y);
}
#pragma endregion

void window::standard::move_to_xy(LONG x_coord, LONG y_coord) {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int width = bounds.right - bounds.left;
    int height = bounds.bottom - bounds.top;
    MoveWindow(hwnd, x_coord, y_coord, width, height, TRUE);
}

void window::resize(LONG width, LONG height) {
    RECT client, bounds;
    POINT offset;
    HWND hwnd = GetConsoleWindow();
    GetClientRect(hwnd, &client);
    GetWindowRect(hwnd, &bounds);
    // find the offset to add to the screen (e.g: x = 33, y = 39)
    offset.x = (bounds.right - bounds.left) - client.right;
    offset.y = (bounds.bottom - bounds.top) - client.bottom;
    LONG final_width = width + offset.x;
    LONG final_height = height + offset.y;
    MoveWindow(hwnd, bounds.left, bounds.top, final_width, final_height, TRUE);
}

#pragma region Top of the screen
void window::visual::move_to_top_left() {
    int pos_x = 0;
    int pos_y = 0;
    move_to_xy(pos_x, pos_y);
}

void window::visual::move_to_top() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx / 2 - (bounds.right - bounds.left) / 2;
    int pos_y = 0;
    move_to_xy(pos_x, pos_y);
}

void window::visual::move_to_top_right() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx - (bounds.right - bounds.left);
    int pos_y = 0;
    move_to_xy(pos_x, pos_y);
}
#pragma endregion

#pragma region Middle of the screen
void window::visual::move_to_left() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = 0;
    int pos_y = WORK_AREA_SIZE.cy / 2 - (bounds.bottom - bounds.top) / 2;
    move_to_xy(pos_x, pos_y);
}

void window::visual::move_to_center() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx / 2 - (bounds.right - bounds.left) / 2;
    int pos_y = WORK_AREA_SIZE.cy / 2 - (bounds.bottom - bounds.top) / 2;
    move_to_xy(pos_x, pos_y);
}

void window::visual::move_to_right() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx - (bounds.right - bounds.left);
    int pos_y = WORK_AREA_SIZE.cy / 2 - (bounds.bottom - bounds.top) / 2;
    move_to_xy(pos_x, pos_y);
}
#pragma endregion

#pragma region Bottom of the screen
void window::visual::move_to_bottom_left() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = 0;
    int pos_y = WORK_AREA_SIZE.cy - (bounds.bottom - bounds.top);
    move_to_xy(pos_x, pos_y);
}

void window::visual::move_to_bottom() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx / 2 - (bounds.right - bounds.left) / 2;
    int pos_y = WORK_AREA_SIZE.cy - (bounds.bottom - bounds.top);
    move_to_xy(pos_x, pos_y);
}

void window::visual::move_to_bottom_right() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int pos_x = WORK_AREA_SIZE.cx - (bounds.right - bounds.left);
    int pos_y = WORK_AREA_SIZE.cy - (bounds.bottom - bounds.top);
    move_to_xy(pos_x, pos_y);
}
#pragma endregion

void window::visual::move_to_xy(LONG x_coord, LONG y_coord) {
    HWND hwnd = GetConsoleWindow();

    RECT bounds, extended;
    GetWindowRect(hwnd, &bounds);
    DwmGetWindowAttribute(
        hwnd, DWMWA_EXTENDED_FRAME_BOUNDS, &extended, sizeof(extended)
    );

    LONG delta_x = extended.left - bounds.left;
    LONG delta_y = extended.top - bounds.top;

    LONG width = bounds.right - bounds.left;
    LONG height = bounds.bottom - bounds.top;

    LONG x = x_coord - delta_x;
    LONG y = y_coord - delta_y;

    MoveWindow(hwnd, x, y, width, height, TRUE);
}
