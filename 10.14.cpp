auto f = [](int a, int b) {return a + b; };

void foo()
{
    int i = 1;
    auto f = [i](int j) {return i + j; };
}