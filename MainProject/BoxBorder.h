#ifndef BOXBORDER_H
#define BOXBORDER_H
#pragma once

enum class BorderStyle {
	SINGLE,
	DOUBLE,
	DOUBLE_OUTER_SINGLE_INNER
};

template<BorderStyle _borderStyle>
struct BoxBorder {
	static wchar_t horizontal(); 
	static wchar_t vertical();
	struct top {
		static wchar_t left();
		static wchar_t right();
	};
	struct bottom {
		static wchar_t left();
		static wchar_t right();
	};
	static wchar_t left();
	static wchar_t right();
	static wchar_t top();
	static wchar_t bottom();
	static wchar_t middle();
	// ─│┌┐└┘├┤┬┴┼
	// ═║╔╗╚╝╠╣╦╩╬
	//   ╒╕╘╛╞╡╤╧╪
	//   ╓╖╙╜╟╢╥╨╫
	// ⩴⫬═≕≔≖
};

#endif

template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::horizontal() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
	case BorderStyle::DOUBLE_OUTER_SINGLE_INNER:
		return L'─';
	case BorderStyle::DOUBLE:
		return L'═';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::vertical() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
		return L'│';
	case BorderStyle::DOUBLE:
		return L'║';
	default:
		return L'\0';
	}
}

template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::top::left() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
		return L'┌';
	case BorderStyle::DOUBLE:
		return L'╔';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::top::right() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
		return L'┐';
	case BorderStyle::DOUBLE:
		return L'╗';
	default:
		return L'\0';
	}
}

template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::bottom::left() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
		return L'└';
	case BorderStyle::DOUBLE:
		return L'╚';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::bottom::right() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
		return L'┘';
	case BorderStyle::DOUBLE:
		return L'╝';
	default:
		return L'\0';
	}
}

template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::left() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
		return L'├';
	case BorderStyle::DOUBLE:
		return L'╠';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::right() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
		return L'┤';
	case BorderStyle::DOUBLE:
		return L'╣';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::top() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
		return L'┬';
	case BorderStyle::DOUBLE:
		return L'╦';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::bottom() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
		return L'┴';
	case BorderStyle::DOUBLE:
		return L'╩';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::middle() {
	switch (_borderStyle) {
	case BorderStyle::SINGLE:
		return L'┼';
	case BorderStyle::DOUBLE:
		return L'╬';
	default:
		return L'\0';
	}
}
