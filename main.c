#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>
#include "InsertionSort.h"
#include "RecursiveBubbleSort.h"
#include "SelectionSort.h"
#include "Bubble_Sort.h"

int SORT_NO= 4;	    // Number of sorting algorithms
int SPEED= 700;	    // Speed of sorting, must be greater than MAX always
int MAX=50;         // Array Size
int a[50];			// Array
int k=0;			// To Switch from Welcome screen to Main Screen
int sorting=0;
char *sort_string[]={"Bubble Sort","Selection Sort","Insertion Sort","Recursive Bubble Sort"};
int sort_count=0;	// To cycle through the string

void bitmap_output(int x, int y, char *string, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

// Function to integer to string
void int_str(int rad,char r[])
{
	sprintf(r, "%d", rad);
}

void display_text()
{

	glColor3f(1,1,1);
	bitmap_output(150, 665, "Learning Different Sorting Algorithms Through Visualization",GLUT_BITMAP_HELVETICA_18);
	glBegin(GL_LINE_LOOP);
		glVertex2f(145, 660);
		glVertex2f(495, 660);
	glEnd();

	// other text small font
	bitmap_output(10, 625, "This program sorts a random set of numbers in ascending order displaying them graphically as ",GLUT_BITMAP_9_BY_15);
	bitmap_output(10, 605, "bars with varying height",GLUT_BITMAP_9_BY_15);


	if (sorting == 0)	// if not sorting display menu
	{
		bitmap_output(10, 575, "MENU",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 555, "Press s to SORT",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 535, "Press c to SELECT the sort algorithm",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 515, "Press r to RANDOMISE",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 495, "Esc to QUIT",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 475, "Selected sort: ",GLUT_BITMAP_9_BY_15);
		bitmap_output(150, 475, *(sort_string+sort_count),GLUT_BITMAP_9_BY_15);
	}
	else if (sorting == 1)	// while sorting
	{
		glColor3f(0.0,1.0,0.0);
		bitmap_output(10, 535, "Press p to PAUSE",GLUT_BITMAP_9_BY_15);
		glColor3f(0.0,0.0,0.0);
		glColor3f(1.0,0.0,0.0);
		if (sort_count==0){
            bitmap_output(10, 555, "Visualizing Bubble Sort",GLUT_BITMAP_9_BY_15);
            bitmap_output(10, 515, "Best Case Time complexity is: O(n)",GLUT_BITMAP_9_BY_15);
            bitmap_output(10, 495, "Worst Case and Avg Case Time complexity is: O(n^2)",GLUT_BITMAP_9_BY_15);
		}
		else if (sort_count==1){
		    bitmap_output(10, 555, "Visualizing Selection Sort",GLUT_BITMAP_9_BY_15);
            bitmap_output(10, 515, "Best Case, Avg Case and Worst Case Time complexity is: O(n^2)",GLUT_BITMAP_9_BY_15);
		}
		else if (sort_count==2){
		    bitmap_output(10, 555, "Visualizing Insertion Sort",GLUT_BITMAP_9_BY_15);
            bitmap_output(10, 515, "Best Case Time complexity is: O(n)",GLUT_BITMAP_9_BY_15);
            bitmap_output(10, 495, "Worst Case and Avg Case Time complexity is: O(n^2)",GLUT_BITMAP_9_BY_15);
		}
		else if (sort_count==3){
		    bitmap_output(10, 555, "Visualizing Recursive Bubble Sorting",GLUT_BITMAP_9_BY_15);
            bitmap_output(10, 515, "Best Case Time complexity is: O(n)",GLUT_BITMAP_9_BY_15);
            bitmap_output(10, 495, "Worst Case and Avg Case Time complexity is: O(n^2)",GLUT_BITMAP_9_BY_15);
		}
		glColor3f(0.0,0.0,0.0);
	}
}

void front()
{
	glColor3f(1.0,1.0,1.0);
	bitmap_output(150, 450, "Learning Different Sorting Algorithms",GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(150, 400, "Through Visualization",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0,1.0,1.0);
	bitmap_output(550, 125, "Press Enter to Continue",GLUT_BITMAP_HELVETICA_18);
}

void Initialize() {
	int temp1;

	// Reset the array
	for(temp1=0;temp1<MAX;temp1++){
		a[temp1]=rand()%100+1;
		printf("%d ",a[temp1]);
	}

	glClearColor(0.1,0.1,0.1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 700, 0, 800);
}

// Main function for display
void display()
{
	int ix,temp;
	glClear(GL_COLOR_BUFFER_BIT);

	if(k==0)
		front();
	else{
		display_text();
		char text[10];

		for(ix=0;ix<MAX;ix++)
		{
			glBegin(GL_POLYGON);
                glColor3f(0,0.42,0.7);
				glVertex2f(10+(700/(MAX+1))*ix,50);
				glVertex2f(10+(700/(MAX+1))*(ix+1),50);
				glColor3f(0.66,0.2,0.50);
				glVertex2f(10+(700/(MAX+1))*(ix+1),50+a[ix]*4);
				glVertex2f(10+(700/(MAX+1))*ix,50+a[ix]*4);
			glEnd();

			int_str(a[ix],text);
			glColor3f(1,1,1);
			bitmap_output(12+(700/(MAX+1))*ix, 35, text,GLUT_BITMAP_HELVETICA_10);
		}
	}
	glFlush();
}

void bubblesort(int a, int MAX){}
void insertionsort(int a, int MAX){}
void selectionsort(int a, int MAX){}
void recursivebubblesort(int a, int MAX){}

// Timer Function, takes care of sort selection
void makedelay(int)
{
	if(sorting)
	{
		switch(sort_count)
		{
			case 0:	bubblesort(a, 50);
					break;
			case 1:	selectionsort(a, 50);
                    break;
			case 2: insertionsort(a, 50);
                    break;
			case 3: recursivebubblesort(a, 50);
					break;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(SPEED/MAX,makedelay,1);
}

// Keyboard Function
void keyboard (unsigned char key, int x, int y)
{
	if(key==13)
		k=1;
	if (k==1 && sorting!=1)
	{
		switch (key)
		{
			case 27	 :	exit (0); // 27 is the ASCII code for the ESC key
			case 's' :	sorting = 1;
                        break;
			case 'r' :	Initialize();
                        break;
			case 'c' :	sort_count=(sort_count+1)%SORT_NO;
                        break;
		}
	}
	if(k==1 && sorting==1)
		if(key=='p')
            sorting=0;
}



// Main Function
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1024,768);
	glutInitWindowPosition(0,0);
	glutCreateWindow("MINOR PROJECT");
	Initialize();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(100,makedelay,1);
	glutMainLoop();
}
