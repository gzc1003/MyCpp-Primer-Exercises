#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    char ch, pre_ch='\0';
    unsigned acnt = 0, ecnt = 0, icnt = 0, ocnt = 0, ucnt = 0;
    unsigned space_cnt = 0, tab_cnt = 0, newline_cnt = 0;
    unsigned ff_cnt = 0, fl_cnt = 0, fi_cnt = 0;
    //use cin.get() or noskipws to not skip whitespace
    cin >> std::noskipws;
    while (cin >> ch) {
        switch (ch) {
        case 'a': case 'A':
            ++acnt;
            break;
        case 'e': case 'E':
            ++ecnt;
            break;
        case 'i':
            if (pre_ch == 'f')
                ++fi_cnt;
        case 'I':
            ++icnt;
            break;
        case 'o': case 'O':
            ++ocnt;
            break;
        case 'u': case 'U':
            ++ucnt;
            break;
        case ' ':
            ++space_cnt;
            break;
        case '\t':
            ++tab_cnt;
            break;
        case '\n':
            ++newline_cnt;
            break;
        case 'f':
            if (pre_ch == 'f')
                ++ff_cnt;
            break;
        case 'l':
            if (pre_ch == 'f')
                ++fl_cnt;
            break;
        }
        pre_ch = ch;
    }
    cin >> std::skipws;
    cout << "acnt\t" << acnt << endl;
    cout << "ecnt\t" << ecnt << endl;
    cout << "icnt\t" << icnt << endl;
    cout << "ocnt\t" << ocnt << endl;
    cout << "ucnt\t" << ucnt << endl;
    cout << "space_cnt\t" << space_cnt << endl;
    cout << "tab_cnt\t" << tab_cnt << endl;
    cout << "newline_cnt \t" << newline_cnt << endl;
    cout << "ff_cnt\t" << ff_cnt << endl;
    cout << "fi_cnt\t" << fi_cnt << endl;
    cout << "fl_cnt\t" << fl_cnt << endl;
    return 0;
}