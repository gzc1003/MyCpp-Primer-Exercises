#include <string>
#include <iostream>
#include <vector>

class Screen;

class WindowMgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
	// if an incomplete type is used as a template argument when 
	// instantiating a template component, undefined behavior

    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};


class Screen {
    friend void WindowMgr::clear(ScreenIndex);

public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos h, pos w) :
        height(h), width(w), contents(h*w, ' ') {}
    Screen(pos h, pos w, char c) :
        height(h), width(w), contents(h*w, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const;

    Screen &move(pos r, pos c);

    Screen &set(char c)
    {
        contents[cursor] = c; return *this;
    }
    Screen &set(pos r, pos col, char ch)
    {
        contents[r*width + col] = ch; return *this;
    }

    Screen &display(std::ostream &os)
    {
        do_display(os); return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os); return *this;
    }

private:
    pos height = 0, width = 0;
    pos cursor = 0;
    std::string contents;

    void do_display(std::ostream &os) const { os << contents; }

};

inline char Screen::get(pos r, pos c) const
{
    return contents[r*width + c];
}

inline Screen &Screen::move(pos r, pos c)
{ 
    cursor = r * width + c;
    return *this;
}


inline
void WindowMgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}
