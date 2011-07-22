#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>


void die(char *why)
{
  fprintf(stderr, "%s\n", why);
  exit(1);
}

int main()
{
  Display *dpy; 
  XWMHints *hints;
  Window window;
  char * windowid;


  if ( !(windowid = getenv("WINDOWID")) )
    die("No $WINDOWID found");
  window = atoi(windowid);

  if ( !(dpy = XOpenDisplay(NULL)) )
    die("Could not open display");

  if ( !(hints = XGetWMHints(dpy, window)) )
    die("Could not get hints");

  hints->flags |= XUrgencyHint;

  XSetWMHints(dpy, window, hints);

  XFlush(dpy);
  XCloseDisplay(dpy);

  return 0;
}
