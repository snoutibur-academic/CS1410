#ifndef COLORS_H
#define COLORS_H

#include <string>
using std::string;

//Foreground colors
const string fg_gray = "\033[30m";
const string fg_red = "\033[31m";
const string fg_green = "\033[32m";
const string fg_orange = "\033[33m";
const string fg_blue = "\033[34m";
const string fg_purple = "\033[35m";
const string fg_cyan = "\033[36m";
const string fg_white = "\033[37m";
const string fg_light_gray = "\033[02m";


//Font styles
const string style_italic = "\033[03m";
const string style_bold = "\033[01m";
const string style_underline = "\033[04m";
const string style_normal = "\033[00m";

//Background colors
const string bk_white = "\033[07m";
const string bk_gray = "\033[40m";
const string bk_red = "\033[41m";
const string bk_green = "\033[42m";
const string bk_orange = "\033[43m";
const string bk_blue = "\033[44m";
const string bk_purple = "\033[45m";
const string bk_cyan = "\033[46m";
const string bk_gray_light = "\033[47m";
const string bk_normal = "\033[49m";

//Clear the screen
const string scr_clear = "\033[2J\033[1;1H";

#endif //COLORS_H
