#include<iostream>
#include<math.h>
#include<GL/glut.h>
#include<time.h>
#include<vector>
using namespace std ;
int edge ;
vector<int> xpoint;
vector<int> ypoint;
int ch;
void init()
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,640,0,480);
glClear(GL_COLOR_BUFFER_BIT);
}
void scale()
{
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
for(int i=0 ; i<edge ; i++)
{
glVertex2i(xpoint[i]-320,ypoint[i]-240);
}
glEnd();
glFlush();
int sx , sy;
cout<<"\n\tEnter Scaling factors Sx and Sy :";
cin>>sx>>sy;
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
for(int i=0 ; i<edge ; i++)
{
glVertex2i((xpoint[i]-320)*sx,(ypoint[i]-240)*sy);
}
glEnd();
glFlush();
}
void rotate()
{
int cx,cy;
cout<<"\n\tEnter any Arbitrary Points :";
cin>>cx>>cy;
cx=cx+320;
cy=cy+240;
double the;
cout<<"\n\tEnter Angle Of Rotation :";
cin>>the;
the=the*3.14/180;
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
for(int i=0 ; i<edge ; i++)
{
glVertex2i( floor(((xpoint[i]-cx)*cos(the)-
(ypoint[i]-cy)*sin(the))+cx) ,
floor(((xpoint[i]-cx)*sin(the)+
(ypoint[i]-cy)*cos(the))+cy));
}
glEnd();
glFlush();
}
void reflect()
{
char reflection;
cout<<"\n\tEnter Reflection Axis :";
cin>>reflection;
if(reflection=='x' || reflection=='X')
{
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
for(int i =0 ; i<edge ; i++ )
{
glVertex2i(xpoint[i],(ypoint[i]*-1)+480);
}
glEnd();
}
else if(reflection=='y' || reflection=='Y')
{
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
for(int i =0 ; i<edge ; i++ )
{
glVertex2i((xpoint[i]*-1)+640,ypoint[i]);
}
glEnd();
}
glFlush();
}
void Draw()
{
if(ch==2 || ch==3)
{
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINES);
glVertex2i(0,240);
glVertex2i(640,240);
glEnd();
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINES);
glVertex2i(320,480);
glVertex2i(320,0);
glEnd();
glFlush();
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
for(int i=0 ; i<edge ; i++ )
{
glVertex2i(xpoint[i],ypoint[i]);
}
glEnd();
glFlush();
}
if(ch==1)
{
scale();
}
else if(ch==2)
{
rotate();
}
else if(ch==3)
{
reflect();
}
}
int main(int argc , char** argv)
{
cout<<"\n\t|| MENU ||"
<<"\n\t1>Scale"
<<"\n\t2>Rotate"
<<"\n\t3>Reflection"
<<"\n\tEnter Your Choice : ";
cin>>ch;
if(ch==1 || ch==2 || ch==3)
{
int xpointnew ,ypointnew;
cout<<"\n\tEnter no of Edges of Polygon : ";
cin>>edge;
for(int i=0 ; i<edge ; i++ )
{
cout<<"Enter "<<i<<" point : ";
cin>>xpointnew>>ypointnew;
xpoint.push_back(xpointnew+320);
ypoint.push_back(ypointnew+240);
}
glutInit(&argc , argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(200,200);
glutCreateWindow("Transformation");
init();
glutDisplayFunc(Draw);
glutMainLoop();
return 0;
}
else
{
cout<<"\nInvalid Input!! ";
return 0;
}
}
