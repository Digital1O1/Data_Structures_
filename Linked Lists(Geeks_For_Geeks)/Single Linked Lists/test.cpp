#include <iostream>

using namespace std;

int main()
{
    // char text[] = "1";
    // int text = 1;
    // printf("%d\r\n", text);
    // text++;
    // printf("%d\r\n", text);

    // cout << text - 48;
    int count = 0;
    char text[] = "1";
    cout << text << endl;
    text[0] += (++count);
    // text[0] = text[0] + (++count);
    cout << text << endl;

    //text[0] = text[0] + (count++);
    cout << text << endl;
    return 0;
}