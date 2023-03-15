#ifndef BOXBORDER_H
#define BOXBORDER_H
#pragma once

enum class BorderStyle {
	Single,
	Double
};

template<BorderStyle _borderStyle>
struct BoxBorder {
	static wchar_t Horizontal(); 
	static wchar_t Vertical();
	struct Top {
		static wchar_t Left();
		static wchar_t Right();
	};
	struct Bottom {
		static wchar_t Left();
		static wchar_t Right();
	};
	static wchar_t Left();
	static wchar_t Right();
	static wchar_t Top();
	static wchar_t Bottom();
	static wchar_t Middle();
	// ─│┌┐└┘├┤┬┴┼
	// ═║╔╗╚╝╠╣╦╩╬
	// ⩴⫬═≕≔≖
};

#endif

template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Horizontal() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'─';
	case BorderStyle::Double:
		return L'═';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Vertical() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'│';
	case BorderStyle::Double:
		return L'║';
	default:
		return L'\0';
	}
}

template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Top::Left() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'┌';
	case BorderStyle::Double:
		return L'╔';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Top::Right() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'┐';
	case BorderStyle::Double:
		return L'╗';
	default:
		return L'\0';
	}
}

template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Bottom::Left() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'└';
	case BorderStyle::Double:
		return L'╚';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Bottom::Right() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'┘';
	case BorderStyle::Double:
		return L'╝';
	default:
		return L'\0';
	}
}

template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Left() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'├';
	case BorderStyle::Double:
		return L'╠';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Right() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'┤';
	case BorderStyle::Double:
		return L'╣';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Top() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'┬';
	case BorderStyle::Double:
		return L'╦';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Bottom() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'┴';
	case BorderStyle::Double:
		return L'╩';
	default:
		return L'\0';
	}
}
template<BorderStyle _borderStyle> inline wchar_t BoxBorder<_borderStyle>::Middle() {
	switch (_borderStyle) {
	case BorderStyle::Single:
		return L'┼';
	case BorderStyle::Double:
		return L'╬';
	default:
		return L'\0';
	}
}
