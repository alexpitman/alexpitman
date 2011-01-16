///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : Base class 
// Desctription   : View rendering
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/View.h"

#include <gl.h>

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

vwr::View::View()
{
}

vwr::View::~View()
{
}

void
vwr::View::Build()
{
  isBuildPending = false;
}

void
vwr::View::SetBuildPending()
{
  isBuildPending = true;
}

void 
vwr::View::Render()
{
  if ( isBuildPending ) Build();
  isRenderPending = false;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  glTranslatef(0, 0, 8);
  glRotatef(210, 1, 0, 0);
  glRotatef(210, 0, 0, 1);
  
  glBegin(GL_TRIANGLES);
  
  glColor3f(0, 1, 0);
  glVertex3f(-1, -1, -1); // Front
  glVertex3f( 1,  1, -1);
  glVertex3f(-1,  1, -1);
  
  glVertex3f(-1, -1, -1);
  glVertex3f( 1, -1, -1);
  glVertex3f( 1,  1, -1);
  
  glColor3f(1, 0, 0);
  glVertex3f(-1, -1,  1); // Back
  glVertex3f(-1,  1,  1);
  glVertex3f( 1,  1,  1);
  
  glVertex3f(-1, -1,  1);
  glVertex3f( 1,  1,  1);
  glVertex3f( 1, -1,  1);
  
  glColor3f(1, 1, 0);
  glVertex3f(-1, -1,  1);
  glVertex3f( 1, -1,  1);
  glVertex3f(-1, -1, -1);
  
  glVertex3f( 1, -1,  1);
  glVertex3f( 1, -1, -1);
  glVertex3f(-1, -1, -1);
  
  glColor3f(0, 1, 1);
  glVertex3f(-1,  1,  1);
  glVertex3f(-1, -1,  1);
  glVertex3f(-1, -1, -1);
  
  glVertex3f(-1,  1, -1);
  glVertex3f(-1,  1,  1);
  glVertex3f(-1, -1, -1);
  
  glColor3f(1, 0, 1);
  glVertex3f( 1,  1, -1);
  glVertex3f( 1, -1, -1);
  glVertex3f( 1,  1,  1);
  
  glVertex3f( 1, -1, -1);
  glVertex3f( 1, -1,  1);
  glVertex3f( 1,  1,  1);
  
  glColor3f(1, 1, 1);
  glVertex3f( 1,  1, -1);
  glVertex3f( 1,  1,  1);
  glVertex3f(-1,  1, -1);
  
  glVertex3f( 1,  1,  1);
  glVertex3f(-1,  1,  1);
  glVertex3f(-1,  1, -1);
  
  glEnd();
}

void
vwr::View::SetRenderPending()
{
  isRenderPending = true;
}

void
vwr::View::GLInitialise()
{
  glClearColor(0, 0, 0, 1);
  
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glShadeModel(GL_SMOOTH);
  //glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);
  glEnable(GL_MULTISAMPLE);
}

void
vwr::View::Resize(int Width, int Height)
{
  glViewport(0, 0, Width, Height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(-10, +10, -10, +10, -4.0, -15.0);

  glMatrixMode(GL_MODELVIEW);
}