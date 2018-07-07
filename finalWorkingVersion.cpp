#include <iostream>
#include <string>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

class point
{
    float x;
    float y;
    public:
    void setX(float inputx)
    {
        x=inputx;
    }
    float getX()
    {
        return x;
    }
     void setY(float inputy)
    {
        y=inputy;
    }
    float getY()
    {
        return y;
    }
};

void printPoint (float xpoint,float ypoint)
{
    cout << "(" << xpoint << "," << ypoint << ")";
}
float slope(point p1, point p2)
{
    return ((p2.getY()-p1.getY())/(p2.getX()-p1.getX()));
}

void minXop(int polygonCount, int pointcountarray[100],float polygons[100][100][2])
{
	float minX=polygons[0][0][0];
	for (int i=0;i<polygonCount;i++)
        {
	        for (int j=0;j<pointcountarray[i];j++)
                {
                    if((polygons[i][j][0])<minX)
                        minX=polygons[i][j][0];
                }
         }
    cout << minX <<endl;
}

void maxXop(int polygonCount, int pointcountarray[100], float polygons[100][100][2])
{
	float maxX=polygons[0][0][0];
	for (int i=0;i<polygonCount;i++)
            {
                for (int j=0;j<pointcountarray[i];j++)
                {
                    if((polygons[i][j][0])> maxX)
                        maxX=polygons[i][j][0];
                }
            }
    cout << maxX <<endl;
}

void minYop(int polygonCount, int pointcountarray[100], float polygons[100][100][2])
{
	float minY=polygons[0][0][1];
	for (int i=0;i<polygonCount;i++)
            {
                for (int j=0;j<pointcountarray[i];j++)
                {
                    if((polygons[i][j][1])<minY)
                        minY=polygons[i][j][1];
                }
            }
    cout << minY <<endl;
}

void maxYop(int polygonCount, int pointcountarray[100], float polygons[100][100][2])
{
	float maxY=polygons[0][0][1];
	for (int i=0;i<polygonCount;i++)
            {
                for (int j=0;j<pointcountarray[i];j++)
                {
                    if((polygons[i][j][1])> maxY)
                        maxY=polygons[i][j][1];
                }
            }
    cout << maxY <<endl;
}
float minXop1(int polno, int pointcountarray[100],float polygons[100][100][2])
{
	float minX=polygons[polno][0][0];
    for (int j=0;j<pointcountarray[polno];j++)
    {
        if((polygons[polno][j][0])<minX)
            minX=polygons[polno][j][0];
    }
    return minX;
}
float minYop1 (int polno, int pointcountarray[100],float polygons[100][100][2])
{
	float minY=polygons[polno][0][1];
    for (int j=0;j<pointcountarray[polno];j++)
    {
        if((polygons[polno][j][1])<minY)
            minY=polygons[polno][j][1];
    }
    return minY;
}
float maxXop1(int polno, int pointcountarray[100],float polygons[100][100][2])
{
	float maxX=polygons[polno][0][0];
    for (int j=0;j<pointcountarray[polno];j++)
    {
        if((polygons[polno][j][0])>maxX)
            maxX=polygons[polno][j][0];
    }
    return maxX;
}
float maxYop1 (int polno, int pointcountarray[100],float polygons[100][100][2])
{
	float maxY=polygons[polno][0][1];
    for (int j=0;j<pointcountarray[polno];j++)
    {
        if((polygons[polno][j][1])>maxY)
            maxY=polygons[polno][j][1];
    }
    return maxY;
}

void encR (int polygonCount, int pointcountarray[100], float polygons[100][100][2])
{
    float minX, maxX, minY, maxY;
	minX=polygons[0][0][0];
	maxX=polygons[0][0][0];
	minY=polygons[0][0][1];
	minY=polygons[0][0][1];
	for (int i=0;i<polygonCount;i++)
        {
             for (int j=0;j<pointcountarray[i];j++)
             {
                 if((polygons[i][j][0])<minX)
                     minX=polygons[i][j][0];
                 if((polygons[i][j][0])> maxX)
                     maxX=polygons[i][j][0];
                 if((polygons[i][j][1])<minY)
                     minY=polygons[i][j][1];
                 if((polygons[i][j][1])> maxY)
                     maxY=polygons[i][j][1];
              }
         }
         printPoint(minX,minY);
         printPoint(minX,maxY);
         printPoint(maxX,maxY);
         printPoint(maxX,minY);
         cout << endl;
}

void red(int polygonCount, int pointcountarray[100], float polygons[100][100][2])
{
    int redundantCount=0, check=0;
    point p1,p2,p3;
	if(check==0)
            {
                for (int polcount=0;polcount<polygonCount;polcount++)
                {
                    for (int i=0;i<pointcountarray[polcount];i++)     // for the first polygon for ex. for all points in that polygon ba2a we take 2 points make a line between them and check if any point lies on line
                    {
                       if (i==(pointcountarray[polcount]-1))
                       {
                           p1.setX(polygons[polcount][i][0]);
                           p1.setY(polygons[polcount][i][1]);
                           p2.setX(polygons[polcount][0][0]);
                           p2.setY(polygons[polcount][0][1]);
                           p3.setX(polygons[polcount][1][0]);
                           p3.setY(polygons[polcount][1][1]);
                           if (p1.getX()==p2.getX())
                           {
                                if (p1.getY()==p2.getY())
                                    redundantCount++;
                                /*else if (p1.getX()-p3.getX()==0)
                                    redundantCount++;*/
                                else continue;
                           }
                           else if ((slope(p1,p2))==(slope(p2,p3)))
                            redundantCount++;
                       }
                       else
                       {
                           p1.setX(polygons[polcount][i][0]);
                           p1.setY(polygons[polcount][i][1]);
                           p2.setX(polygons[polcount][i+1][0]);
                           p2.setY(polygons[polcount][i+1][1]);
                           p3.setX(polygons[polcount][i+2][0]);
                           p3.setY(polygons[polcount][i+2][1]);
                           if (p1.getX()==p2.getX())
                           {
                                if (p1.getY()==p2.getY())
                                    redundantCount++;
                                /*else if (p1.getX()==p3.getX())
                                    redundantCount++;*/
                                else continue;
                           }
                           else if ((slope(p1,p2))==(slope(p2,p3)))
                            redundantCount++;
                       }
                    }
                }
            }
            if (redundantCount==0)
            {
                cout << "none" << endl;
            }
            else
            {
                cout << redundantCount <<endl;
                check=1;
            }
}

int red1 (int polno, int pointcountarray[100], float polygons[100][100][2])
{
    int redundantCount=0;
    point p1,p2,p3;
    for (int i=0;i<pointcountarray[polno];i++)
    {
        if (i==(pointcountarray[polno]-1))
        {
            p1.setX(polygons[polno][i][0]);
            p1.setY(polygons[polno][i][1]);
            p2.setX(polygons[polno][0][0]);
            p2.setY(polygons[polno][0][1]);
            p3.setX(polygons[polno][1][0]);
            p3.setY(polygons[polno][1][1]);
            if (p1.getX()==p2.getX())
            {
                if (p1.getY()==p2.getY())
                    redundantCount++;
                /*else if (p1.getX()==p3.getX())
                    redundantCount++;*/
                else
                    continue;
            }
            else if ((slope(p1,p2))==(slope(p2,p3)))
                redundantCount++;
        }
        else
        {
            p1.setX(polygons[polno][i][0]);
            p1.setY(polygons[polno][i][1]);
            p2.setX(polygons[polno][i+1][0]);
            p2.setY(polygons[polno][i+1][1]);
            p3.setX(polygons[polno][i+2][0]);
            p3.setY(polygons[polno][i+2][1]);
            if (p1.getX()==p2.getX())
            {
                if (p1.getY()==p2.getY())
                    redundantCount++;
                /*else if (p1.getX()==p3.getX())
                    redundantCount++;*/
                else
                    continue;
            }
            else if ((slope(p1,p2))==(slope(p2,p3)))
                redundantCount++;
        }
    }
    return redundantCount;
}


float distancep (point p1, point p2)
{
    float dx= p2.getX()-p1.getX();
    float dy=p2.getY()-p1.getY();
    return sqrt(pow(dx,2)+pow(dy,2));
}

float peri(int polno, int pointcountarray[100], float polygons[100][100][2])
{

    point p1,p2;
    float distance,sum=0;
    for (int i=0;i<pointcountarray[polno];i++)
    {
        if (i==pointcountarray[polno]-1)
        {
            p1.setX(polygons[polno][i][0]);
            p1.setY(polygons[polno][i][1]);
            p2.setX(polygons[polno][0][0]);
            p2.setY(polygons[polno][0][1]);
            distance=distancep(p1,p2);
            sum=sum+distance;

        }
        else
        {
            p1.setX(polygons[polno][i][0]);
            p1.setY(polygons[polno][i][1]);
            p2.setX(polygons[polno][i+1][0]);
            p2.setY(polygons[polno][i+1][1]);
            distance=distancep(p1,p2);
            sum=sum+distance;
        }
    }
    return sum;
}

int main()
{
    int c,polygonCount,pointCount,sumPoints=0;
    string first,operation;
    float x,y;
    float polygons[100][100][2];
    int pointcountarray[100];

    cout <<"Enter the data:"<<endl;

    for (int i=0;i<100;i++)             //initialization of arrays
    {
        for (int j=0;j<100;j++)
        {
            polygons[i][j][0]=0;
            polygons[i][j][1]=0;
        }
    }

    // parsing the input and storing it in a 2D array made up of a 100 polygons with a 100 points each

    getline(cin,first,'=');
    if(first=="Polygons")
    {
        if ((c=cin.get())=='[')
        {
            for(polygonCount=0;polygonCount<100;polygonCount++)
            {
                for(pointCount=0 ; pointCount<100 ; pointCount++)
                {
                    if ((c=cin.get())=='(')
                    {
                        cin >> x;
                        if((c=cin.get()==','))
                        cin >> y;
                    }

                    if ((c=cin.get())==')')
                    {
                        polygons[polygonCount][pointCount][0]=x;
                        polygons[polygonCount][pointCount][1]=y;
                    }
                    if ((c=cin.get())!=',')
                    {
                        pointcountarray[polygonCount]=pointCount+1;
                        sumPoints=sumPoints+pointCount+1;
                        break;
                    }
                }
                if (c==']')
                {
                    polygonCount++;
                    break;
                }
            }
        }
    }

    //nored list
    float nored [100][100][2];
    int pointcountarrayw [100];
    int pointCountw;
    for (int i=0;i<polygonCount;i++)
    {
        point p1,p2,p3;
        pointCountw=0;
        for (int j=0; j<pointcountarray[i];j++)
        {
            if (j==(pointcountarray[i]-1))
           {
               p1.setX(polygons[i][j][0]);
               p1.setY(polygons[i][j][1]);
               p2.setX(polygons[i][0][0]);
               p2.setY(polygons[i][0][1]);
               p3.setX(polygons[i][1][0]);
               p3.setY(polygons[i][1][1]);
               if (p1.getX()==p2.getX())
               {
                    if (p1.getY()==p2.getY())
                        continue;
                    /*else if (p1.getX()==p3.getX())
                        continue;*/

               }
               else if ((slope(p1,p2))==(slope(p2,p3)))
                    continue;
            }
           else
           {
               p1.setX(polygons[i][j][0]);
               p1.setY(polygons[i][j][1]);
               p2.setX(polygons[i][j+1][0]);
               p2.setY(polygons[i][j+1][1]);
               p3.setX(polygons[i][j+2][0]);
               p3.setY(polygons[i][j+2][1]);
               if (p1.getX()==p2.getX())
               {
                    if (p1.getY()==p2.getY())
                        continue;
                    /*else if (p1.getX()==p3.getX())
                        continue;*/

               }
               else if ((slope(p1,p2))==(slope(p2,p3)))
                continue;
           }
            nored[i][pointCountw][0]=polygons[i][j][0];
            nored[i][pointCountw][1]=polygons[i][j][1];
            pointCountw++;
        }
        pointcountarrayw[i]=pointCountw;
    }

    //start of operations

    while (1)
    {
		cout << "Enter operation: " << endl;
		cin >> operation;
		if (operation=="Number_Polygons")
            cout << polygonCount <<endl;
        else if (operation=="Total_Number_Points")
                cout << sumPoints <<endl;

        else if (operation=="Minimum_X")
        {
           minXop(polygonCount,pointcountarray,polygons);
        }
        else if (operation=="Maximum_X")
        {
            maxXop(polygonCount,pointcountarray,polygons);
        }

        else if (operation=="Minimum_Y")
        {
            minYop(polygonCount,pointcountarray,polygons);
        }
        else if (operation=="Maximum_Y")
        {
            maxYop(polygonCount,pointcountarray,polygons);
        }
        else if (operation=="Enclosing_Rectangle")
        {
            encR(polygonCount,pointcountarray,polygons);
        }
        else if(operation=="Total_Redundant_Points")
        {
            red(polygonCount, pointcountarray, polygons);
        }
        else if (operation=="Quit")
				break;
        else if (operation=="Polygon_Points")
        {
            int polno;
            cin>> polno;
            int counter=0,checkcounter=0;
            for(int i=0; i< pointcountarrayw[polno-1]; i++)
            {
                counter++;
            }
            for(int i=0;i<pointcountarrayw[polno-1];i++)
            {
                checkcounter ++;
                printPoint(polygons[polno-1][i][0],polygons[polno-1][i][1]);
                if (checkcounter<counter)
                {
                    cout << ",";
                }
            }
            if (counter==0)
            {
                cout << "None";
            }
            cout << endl;
        }
        else if (operation=="Point_Polygons")
        {
            char in;
            float xin, yin;
            int counter=0,checkcounter=0;
            if ((in=cin.get())==' ')
            {
                if ((in=cin.get())=='(')
                {
                    cin >> xin;
                    if ((in=cin.get())==',')
                        cin >> yin;
                    in=cin.get();
                }
                for (int i=0; i<polygonCount; i++)
                {
                    for(int j=0;j<pointcountarray[i];j++)
                    {
                        if(xin==polygons[i][j][0]&&yin==polygons[i][j][1])
                        {
                            counter++;
                            break;
                        }
                    }
                }
                for (int i=0; i<polygonCount; i++)
                {
                    for(int j=0;j<pointcountarray[i];j++)
                    {
                        if(xin==polygons[i][j][0]&&yin==polygons[i][j][1])
                        {
                            checkcounter++;
                            cout << i+1;
                            if (checkcounter<counter)
                            {
                                cout << ",";
                            }
                        }
                    }
                }
                if (counter==0)
                    cout << "None";
            }
            cout << endl;

        }
        else if (operation=="List_Polygons_Points")
        {
            string in;
            cin >> in;
            if (in=="More")
            {
                int inp;
                cin >> inp;
                int counter=0,checkcounter=0;
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if((pointcountarray[polno]-red1(polno, pointcountarray, polygons))>inp)
                        {
                            counter++;
                        }

                }
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if((pointcountarray[polno]-red1(polno, pointcountarray, polygons))>inp)
                        {
                            cout<< polno+1;
                            checkcounter++;
                            if (checkcounter<counter)
                                cout << ",";
                        }

                }
                if (counter==0)
                    cout << "None" << endl;
                else cout << endl;
            }
            else if (in=="Less")
            {
                int inp;
                cin >> inp;
                int counter=0,checkcounter=0;
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if((pointcountarray[polno]-red1(polno, pointcountarray, polygons))<inp)
                        {
                            counter++;
                        }

                }
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if((pointcountarray[polno]-red1(polno, pointcountarray, polygons))<inp)
                        {
                            cout<< polno+1;
                            checkcounter++;
                            if (checkcounter<counter)
                                cout << ",";
                        }

                }
                if (counter==0)
                    cout << "None" << endl;
                else cout << endl;
            }
            else if (in=="Equal")
            {
                int inp;
                cin >> inp;
                int counter=0,checkcounter=0;
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if((pointcountarray[polno]-red1(polno, pointcountarray, polygons))==inp)
                        {
                            counter++;
                        }

                }
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if((pointcountarray[polno]-red1(polno, pointcountarray, polygons))==inp)
                        {
                            cout<< polno+1;
                            checkcounter++;
                            if (checkcounter<counter)
                                cout << ",";
                        }

                }
                if (counter==0)
                    cout << "None" << endl;
                else cout << endl;
            }
        }
        else if (operation=="List_Points_Polygons")
        {
            string inp;
            cin >> inp;
            bool check=false;
            if (inp=="Equal")
            {
                int in;
                cin >> in;
                int counter=0,checkcounter=0;
                for (int i=0; i<polygonCount;i++)
                {
                    for (int j=0; j<pointcountarray[i];j++)
                    {
                        int inCounter=0;
                        for (int k=0; k<polygonCount;k++)
                        {
                            for(int m=0; m<pointcountarray[k];m++)
                            {
                                if ((polygons[i][j][0]==polygons[k][m][0])&&(polygons[i][j][1]==polygons[k][m][1]))
                                {
                                    inCounter++;
                                    break;
                                }
                            }
                        }
                        if (inCounter==in)
                        {
                            check=true;
                            counter++;
                        }
                    }
                    for (int j=0; j<pointcountarray[i];j++)
                    {
                        int inCounter=0;
                        for (int k=0; k<polygonCount;k++)
                        {
                            for(int m=0; m<pointcountarray[k];m++)
                            {
                                if ((polygons[i][j][0]==polygons[k][m][0])&&(polygons[i][j][1]==polygons[k][m][1]))
                                {
                                    inCounter++;
                                    break;
                                }
                            }
                        }
                        if (inCounter==in)
                        {
                            printPoint(polygons[i][j][0],polygons[i][j][1]);
                            checkcounter++;
                            if (checkcounter<counter)
                            {
                                cout << ",";
                            }
                        }
                    }
                }
                if (check==false)
                    cout <<"None";

            }
            if (inp=="More")
            {
                int in;
                cin >> in;
                int counter=0,checkcounter=0;
                for (int i=0; i<polygonCount;i++)
                {
                    for (int j=0; j<pointcountarray[i];j++)
                    {
                        int inCounter=0;
                        for (int k=0; k<polygonCount;k++)
                        {
                            for(int m=0; m<pointcountarray[k];m++)
                            {
                                if ((polygons[i][j][0]==polygons[k][m][0])&&(polygons[i][j][1]==polygons[k][m][1]))
                                {
                                    inCounter++;
                                    break;
                                }
                            }
                        }
                        if (inCounter>in)
                        {
                            check=true;
                            counter++;
                        }
                    }
                    for (int j=0; j<pointcountarray[i];j++)
                    {
                        int inCounter=0;
                        for (int k=0; k<polygonCount;k++)
                        {
                            for(int m=0; m<pointcountarray[k];m++)
                            {
                                if ((polygons[i][j][0]==polygons[k][m][0])&&(polygons[i][j][1]==polygons[k][m][1]))
                                {
                                    inCounter++;
                                    break;
                                }
                            }
                        }
                        if (inCounter>in)
                        {
                            printPoint(polygons[i][j][0],polygons[i][j][1]);
                            checkcounter++;
                            if (checkcounter<counter)
                            {
                                cout << ",";
                            }
                        }
                    }
                }
                if (check==false)
                    cout <<"None";

            }
            else if (inp=="Less")
            {
                int in;
                cin >> in;
                int counter=0,checkcounter=0;
                for (int i=0; i<polygonCount;i++)
                {
                    for (int j=0; j<pointcountarray[i];j++)
                    {
                        int inCounter=0;
                        for (int k=0; k<polygonCount;k++)
                        {
                            for(int m=0; m<pointcountarray[k];m++)
                            {
                                if ((polygons[i][j][0]==polygons[k][m][0])&&(polygons[i][j][1]==polygons[k][m][1]))
                                {
                                    inCounter++;
                                    break;
                                }
                            }
                        }
                        if (inCounter<in)
                        {
                            check=true;
                            counter++;
                        }
                    }
                    for (int j=0; j<pointcountarray[i];j++)
                    {
                        int inCounter=0;
                        for (int k=0; k<polygonCount;k++)
                        {
                            for(int m=0; m<pointcountarray[k];m++)
                            {
                                if ((polygons[i][j][0]==polygons[k][m][0])&&(polygons[i][j][1]==polygons[k][m][1]))
                                {
                                    inCounter++;
                                    break;
                                }
                            }
                        }
                        if (inCounter<in)
                        {
                            printPoint(polygons[i][j][0],polygons[i][j][1]);
                            checkcounter++;
                            if (checkcounter<counter)
                            {
                                cout << ",";
                            }
                        }
                    }
                }
                if (check==false)
                    cout <<"None";

            }
            cout << endl;
        }
        else if (operation=="Polygon_Perimeter")
        {
            int polno;
            cin >> polno;
            cout << peri((polno-1),pointcountarray,polygons) << endl;

        }
        else if (operation=="List_Triangles")
        {
                int counter=0,checkcounter=0;
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if((pointcountarray[polno]-red1(polno, pointcountarray, polygons))==3)
                        {
                            counter++;
                        }

                }
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if((pointcountarray[polno]-red1(polno, pointcountarray, polygons))==3)
                        {
                            cout<< polno+1;
                            checkcounter++;
                            if (checkcounter<counter)
                                cout << ",";
                        }

                }
                if (counter==0)
                    cout << "None" << endl;
                else cout << endl;
        }
        else if (operation=="List_Rectangles")
        {
                int counter=0,checkcounter=0;
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if(pointcountarrayw[polno]==4)
                        {
                            point p1,p2,p3,p4;
                            p1.setX(nored[polno][0][0]);
                            p1.setY(nored[polno][0][1]);
                            p2.setX(nored[polno][1][0]);
                            p2.setY(nored[polno][1][1]);
                            p3.setX(nored[polno][2][0]);
                            p3.setY(nored[polno][2][1]);
                            p4.setX(nored[polno][3][0]);
                            p4.setY(nored[polno][3][1]);
                            double no= (pow(distancep(p2,p4),2)-pow(distancep(p1,p2),2)-pow(distancep(p1,p4),2))/(-2*distancep(p1,p2)*distancep(p1,p4));
                            double angle= acos(no);
                            if ((slope(p1,p2)==slope(p4,p3))&&(slope(p2,p3)==slope(p1,p4))&&(((asin(1.0)-0.01)<angle)&&(angle<(asin(1.0)+0.01))))
                            {
                                counter++;
                            }
                        }

                }
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if(pointcountarrayw[polno]==4)
                        {
                            point p1,p2,p3,p4;
                            p1.setX(nored[polno][0][0]);
                            p1.setY(nored[polno][0][1]);
                            p2.setX(nored[polno][1][0]);
                            p2.setY(nored[polno][1][1]);
                            p3.setX(nored[polno][2][0]);
                            p3.setY(nored[polno][2][1]);
                            p4.setX(nored[polno][3][0]);
                            p4.setY(nored[polno][3][1]);
                            double no= (pow(distancep(p2,p4),2)-pow(distancep(p1,p2),2)-pow(distancep(p1,p4),2))/(-2*distancep(p1,p2)*distancep(p1,p4));
                            double angle= acos(no);
                            if ((slope(p1,p2)==slope(p4,p3))&&(slope(p2,p3)==slope(p1,p4))&&(((asin(1.0)-0.01)<angle)&&(angle<(asin(1.0)+0.01))))
                            {
                                cout<< polno+1;
                                checkcounter++;
                                if (checkcounter<counter)
                                    cout << ",";
                            }
                        }
                }
                if (counter==0)
                    cout << "None" << endl;
                else cout << endl;
        }
        else if (operation=="List_Trapezoid")
        {
                int counter=0,checkcounter=0;
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if(pointcountarrayw[polno]==4)
                        {
                            point p1,p2,p3,p4;
                            p1.setX(nored[polno][0][0]);
                            p1.setY(nored[polno][0][1]);
                            p2.setX(nored[polno][1][0]);
                            p2.setY(nored[polno][1][1]);
                            p3.setX(nored[polno][2][0]);
                            p3.setY(nored[polno][2][1]);
                            p4.setX(nored[polno][3][0]);
                            p4.setY(nored[polno][3][1]);
                            if ((slope(p1,p2)==slope(p4,p3))||(slope(p2,p3)==slope(p1,p4)))
                            {
                                counter++;
                            }
                        }

                }
                for (int polno=0;polno<polygonCount;polno++)
                {
                        if(pointcountarrayw[polno]==4)
                        {
                            point p1,p2,p3,p4;
                            p1.setX(nored[polno][0][0]);
                            p1.setY(nored[polno][0][1]);
                            p2.setX(nored[polno][1][0]);
                            p2.setY(nored[polno][1][1]);
                            p3.setX(nored[polno][2][0]);
                            p3.setY(nored[polno][2][1]);
                            p4.setX(nored[polno][3][0]);
                            p4.setY(nored[polno][3][1]);
                            if ((slope(p1,p2)==slope(p4,p3))||(slope(p2,p3)==slope(p1,p4)))
                            {
                                cout<< polno+1;
                                checkcounter++;
                                if (checkcounter<counter)
                                    cout << ",";
                            }
                        }
                }
                if (counter==0)
                    cout << "None" << endl;
                else cout << endl;
        }
        else if (operation=="Inside_Rectangle")
        {
            char in;
            float rect[4][2];
            int counter=0,checkcounter=0;
            if ((in=cin.get())==' ')
            {
                for (int i=0;i<4;i++)
                {
                    if ((in=cin.get())=='(')
                    {
                        cin >> rect[i][0];
                        if ((in=cin.get())==',')
                        {
                            cin >> rect[i][1];
                            if ((in=cin.get())==')')
                            {
                                if((in=cin.get())==',')
                                    continue;
                            }
                        }

                    }
                }
            }
            float maxX=rect[0][0],minX=rect[0][0],maxY=rect[0][1],minY=rect[0][1];
            for (int i=1;i<4;i++)
            {
                if (rect[i][0]<minX)
                {
                   minX=rect[i][0];
                }
                if (rect[i][0]>maxX)
                {
                    maxX=rect[i][0];
                }
                if (rect[i][1]<minY)
                {
                   minY=rect[i][1];
                }
                if (rect[i][1]>maxY)
                {
                    maxY=rect[i][1];
                }
            }
            for (int polno=0;polno<polygonCount;polno++)
            {
                float min0=(minXop1(polno,pointcountarray,polygons)), max0=(maxXop1(polno,pointcountarray,polygons));
                float min1=(minYop1(polno,pointcountarray,polygons)), max1=(maxYop1(polno,pointcountarray,polygons));
                if (((min0)>(minX))&&((max0)<(maxX))&&((min1)>(minY))&&((max1)<(maxY)))
                {
                    counter++;
                }
            }
            for (int polno=0;polno<polygonCount;polno++)
            {
                float min0=(minXop1(polno,pointcountarray,polygons)), max0=(maxXop1(polno,pointcountarray,polygons));
                float min1=(minYop1(polno,pointcountarray,polygons)), max1=(maxYop1(polno,pointcountarray,polygons));
                if (((min0)>(minX))&&((max0)<(maxX))&&((min1)>(minY))&&((max1)<(maxY)))
                {
                    checkcounter++;
                    cout << polno+1;
                    if(checkcounter<counter)
                        cout << ",";
                }
            }
            if (counter==0)
                cout << "None";
            cout << endl;
        }
        else if (operation=="Inside_Circle")
        {
            char in;
            int rad;
            float xin, yin;
            int counter=0,checkcounter=0;
            if ((in=cin.get())==' ')
            {
                if ((in=cin.get())=='(')
                {
                    cin >> xin;
                    if ((in=cin.get())==',')
                        cin >> yin;
                    if ((in=cin.get())==')')
                    {
                        if ((in=cin.get())==',')
                        {
                            cin >> rad;
                        }
                    }
                }
            }
            for (int polno=0;polno<polygonCount;polno++)
            {
                float min0=(minXop1(polno,pointcountarray,polygons)), max0=(maxXop1(polno,pointcountarray,polygons));
                float min1=(minYop1(polno,pointcountarray,polygons)), max1=(maxYop1(polno,pointcountarray,polygons));
                point center;
                center.setX(xin);
                center.setY(yin);
                point b1,b2,b3,b4;
                b1.setX(min0); b1.setY(min1); b2.setX(min0); b2.setY(max1); b3.setX(max0); b3.setY(max1); b4.setX(max0); b4.setY(min1);
                if(((distancep(b1,center))<=rad)&&((distancep(b2,center))<=rad)&&((distancep(b3,center))<=rad)&&((distancep(b4,center))<=rad))
                {
                    counter++;
                }
            }
            for (int polno=0;polno<polygonCount;polno++)
            {
                float min0=(minXop1(polno,pointcountarray,polygons)), max0=(maxXop1(polno,pointcountarray,polygons));
                float min1=(minYop1(polno,pointcountarray,polygons)), max1=(maxYop1(polno,pointcountarray,polygons));
                point center;
                center.setX(xin);
                center.setY(yin);
                point b1,b2,b3,b4;
                b1.setX(min0); b1.setY(min1); b2.setX(min0); b2.setY(max1); b3.setX(max0); b3.setY(max1); b4.setX(max0); b4.setY(min1);
                if(((distancep(b1,center))<=rad)&&((distancep(b2,center))<=rad)&&((distancep(b3,center))<=rad)&&((distancep(b4,center))<=rad))
                {
                    checkcounter++;
                    cout << polno+1;
                    if (checkcounter<counter)
                        cout << ",";
                }
            }

            if (counter==0)
                cout << "None";
            cout << endl;
        }
        else
            cout << "Invalid Operation" << endl;
    }


    return 0;
}
