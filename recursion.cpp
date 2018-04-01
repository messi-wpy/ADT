/* 
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.
 */

#include <math.h>
#include "recursion.h"
#include "map.h"
#include "vector.h"
#include "set.h"
#include "gwindow.h"
#include "gobjects.h"
#include "tokenscanner.h"
#include"stdio.h"
#include"gmath.h"
using namespace std;

int gcd(int a, int b) {
    if(b==0){
            cout << "gcd(" << a << "," << b << ") = " << a << endl;
            return a;
        }
        else {
        cout << "gcd(" <<  a << "," << b << ") = ";
        cout << "gcd(" << b << "," << a%b << ") " << endl;
          return  gcd(b,a%b);

        }

}

void serpinskii(GWindow &w, int leftX, int leftY, int size, int order)
{
    if(order>0){
        double bottomX=leftX+size/2;
        double bottomY=leftY+size*sinDegrees(60);
       GPoint a(leftX,leftY);
       GPoint b(leftX+size,leftY);
       GPoint c(bottomX,bottomY);
       w.drawLine(a,b);
       w.drawLine(a,c);
       w.drawLine(b,c);
       serpinskii(w,leftX,leftY,size/2,order-1);
        serpinskii(w,leftX+size/2,leftY,size/2,order-1);
        serpinskii(w,leftX+size/4,leftY+(size*sinDegrees(60)/2),size/2,order-1);


    }

    cout << "[recursion serpinskii called]" << endl;
}

int floodFill(GBufferedImage& image, int x, int y, int newColor) {
    // your code here
    cout << "[recursion flood fill called]" << endl;
    return 0;
}

void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    // your code here
    cout << "[recursion personal curriculum called]" << endl;
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {
    // your code here
    cout << "[recursion generate called]" << endl;
    return "";
}
