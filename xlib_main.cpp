#include <X11/Xlib.h>
#include <unistd.h>

main()
{
  Display *d = XOpenDisplay(0);
  XEvent e;

  if ( d )
    {
      Window w = XCreateWindow(d, DefaultRootWindow(d), 0, 0, 640,
			       480, 0, CopyFromParent, CopyFromParent,
			       CopyFromParent, 0, 0);
      XSelectInput(d, w, ExposureMask | KeyPressMask);
      XMapWindow(d, w);
      while(1)
      {
	XNextEvent(d, &e);
	if (e.type == KeyPress)
		break;
      }
    }
  XCloseDisplay(d);
  return 0;
}
