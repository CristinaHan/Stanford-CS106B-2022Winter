#include "Plotter.h"
#include <string>
#include "strlib.h"
#include <vector.h>
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    double x0 = 0, y0 = 0;
    bool updown = false;
    PenStyle style = { 1, "black" };

    for (string line; getline(input, line); ) {
        toLowerCaseInPlace(line);
        Vector<string> commands = stringSplit(line, " ");

        if (commands[0] == "pendown") {
            updown = true;
        }
        else if (commands[0] == "penup") {
            updown = false;
        }
        else if (commands[0] == "moveabs") {
            if (updown) {
                drawLine(x0, y0, stringToReal(commands[1]), stringToReal(commands[2]), style);
            }
            x0 = stringToReal(commands[1]);
            y0 = stringToReal(commands[2]);
        }
        else if (commands[0] == "moverel") {
            if (updown) {
                drawLine(x0, y0, x0 + stringToReal(commands[1]), y0 + stringToReal(commands[2]), style);
            }
            x0 += stringToReal(commands[1]);
            y0 += stringToReal(commands[2]);
        }
        else if (commands[0] == "pencolor") {
            style.color = commands[1];
        }
        else if (commands[0] == "penwidth") {
            style.width = stringToReal(commands[1]);
        }
    }
}
