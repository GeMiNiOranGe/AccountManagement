﻿#pragma once
#ifndef BOXBORDER_HPP
#define BOXBORDER_HPP

namespace box {
	enum class BorderStyle {
		SINGLE,
		DOUBLE,
		CORNER_SINGLE,
		CORNER_DOUBLE,
		VERTICAL_DOUBLE,
		HORIZONTAL_DOUBLE,
		DOUBLE_OUTER_SINGLE_INNER
	};

	class Border {
	public:
		static wchar_t horizontal(BorderStyle _style);
		static wchar_t vertical(BorderStyle _style);

		static wchar_t top_left(BorderStyle _style);
		static wchar_t top(BorderStyle _style);
		static wchar_t top_right(BorderStyle _style);

		static wchar_t left(BorderStyle _style);
		static wchar_t center(BorderStyle _style);
		static wchar_t right(BorderStyle _style);

		static wchar_t bottom_left(BorderStyle _style);
		static wchar_t bottom(BorderStyle _style);
		static wchar_t bottom_right(BorderStyle _style);
		// ─│┌┐└┘├┤┬┴┼
		// ═║╔╗╚╝╠╣╦╩╬
		//   ╒╕╘╛╞╡╤╧╪
		//   ╓╖╙╜╟╢╥╨╫
		// ⩴⫬═≕≔≖
		//ͰΤ⫟⫞⊦⊢⊤⌜⌌⌍⌏⌎◜◞⌊⌈|⨽⨼⫠⫥⫭⫪⫬Τ—−––--−−——⌈‖Τ
	};
} // namespace box

#endif // end BOXBORDER_HPP