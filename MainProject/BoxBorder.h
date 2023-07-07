#ifndef BOXBORDER_H
#define BOXBORDER_H
#pragma once

namespace box {
	enum class BorderStyle {
		SINGLE,
		DOUBLE,
		DOUBLE_OUTER_SINGLE_INNER
	};

	struct Border {
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
	};
} // namespace box
#endif
