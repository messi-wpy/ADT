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
#include"tokenscanner.h"
#include"random.h"
#include"gbufferedimage.h"
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
int n=0;

int floodFill(GBufferedImage& image, int x, int y, int newColor) {

       if(image.getRGB(x,y)!=newColor){

           int color = image.getRGB(x,y);
           image.setRGB(x,y,newColor);
           n++;

           if(image.getRGB(x+1,y)==color)
               floodFill(image,x+1,y,newColor);
           if(image.getRGB(x-1,y)==color)
               floodFill(image,x-1,y,newColor);
           if(image.getRGB(x,y+1)==color)
               floodFill(image,x,y+1,newColor);
           if(image.getRGB(x,y-1)==color)
               floodFill(image,x,y-1,newColor);
       }

       return n;
}
Map<string,string>exist;
void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
   if(prereqMap.containsKey(goal)){
       for(int i=0;i<prereqMap.get(goal).size();i++){

           personalCurriculum(prereqMap,prereqMap.get(goal).get(i));
            if(!exist.containsKey(prereqMap.get(goal).get(i)))
           cout<<prereqMap.get(goal).get(i)<<endl;
           exist.put(prereqMap.get(goal).get(i),"exist");
       }
       if(!exist.containsKey(goal))
           cout<<goal<<endl;//所有调用完后输出第一个
       exist.put(goal,"exist");
   }
  //  cout << "[recursion personal curriculum called]" << endl;
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {
    Vector<string>vec;
    string str;
    string result;
    if(grammar.containsKey(symbol)){
        vec=grammar.get(symbol);
        int random=randomReal(0,vec.size()-1);
         str=vec.get(random);
         TokenScanner token(str);
         while (token.hasMoreTokens()) {
             string t=token.nextToken();
            result+=generate(grammar,t);
         }
    }
         else {
             result=symbol;
         }
    return result;
}
