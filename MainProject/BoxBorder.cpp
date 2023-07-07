#include "BoxBorder.h"

wchar_t box::Border::horizontal(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
	case BorderStyle::DOUBLE_OUTER_SINGLE_INNER:
		return L'─';
	case BorderStyle::DOUBLE:
		return L'═';
	default:
		return L'\0';
	}
}
wchar_t box::Border::vertical(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
		return L'│';
	case BorderStyle::DOUBLE:
		return L'║';
	default:
		return L'\0';
	}
}

wchar_t box::Border::top_left(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
		return L'┌';
	case BorderStyle::DOUBLE:
		return L'╔';
	default:
		return L'\0';
	}
}
wchar_t box::Border::top(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
		return L'┬';
	case BorderStyle::DOUBLE:
		return L'╦';
	default:
		return L'\0';
	}
}
wchar_t box::Border::top_right(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
		return L'┐';
	case BorderStyle::DOUBLE:
		return L'╗';
	default:
		return L'\0';
	}
}

wchar_t box::Border::left(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
		return L'├';
	case BorderStyle::DOUBLE:
		return L'╠';
	default:
		return L'\0';
	}
}
wchar_t box::Border::center(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
		return L'┼';
	case BorderStyle::DOUBLE:
		return L'╬';
	default:
		return L'\0';
	}
}
wchar_t box::Border::right(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
		return L'┤';
	case BorderStyle::DOUBLE:
		return L'╣';
	default:
		return L'\0';
	}
}

wchar_t box::Border::bottom_left(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
		return L'└';
	case BorderStyle::DOUBLE:
		return L'╚';
	default:
		return L'\0';
	}
}
wchar_t box::Border::bottom(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
		return L'┴';
	case BorderStyle::DOUBLE:
		return L'╩';
	default:
		return L'\0';
	}
}
wchar_t box::Border::bottom_right(BorderStyle _style) {
	switch (_style) {
	case BorderStyle::SINGLE:
		return L'┘';
	case BorderStyle::DOUBLE:
		return L'╝';
	default:
		return L'\0';
	}
}
