#include "BoxBorder.h"

wchar_t box::Border::horizontal(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_DOUBLE:
	case BorderStyle::VERTICAL_DOUBLE:
		return L'─';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_SINGLE:
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'═';
	default:
		return L'\0';
	}
}
wchar_t box::Border::vertical(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_DOUBLE:
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'│';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_SINGLE:
	case BorderStyle::VERTICAL_DOUBLE:
		return L'║';
	default:
		return L'\0';
	}
}

wchar_t box::Border::top_left(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_SINGLE:
		return L'┌';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_DOUBLE:
		return L'╔';
	case BorderStyle::VERTICAL_DOUBLE:
		return L'╓';
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'╒';
	default:
		return L'\0';
	}
}
wchar_t box::Border::top(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_SINGLE:
		return L'┬';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_DOUBLE:
		return L'╦';
	case BorderStyle::VERTICAL_DOUBLE:
		return L'╥';
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'╤';
	default:
		return L'\0';
	}
}
wchar_t box::Border::top_right(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_SINGLE:
		return L'┐';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_DOUBLE:
		return L'╗';
	case BorderStyle::VERTICAL_DOUBLE:
		return L'╖';
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'╕';
	default:
		return L'\0';
	}
}

wchar_t box::Border::left(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_SINGLE:
		return L'├';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_DOUBLE:
		return L'╠';
	case BorderStyle::VERTICAL_DOUBLE:
		return L'╟';
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'╞';
	default:
		return L'\0';
	}
}
wchar_t box::Border::center(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_SINGLE:
		return L'┼';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_DOUBLE:
		return L'╬';
	case BorderStyle::VERTICAL_DOUBLE:
		return L'╫';
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'╪';
	default:
		return L'\0';
	}
}
wchar_t box::Border::right(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_SINGLE:
		return L'┤';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_DOUBLE:
		return L'╣';
	case BorderStyle::VERTICAL_DOUBLE:
		return L'╢';
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'╡';
	default:
		return L'\0';
	}
}

wchar_t box::Border::bottom_left(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_SINGLE:
		return L'└';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_DOUBLE:
		return L'╚';
	case BorderStyle::VERTICAL_DOUBLE:
		return L'╙';
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'╘';
	default:
		return L'\0';
	}
}
wchar_t box::Border::bottom(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_SINGLE:
		return L'┴';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_DOUBLE:
		return L'╩';
	case BorderStyle::VERTICAL_DOUBLE:
		return L'╨';
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'╧';
	default:
		return L'\0';
	}
}
wchar_t box::Border::bottom_right(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::CORNER_SINGLE:
		return L'┘';
	case BorderStyle::DOUBLE:
	case BorderStyle::CORNER_DOUBLE:
		return L'╝';
	case BorderStyle::VERTICAL_DOUBLE:
		return L'╜';
	case BorderStyle::HORIZONTAL_DOUBLE:
		return L'╛';
	default:
		return L'\0';
	}
}
